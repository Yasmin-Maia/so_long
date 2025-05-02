# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 16:45:00 by yasmin            #+#    #+#              #
#    Updated: 2025/05/02 17:42:22 by yasmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directorio
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/get_next_line
MLX_DIR = ./mlx
FT_PRINTF_DIR = ./libft/ft_printf
GNL_DIR = ./libft/get_next_line

# Sources and Objects
SRCS = main.c read_map.c validate_map_utils.c validate_map.c error.c movement.c
OBJS = $(SRCS:.c=.o)

# Get_next_line and Ft_printf
FT_PRINTF_OBJ = $(FT_PRINTF_DIR)/ft_printf.o $(FT_PRINTF_DIR)/ft_printf_utils.o
GNL_OBJ = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

# Includes
INCLUDES = -I. $(LIBFT_INC) -I$(MLX_DIR)
LIBS = $(LIBFT_A) -L$(MLX_DIR) -lmlx -lXext -lX11

LIBFT_REPO = git@github.com:Yasmin-Maia/libft.git

all: $(LIBFT_A) $(NAME)

# Check if libft exists, if not, to clone the repository
$(LIBFT_A):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Libft não encontrada, clonando..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@echo "Compilando libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Comple so_long
$(NAME): $(OBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

# Comple objects
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
