/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:43:59 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:06:15 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_fill(char **map, int x, int y, t_valid *valid)
{
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		valid->colletibles_found++;
	if (map[y][x] == 'E')
		valid->exit_found = 1;
	map[y][x] = '1';
	if (valid->colletibles_found == valid->total_collectibles
		&& valid->exit_found)
		return (1);
	if (flood_fill(map, x + 1, y, valid))
		return (1);
	if (flood_fill(map, x - 1, y, valid))
		return (1);
	if (flood_fill(map, x, y + 1, valid))
		return (1);
	if (flood_fill(map, x, y - 1, valid))
		return (1);
	return (0);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	t_valid	valid;
	int		result;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	valid.colletibles_found = 0;
	valid.exit_found = 0;
	valid.total_collectibles = game->num_collect;
	result = flood_fill(map_copy, game->player_pos.x,
			game->player_pos.y, &valid);
	free_map(map_copy);
	if (!result)
	{
		ft_putstr_fd("Error: No valid path\n", 2);
		return (0);
	}
	return (result);
}
