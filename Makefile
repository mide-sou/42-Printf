# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 15:54:19 by mide-sou          #+#    #+#              #
#    Updated: 2022/03/29 15:54:24 by mide-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf \
		ft_printf1 \

CC = gcc

RM =rm -rf

CFLAGS = -Wall -Werror -Wextra -I.

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)

all:$(NAME)

clean:
	$(RM)	$(SRC:=.o)

fclean: clean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY: all clean fclean re
