# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/05 11:19:45 by jlangman          #+#    #+#              #
#    Updated: 2016/10/05 11:28:08 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SDIR = ./src/
IDIR = ./inc/
LIBS = -L ./libft/ -lft -lmlx -framework OpenGL -framework AppKit -g3
SRC = $(SDIR)main.c  $(SDIR)parse.c $(SDIR)controls.c $(SDIR)draw.c \
	  $(SDIR)fractals.c $(SDIR)init.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo " - Compiling $(NAME)..."
	@make -C ./libft/
	@$(CC) $(CFLAGS) -I$(IDIR) $^ -o $(NAME) $(LIBS)
	@echo "Done."

%.o:%.c
	@echo " - Creating $<..."
	@$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

clean:
	@echo " - Cleaning object files..."
	@make clean -C ./libft/
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@make fclean -C ./libft/ 
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
