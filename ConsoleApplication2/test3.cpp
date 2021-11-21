#include <Windows.h>
#include <sstream>
int main()
{
	OutputDebugStringA("シフトJIS用\n");
	OutputDebugStringW(L"Unicode用\n");
	OutputDebugStringA((std:: ostringstream() << "OutputDebugStringA: " << 123 << '\n').str().c_str());
	OutputDebugStringW((std::wostringstream() << "OutputDebugStringW: " << 123 << '\n').str().c_str());
}
