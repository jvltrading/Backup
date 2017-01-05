# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlangman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/27 11:04:07 by jlangman          #+#    #+#              #
#    Updated: 2016/10/27 11:07:12 by jlangman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c			\
	  ft_itoa.c				\
	  ft_bzero.c			\
	  ft_memcpy.c			\
	  ft_memccpy.c			\
	  ft_memmove.c			\
	  ft_memchr.c			\
	  ft_memcmp.c			\
	  ft_strlen.c			\
	  ft_strdup.c			\
	  ft_strcpy.c			\
	  ft_strncpy.c			\
	  ft_strcat.c			\
	  ft_strncat.c			\
	  ft_strlcat.c			\
	  ft_strchr.c			\
	  ft_strstr.c			\
	  ft_strrchr.c			\
	  ft_strnstr.c			\
	  ft_strcmp.c			\
	  ft_strncmp.c			\
	  ft_atoi.c				\
	  ft_isalpha.c			\
	  ft_isdigit.c			\
	  ft_isascii.c			\
	  ft_isalnum.c			\
	  ft_isprint.c			\
	  ft_toupper.c			\
	  ft_tolower.c			\
	  ft_putchar.c			\
	  ft_putchar_fd.c		\
	  ft_putstr.c			\
	  ft_putstr_fd.c		\
	  ft_putendl.c			\
	  ft_putendl_fd.c		\
	  ft_strequ.c			\
	  ft_strnequ.c			\
	  ft_strclr.c			\
	  ft_memalloc.c			\
	  ft_memdel.c			\
	  ft_strnew.c			\
	  ft_strdel.c			\
	  ft_strtrim.c			\
	  ft_strsub.c			\
	  ft_striter.c			\
	  ft_striteri.c			\
	  ft_strmap.c			\
	  ft_strmapi.c			\
	  ft_putnbr.c			\
	  ft_putnbr_fd.c		\
	  ft_strjoin.c			\
	  ft_strsplit.c			\
	  ft_iswhitespace.c		\
	  ft_lstadd.c			\
	  ft_lstnew.c			\
	  ft_strmerge.c			\
	  get_next_line.c		\
	  ft_strsplittoint.c	\
	  ft_atol.c				\
	  ft_strisdigit.c		\
	  ft_strjoin_free1.c	\
	  ft_strjoin_free2.c	\
	  ft_strjoin_free3.c	\


SRCO = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC)
	ar ruv $(NAME) $(SRCO)
	ranlib $(NAME)
clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
