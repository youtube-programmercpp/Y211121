#include <stdio.h>

int main()
{
	int k = 10;
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", [k](int x) {return k * x; }(i));
	}
}
