#include <Windows.h>
#include <process.h>
#include <sstream>
template<class T>HANDLE new_thread(const T& fn)
{
	const auto pNew = new T(fn);
	return HANDLE(_beginthreadex(nullptr, 0, [](void* pNew)->unsigned
		{
			const auto exit_code = (*static_cast<T*>(pNew))();
			delete static_cast<T*>(pNew);
			return exit_code;
		}, pNew, 0, nullptr));
}
#include <vector>
int main()
{
	CRITICAL_SECTION c;
	InitializeCriticalSection(&c);
	const HANDLE hStartEvent = CreateEventW(nullptr, true, false, nullptr);
	std::vector<HANDLE> threads;
	for (int i = 0; i < 10; ++i) {
		threads.push_back(new_thread([hStartEvent, &c, i]()->unsigned
			{
				(void)WaitForSingleObject(hStartEvent, INFINITE);
				for (int j = 0; j < 10; ++j) {
					Sleep(500);
					const auto s = (std::ostringstream() << "Thread #" << i << ": " << j << '\n').str();
					EnterCriticalSection(&c);
					OutputDebugStringA(s.c_str());
					LeaveCriticalSection(&c);
					Sleep(500);
				}
				return 0;
			}));
	}
	SetEvent(hStartEvent);
	(void)WaitForMultipleObjects
	( /*_In_               DWORD          nCount        */static_cast<DWORD>(threads.size())
	, /*_In_reads_(nCount) CONST HANDLE * lpHandles     */&threads.front()
	, /*_In_               BOOL           bWaitAll      */true
	, /*_In_               DWORD          dwMilliseconds*/INFINITE
	);
	for (const auto hThread : threads)
		(void)CloseHandle(hThread);
	DeleteCriticalSection(&c);
	(void)CloseHandle(hStartEvent);
}
