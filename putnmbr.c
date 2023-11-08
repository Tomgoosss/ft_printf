#include "ft_printf.h"

int countnumm(int i)
{
	int count;

	count = 0;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

int main(void)
{
	int i = 10;

	printf("%i", countnumm(i));
}