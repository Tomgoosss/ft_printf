#include "ft_printf.h"

static int lengicount(int n)
{
    int len;

    if (n == 0)
        return 1;
    len = 0;
    if (n < 0)
    {
        n = -n;
    }
    while (n)
    {
        n /= 10;
        len++;
    }

    return (len);
}

int printint(long nb)
{
    int len = lengicount(nb);
    char str[len + 1];
	int i;
	
	i = 0;

    if (nb < 0)
    {
        ft_putchar_fd('-', 1);
        nb = -nb;
    }
    if (nb == 0)
    {
        ft_putchar_fd('0', 1);
    }
    else
    {
        str[len] = '\0';
        while (nb)
        {
            len--;
            str[len] = nb % 10 + 48;
            nb = nb / 10;
        }
        while (str[i])
        {
            ft_putchar_fd(str[i], 1);
            i++;
        }
    }
    return (len);
}
