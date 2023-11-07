#include "ft_printf.h"

static int lengicountF(int n)
{
    int len;

    if (n == 0)
        return 1;
    len = 0;
    if (n < 0)
    {
        n += 2147483647;
    }
    while (n)
    {
        n /= 10;
        len++;
    }

    return (len);
}


int printunsigned(long nb)
{

    int len = 0;
    char str[len + 1];
	int i;
	
	i = 0;
	len = lengicountF(nb);
    if (nb < 0)
    {
        nb += 2147483647;
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