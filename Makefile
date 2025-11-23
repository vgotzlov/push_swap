# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 15:46:35 by vgotzlov          #+#    #+#              #
#    Updated: 2025/11/23 17:03:28 by vgotzlov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude

SRC		= src/main.c \
		  src/parse.c \
		  src/validate.c \
		  src/index.c \
		  src/utils.c \
		  src/s_ops.c \
		  src/r_ops.c \
		  src/stack_helpers.c \
		  src/stack_helpers2.c \
		  src/rr_ops.c \
		  src/p_ops.c \
		  src/sort_small.c \
		  src/radix.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
