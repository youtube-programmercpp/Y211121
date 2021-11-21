#include <stdio.h>
template<class T>void test(const T& s)
{
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", s(i));
	}
}
// C++0x ... C++11 ‚ª³Ž®‚É“oê‚·‚é‘O‚Ì–¼‘O
int main()
{
	struct   {
		int k;
		int a;
		int operator()(int x) const
		{
			return k * x + a;
		}
	} s;
	s.k = 10;
	s.a = 50000;
	test(s);
}
