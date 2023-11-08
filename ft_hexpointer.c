/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:38:19 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/08 12:16:04 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lengicount(int n)
{
	int	len;

	if (n == 0)
		return (1);
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
	return (len - 1);
}

int	ft_hexpointer(long long unsigned i, int firstcall)
{
	int	count;

	if (i == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = lengicount(i);
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
	return (count);
}

int	ft_hexpointerlower(long long unsigned i)
{
	int	count;

	count = lengicount(i);
	if (i >= 16)
		ft_hexpointerlower(i / 16);
	if (i % 16 >= 10)
		ft_putchar_fd(i % 16 + 87, 1);
	else if (i % 16 > 0)
		ft_putchar_fd(i % 16 + 48, 1);
	else
		ft_putchar_fd(48, 1);
	return (count);
}

int	ft_hexpointerupper(long long unsigned i)
{
	int	count;

	count = lengicount(i);
	if (i >= 16)
		ft_hexpointerupper(i / 16);
	if (i % 16 >= 10)
		ft_putchar_fd(i % 16 + 55, 1);
	else if (i % 16 > 0)
		ft_putchar_fd(i % 16 + 48, 1);
	else
		ft_putchar_fd(48, 1);
	return (count);
}
