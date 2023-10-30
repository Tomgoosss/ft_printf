sourcefiles = 	ft_printf.c

objects =		$(sourcefiles:.c=.o)

NAME =			libftprintf.a

all:			$(NAME)

$(NAME):		$(objects)
	ar rcs libftprintf.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(objects)

fclean:
	rm -f $(objects) $(NAME)

re: 			fclean all