# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 18:44:04 by seizquie          #+#    #+#              #
#    Updated: 2024/12/16 19:07:53 by seizquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC= cc
CFLAGS= -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar -rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: all clean fclean re
	

