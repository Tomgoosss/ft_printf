/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knockla <knockla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:38:10 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/08 15:27:12 by knockla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *var, ...);
int		ft_hexpointer(long long unsigned i, int firstcall);
int		printint(long nb);
int		printunsigned(long nb);
int		ft_hexpointerlower(long long unsigned i);
int		ft_hexpointerupper(long long unsigned i);
int		ft_putchar(char c);
int		ft_strlen(const char *s);
int		putstr(const char *c);

#endif