#include <Windows.h>
#include <sstream>
int main()
{
	OutputDebugStringA("�V�t�gJIS�p\n");
	OutputDebugStringW(L"Unicode�p\n");
	OutputDebugStringA((std:: ostringstream() << "OutputDebugStringA: " << 123 << '\n').str().c_str());
	OutputDebugStringW((std::wostringstream() << "OutputDebugStringW: " << 123 << '\n').str().c_str());
}
