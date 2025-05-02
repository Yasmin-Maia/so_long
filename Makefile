# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 10:12:33 by yasmin            #+#    #+#              #
#    Updated: 2025/05/02 15:51:53 by yasmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

MLX_DIR = ./mlx
MLX_LIB = -L$(MLX_DIR) -lmlx
MLX_INC = -I$(MLX_DIR)
MLX_SYS = -lXext -lX11

INCLUDES = -I. $(LIBFT_INC) $(MLX_INC)
LIBS = $(LIBFT) $(MLX_LIB) $(MLX_SYS)

SRCS = main.c read_map.c validate_map_utils.c validate_map.c error.c movement.c
OBJS = $(SRCS:.c=.o)

all: check_libft $(NAME)

check_libft:
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "[libft] Pasta encontrada."; \
	else \
		echo "Clonando libft..."; \
		git clone git@github.com:Yasmin-Maia/libft.git $(LIBFT_DIR); \
		echo "Clonagem concluída."; \
	fi
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re check_libft
