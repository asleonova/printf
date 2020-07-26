# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 13:39:27 by dbliss            #+#    #+#              #
#    Updated: 2020/07/20 17:55:05 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
INCLUDES = ./
SRCS =	flags.c \
		ft_printf.c \
		help_functions.c \
		identifier.c \
		hex.c \
		integer.c \
		percent.c \
		pointer.c \
		string.c \
		char.c \
		u_integer.c \
		help_func_int.c \
		help_func_hex.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c -Wall -Wextra -Werror -I $(INCLUDES) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
