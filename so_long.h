/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:02:38 by ymaia-do         ###   ########.fr       */
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

typedef struct s_valid
{
	int	colletibles_found;
	int	total_collectibles;
	int	exit_found;
}	t_valid;

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

int		check_rectangular(char **map);
int		check_elements(char **map);
int		check_walls(char *line);
int		check_surrounded(char **map);
int		check_chars(char **map);

int		load_sprites(t_game *game);
void	put_tile_image(t_game *game, char tile, int x, int y);
void	draw_map(t_game *game);

void	error_exit(char *msg, char **map, t_game *game);

int		validate_path(t_game *game);

void	free_map(char **map);
void	destroy_images(t_game *game);
void	free_all(t_game *game);

void	find_player_position(t_game *game);
void	count_map_dimensions(t_game *game);
int		init_game(t_game *game);

int		close_window(t_game *game);
int		main(int ac, char **av);

int		handle_keypress(int keycode, t_game *game);
int		count_collectibles(char **map);

void	gnl_clear(int fd);
int		get_map_height(char *file);

char	**read_map(char *file);

int		retangular_map(char **map);
int		check_top_bottom(char *line);

void	count_elements(char **map, int *p, int *e, int *c);
void	elements(char **map, int *player, int *exit, int *collectible);
int		required_elements(char **map);
int		validate_map(t_game *game);

#endif