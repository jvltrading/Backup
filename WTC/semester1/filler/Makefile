# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 11:48:54 by jlangman          #+#    #+#              #
#    Updated: 2016/06/12 11:53:59 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c analyse.c strstart.c free.c save_map.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

FLAGC= -L libft/ -lft

all: $(NAME)

$(NAME):lib
	@gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(FLAGC)

lib:
	make -C libft/

clean: libclean
	rm -rf $(OBJ)

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

fclean: clean libfclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
