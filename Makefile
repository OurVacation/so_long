# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 13:56:48 by taewonki          #+#    #+#              #
#    Updated: 2025/07/20 14:26:55 by taewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -I$(FT_PRINTF_DIR) -I$(FT_LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
LFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

SRC_DIR = src
FT_LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux

FT_LIBFT_LIB = $(FT_LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/libgnl.a
MLX_LIB = $(MLX_DIR)/libmlx.a

NAME = so_long

SRC = $(SRC_DIR)/check.c $(SRC_DIR)/dfs.c $(SRC_DIR)/free_util.c\
		$(SRC_DIR)/graphic.c $(SRC_DIR)/main.c $(SRC_DIR)/maps_util.c\
		$(SRC_DIR)/util.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(FT_LIBFT_LIB) $(FT_PRINTF_LIB) $(GNL_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) -L$(GNL_DIR) -lgnl -L$(FT_PRINTF_DIR) -lftprintf -L$(FT_LIBFT_DIR) -lft $(MLX_LIB) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_LIBFT_LIB):
	$(MAKE) -C $(FT_LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(FT_LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(MLX_DIR)

re : fclean all

.PHONY: all clean fclean re
