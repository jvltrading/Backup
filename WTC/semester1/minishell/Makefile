# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/08 10:37:40 by jlangman          #+#    #+#              #
#    Updated: 2016/07/08 12:20:37 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRC = main.c prompt.c helper.c setenv.c unsetenv.c env.c ft_exit.c \
	cd.c builtin.c error.c ft_getenv.c echo.c

INC = -I libft/includes -I includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)
	cd libft/ && make clean

fclean: clean
	@echo rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean re all
