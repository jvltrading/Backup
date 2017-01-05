# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/10 10:53:37 by jlangman          #+#    #+#              #
#    Updated: 2016/06/18 10:42:34 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_list_dir.c ft_list_dir_a.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib
		gcc $(FLAGS) -c $(SRC)
		gcc -o $(NAME) $(OBJECTS) -L libft/ -lft

lib:
		make -C libft/

clean: libclean
		rm -f $(OBJECTS)

libclean:
		make -C libft/ clean

libfclean:
		make -C libft/ fclean

fclean: clean libfclean
		rm -f $(NAME)

re: fclean all
