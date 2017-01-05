# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 10:42:45 by jlangman          #+#    #+#              #
#    Updated: 2016/11/22 11:07:08 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

C_FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./src/

INCL = /includes/wolf3d.h

LIB = libft/libft.a

SRC = $(SRC_PATH)main.c $(SRC_PATH)ray_casting.c		\
	  $(SRC_PATH)read_map.c $(SRC_PATH)draw.c			\
	  $(SRC_PATH)key_hook.c $(SRC_PATH)freq.c			\

OBJ = $(SRC_PATH)main.o $(SRC_PATH)ray_casting.o		\
	  $(SRC_PATH)read_map.o $(SRC_PATH)draw.o			\
	  $(SRC_PATH)key_hook.o $(SRC_PATH)freq.o			\

all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\nPreparing to compile Wolf3D..."
	@$(CC) $(C_FLAGS) -c $(SRC) -I $(INCL)
	@echo "Successfully created all your object files..."
	@mv *.o src/
	@echo "Successfully moved all the object files to src/"
	@$(CC) -o $(NAME) $(C_FLAGS) $(OBJ) $(MLX_FLAGS) -L libft/ -lft
	@echo "Successfully compiled your Wolf3D.\n"

clean:
	@cd libft/ && make clean
	@rm -f $(OBJ)
	@echo "Removed object files."

fclean: clean
	@cd libft/ && make fclean
	@rm -f $(NAME)
	@echo "Removed the executable."

re: fclean all
	@echo "Successfully recompiled."

norme: 
	@norminette $(SRC)
