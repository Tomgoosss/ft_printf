#include <stdio.h>

int main()
{
	int n = 5;
	char *d;
	d = &n;

	printf("%llu\n", d);
	printf("%p", d);
	return(0);
}