/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:07:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 12:06:28 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, char **map, t_game *game)
{
	if (map && !game)
		free_map(map);
	free_all(game);
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_game *game)
{
	if (game->player)
	mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
	mlx_destroy_image(game->mlx, game->wall);
	if (game->collect)
	mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
	mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
	mlx_destroy_image(game->mlx, game->floor);
}

void free_all(t_game *game)
{
    if (!game)
        return;
    
    // Free the map first
    if (game->map)
        free_map(game->map);

    // Free graphics resources in correct order
    if (game->mlx)
    {
        destroy_images(game);
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}
