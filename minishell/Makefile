# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 12:55:13 by mnepfumb          #+#    #+#              #
#    Updated: 2017/09/08 21:15:04 by mnepfumb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = minishell

SRCS = 	minishell.c env.c setenv.c unsetenv.c signals.c cd.c echo.c builtins.c \
        exit.c header.c

SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)
BUILDDIR = ./build/
FLAGS = -Wall -Wextra -Werror -o
LIBDIR = ./libft/
LIB = ./libft/libft.a

all: $(NAME) $(LIB) $(SRC)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	gcc $(FLAGS) $(NAME) $(OBJ) $(LIB) 
	echo $(NAME)" complied"

clean:
	make -C ./libft/ clean
	rm -rf $(OBJ)
	echo "minishell clean"

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME) *.a
	echo "minishell fclean"

re: fclean all 
