# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 12:55:13 by mnepfumb          #+#    #+#              #
#    Updated: 2017/07/30 18:37:12 by mnepfumb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = minishell

SRC = ft_minishell.c ft_utilities.c

OBJ = ft_minishell.o ft_utilities.o

HEADER = ./ft_minishell.h

FLAGS = -Wall -Wextra -Werror -I.

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "minishell complied"

lib:
	@make -C libft/ all

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "minishell clean"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) *.a
	@echo "mminishell fclean"

re: fclean lib all
