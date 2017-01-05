# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/15 12:48:53 by jlangman          #+#    #+#              #
#    Updated: 2016/07/15 13:40:36 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRC = display.c ft_enter.c ft_key.c ft_list.c ft_move.c ft_operation.c\
	  ft_print.c ft_resize.c ft_select.c ft_select_all.c ft_signals.c\
	  helper.c terminal_mod.c

INC = -I ./ft_select.h

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@make -C libft
	@gcc $(FLAGS) -ltermcap -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	@rm -f $(OBJ)
	cd libft/ && make clean

fclean: clean
	@rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all
