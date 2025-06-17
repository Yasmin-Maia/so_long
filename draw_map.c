/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:50:12 by ymaia-do          #+#    #+#             */
/*   Updated: 2025/06/17 13:13:31 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprites(t_game *game)
{
	int	w;
	int	h;

	game->player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/blood_vial.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/mystic_floor.xpm", &w, &h);
	if (!game->player || !game->wall || !game->collect
		|| !game->exit || !game->floor)
	{
		destroy_images(game);
		return (0);
	}
	return (1);
}

void	put_tile_image(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, x * 64, y * 64);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			tile = game->map[y][x];
			mlx_put_image_to_window(game->mlx, game->win,
				game->floor, x * 64, y * 64);
			put_tile_image(game, tile, x, y);
			x++;
		}
		y++;
	}
}
