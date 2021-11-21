#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

template<class T>void f(const T& fn)
{
	printf("%d\n", fn());
}
//
void f(int (*fn)(void))
{
	printf("%d\n", fn());
}
int f1()
{
	printf("値を入力してください。\n");
	int n;
	if (scanf("%d", &n) == 1)
		return n;
	else
		return -1;
}

int main()
{
#if 1
	f([]()
		{
			printf("値を入力してください。\n");
			int n;
			if (scanf("%d", &n) == 1)
				return n;
			else
				return -1;
		}
	);
#else
	f(f1);
#endif
}
