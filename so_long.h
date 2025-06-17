/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 11:45:55 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h> // open
# include <unistd.h> // close

typedef struct s_flood
{
	int	collectibles;
	int	exit_reachable;
}	t_flood;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	char	**map;
	char	*map_file;
	int		map_width;
	int		map_height;

	int		num_collect;
	int		collectec;
	int		moves;

	int		player_x;
	int		player_y;

	t_pos	player_pos;

	void	*mlx;
	void	*win;

	// sprites
	void	*player;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*floor;
}	t_game;

void	error_exit(char *msg, char **map, t_game *game);
void	destroy_images(t_game *game);
void	free_map(char **map);
void	free_all(t_game *game);

char	**read_map(char *file);
int		get_map_height(char *file);
int		get_map_width(char *file);
void	count_map_dimensions(t_game *game);

void	draw_map(t_game *game);
int		main(int ac, char **av);
int		init_game(t_game *game);
void	find_player_position(t_game *game);

int		validate_map(t_game *game);

int		retangular_map(char **map);
void	elements(char **map, int *player, int *exit, int *collectible);
int		required_elements(char **map);
int		check_top_bottom(char *line);

int		handle_keypress(int keycode, t_game *game);
int		count_collectibles(char **map);

int		validate_path(t_game *game);
int		validate_char(char **map);
void	gnl_clear(int fd);

#endif