# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:53:02 by tidebonl          #+#    #+#              #
#    Updated: 2025/11/11 16:56:21 by tidebonl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = $(addprefix app/, character.c, windows.c)
GNL_SRC = $(addprefix lib/gnl/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC = $(addprefix lib/printf/, ft_print_c.c ft_putnbr.c ft_putstr.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
    $(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re : fclean all
