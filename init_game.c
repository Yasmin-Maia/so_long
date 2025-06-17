/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:47:53 by ymaia-do          #+#    #+#             */
/*   Updated: 2025/06/17 15:06:03 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: Player's initial position not found!\n", game->map, NULL);
}

void	count_map_dimensions(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	game->collectec = 0;
	game->moves = 0;
}

int	init_game(t_game *game)
{
	count_map_dimensions(game);
	find_player_position(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 64 * game->map_width,
			64 * game->map_height, "So Long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		return (0);
	}
	if (!load_sprites(game))
		return (0);
	return (1);
}
