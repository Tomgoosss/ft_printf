/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knockla <knockla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:57:34 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/08 15:30:07 by knockla          ###   ########.fr       */
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
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}



int	printint(long nb)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = lengicount(nb);
	str = malloc((len) * sizeof(char));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
		ft_putchar('0');
	else
	{
		str[len] = '\0';
		fillstr(str, len, nb);
	}
	while (str[i])
		ft_putchar(str[i++]);
	free (str);
	return (len);
}
