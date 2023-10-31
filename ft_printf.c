/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:40:02 by tgoossen          #+#    #+#             */
/*   Updated: 2023/10/31 18:12:29 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int numpick(const char *var, va_list args)
{
    int i;
    char c;
    const char *str;
    
    i = 0;
	while (var[i])
	{
        if (var[i] == 'c')
        {
            c = va_arg(args, int);
            return(write(1, &c, 1));
        }
        else if (var[i] == 's')
        {
            str = va_arg(args, const char *);
           	return(write(1, str, strlen(str)));
        }
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
            write(1, &var[i], 1);
        else
            count += numpick(&var[i++], args);
        i++;
    }
    va_end(args);
    return (count); 
}

int main()
{
    char *test = "loser wouter";

    ft_printf("this is my printf = %s\n", test);
    printf("this is the real function = %s\n", test);
    
}