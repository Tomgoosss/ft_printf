#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
#include <unistd.h>

int ft_printf(const char *var, ...);
int ft_hexpointer(long long unsigned i, int firstcall);
int printint(long nb);
int printunsigned(long nb);
int ft_hexpointerlower(long long unsigned i);
int ft_hexpointerupper(long long unsigned i);
void	ft_putchar_fd(char c, int fd);
int	ft_strlen(const char *s);

#endif