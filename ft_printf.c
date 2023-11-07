/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:40:02 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/07 19:29:55 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int numpick(const char *var, va_list args)
{
    int i;
    const char *str;
    
    i = 0;
	while (var[i])
	{
        if (var[i] == 'c')
        {
			ft_putchar_fd(va_arg(args, int), 1);
        }
        else if (var[i] == 's')
        {
            str = va_arg(args, const char *);
           	return(write(1, str, ft_strlen(str)));
        }
		else if (var[i] == 'p')
			return (ft_hexpointer(va_arg(args, long long unsigned), 1));
		else if (var[i] == 'd' || var[i] == 'i')
			return(printint(va_arg(args, int)));
		else if (var[i] == 'u')
			return(printunsigned(va_arg(args, unsigned int)));
		else if (var[i] == 'x')
			return(ft_hexpointerlower(va_arg(args, unsigned int)));
		else if (var[i] == 'X')
			return(ft_hexpointerupper(va_arg(args, unsigned int)));
		else if (var[i] == '%')
			ft_putchar_fd('%', 1);
		i++;	
	}
    return(i);
}
int valid(char s) {
	int i;
	i = 0;
	char *c = "cspdiuxX%";

	while (c[i]) {
		if (c[i] == s) return 1;
		i++;
	}
	return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    int i;

    i = 0;
    count = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == '%')
        {
            count += write(1, &format[i], 1);
            i += 2;
        }
        else if (format[i] == '%' && valid(format[i + 1]))
        {
            count += numpick(&format[i + 1], args);
            i += 2;
        }
        else
        {
            count += write(1, &format[i], 1);
            i++; 
        }
    }
    va_end(args);
    return (count);
}

// int main()
// {
//     // char *test = "kjsadsad";
// 	int test =  -3333;


//     ft_printf("this is my printf = %u\n", test);
//     printf("this is the real function = %u\n", test);
    
// }