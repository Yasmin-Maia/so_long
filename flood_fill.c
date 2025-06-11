/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:43:59 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/11 19:49:17 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int flood_fill(char **map, int x, int y, t_flood *flood, int num_collectibles)
{
	if (map[y][x] == '1')
		return (0);
    if (map[y][x] == 'C')
        flood->collectibles++;
    if (map[y][x] == 'E')
        flood->exit_reachable = 1;

    // Marque como visitado
    map[y][x] = '1';
	if (flood->collectibles == num_collectibles && flood->exit_reachable)
		return (1);
    // Propague para todas as direções
    if (flood_fill(map, x + 1, y, flood, num_collectibles))
	{
        return (1);
	}
	if (flood_fill(map, x - 1, y, flood, num_collectibles))
    {
	    return (1);
	}
	if (flood_fill(map, x, y + 1, flood, num_collectibles))
    {
	    return (1);
	}
	if (flood_fill(map, x, y - 1, flood, num_collectibles))
    {
	    return (1);
	}
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

int validate_path(t_game *game)
{
    char    **map_copy;
    t_flood flood;
    int     result;

    map_copy = copy_map(game);
    if (!map_copy)
        return (0);
    flood.collectibles = 0;
    flood.exit_reachable = 0;    
    result = flood_fill(map_copy, game->player_pos.x, game->player_pos.y, &flood, game->num_collect);  
	free_map(map_copy);  
    if (!result)
        error_exit("No valid path");
    return (result);
}

