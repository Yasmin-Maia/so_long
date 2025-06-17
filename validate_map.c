/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:34 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:04:56 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	*p = 0;
	*e = 0;
	*c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

void	elements(char **map, int *player, int *exit, int *collectible)
{
	int	i;
	int	j;

	i = 0;
	*player = 0;
	*exit = 0;
	*collectible = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*player)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				(*collectible)++;
			j++;
		}
		i++;
	}
}

int	required_elements(char **map)
{
	int	player;
	int	exit;
	int	collectible;

	elements(map, &player, &exit, &collectible);
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_rectangular(game->map))
	{
		ft_putstr_fd("Error: Map is not rectangular\n", 2);
		return (0);
	}
	if (!check_elements(game->map))
	{
		ft_putstr_fd("Error: Invalid elements count\n", 2);
		return (0);
	}
	if (!check_surrounded(game->map))
	{
		ft_putstr_fd("Error: Map not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_chars(game->map))
	{
		ft_putstr_fd("Error: Invalid characters in map\n", 2);
		return (0);
	}
	return (1);
}
