# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 13:39:27 by dbliss            #+#    #+#              #
#    Updated: 2020/07/18 18:17:32 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
INCLUDES = ./
SRCS =	flags.c \
		ft_printf.c \
		help_fuctions.c \
		hex.c \
		integer.c \
		percent.c \
		pointer.c \
		string.c \
		width.c \
		char.c \

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
