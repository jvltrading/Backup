# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/27 11:47:36 by jlangman          #+#    #+#              #
#    Updated: 2016/10/27 11:52:59 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mod1

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			window_init.c \
			error_quit.c \
			event_listener.c \
			pixel_put.c \
			map_init.c \
			get_map_color.c \
			draw.c \
			get_screen_coord.c \
			map_post_load.c \
			map_parse.c \
			map_place_mount_line.c \
			map_place_mount.c \
			valid_int.c \
			window_reset.c \
			flow.c \
			scenar_wave.c \
			scenar_uprising.c \
			scenar_rain.c \
			scenar_emptying.c \
			scenar_escaping.c \
			water_bck.c \
			water_reset.c \
			flow_wave.c \
			flow_rain.c \
			flow_uprising.c \
			flow_escaping.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft -lmlx -framework AppKit -framework OpenGL

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C  ./libft/
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make clean -C ./libft/
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft/
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
