#include "libftprintf.h"

int ft_hexpointer(long long unsigned i, int firstcall)
{
	if (firstcall)
	{
		ft_putchar_fd(48, 1);
		ft_putchar_fd('x', 1);
	}
	if (i >= 16)
		ft_hexpointer(i / 16, 0);
	if (i % 16 >= 10)
		ft_putchar_fd(i % 16 + 87, 1);
	else if (i % 16 > 0)
		ft_putchar_fd(i % 16 + 48, 1);
	else
		ft_putchar_fd(48, 1);
	
	return (i);
}