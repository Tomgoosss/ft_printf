/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:40:02 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/06 11:54:17 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			return(pfitoa(va_arg(args, int)));
		i++;
	}
    return(i);
}

int ft_printf(const char *var, ...)
{
    va_list args;
    int count;
    
    int i;

    i  = 0;
	count = 0;
    va_start(args, var);
    while (var[i])
    {
        if ( var[i] != '%' && var[i])
        	count += write(1, &var[i], 1);
        else
            count += numpick(&var[i++], args);
        i++;
    }
    va_end(args);
    return (count); 
}

int main()
{
    // char *test = "p";
	int test = 1234;


    ft_printf("this is my printf = %d\n", test);
    printf("this is the real function = %d\n", test);
    
}

