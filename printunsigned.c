/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:13:07 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/08 13:27:05 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fillstr(char *str, int len, long nb)
{
	while (nb)
	{
		len--;
		str[len] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}

static int	lengicount(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n += INT_MAX;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}


int	printunsigned(long nb)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = lengicount(nb);
	str = malloc((len + 2) * sizeof(char));
	if (nb < 0)
	{
		nb += INT_MAX;
	}
	if (nb == 0)
		ft_putchar_fd('0', 1);
	else
	{
		str[len] = '\0';
		fillstr(str, len, nb);
	}
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	free (str);
	return (len);
}
