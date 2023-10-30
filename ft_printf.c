/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:40:02 by tgoossen          #+#    #+#             */
/*   Updated: 2023/10/30 15:59:13 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int printchar(int c)
{
	write (1, &c, 1);
	return (c);
}

int ft_printf(const char *var, ...)
{
	va_list args;
	
	int i;

	i  = 0;
	va_start(args, var);
	while (var[i])
	{
		if (var[i] == '%')
		{
			
		}
	}
	va_end(args);
	return (i); 
}

int main()
{
	char test = 'j';

	ft_printf("this is my printf = %c\n", test);
	printf("this is the real function = %c\n", test);
	
}