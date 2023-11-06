#include "libftprintf.h"

static int lengicount(int n)
{
    int len;

    if (n == 0)
        return 1;
    len = 0;
    if (n < 0)
    {
        len++;
        n = -n;
    }
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

int pfitoa(int n)
{
    int len = lengicount(n);
    char str[len + 1];
    long nb = n;

    if (n < 0)
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
            str[len] = nb % 10 + '0';
            nb = nb / 10;
        }

        int i = 0;
        while (str[i])
        {
            ft_putchar_fd(str[i], 1);
            i++;
        }
    }
    return len;
}