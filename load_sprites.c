/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:35:00 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/24 18:38:21 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Load all game sprites using MLX
 * This function loads all the images needed for the game
 */
void	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player = mlx_xpm_file_to_image(game->mlx, 
		"./textures/player.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, 
		"./textures/wall.xpm", &width, &height);
	game->collect = mlx_xpm_file_to_image(game->mlx, 
		"./textures/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, 
		"./textures/exit.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, 
		"./textures/floor.xpm", &width, &height);
	
	if (!game->player || !game->wall || !game->collect 
		|| !game->exit || !game->floor)
		error_exit("Failed to load sprites");
}
