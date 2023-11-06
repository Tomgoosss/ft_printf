#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

int ft_printf(const char *var, ...);
int ft_hexpointer(long long unsigned i, int firstcall);
int	pfitoa(int n);

#endif