/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:11:33 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/30 20:16:03 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	retangular_map(char **map)
{
	int		i;
	size_t	len;

	if (!map || !map[0])
		return (0);
	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
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

int	check_top_bottom(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_surrounded(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	while (i < height)
	{
		if ((i == 0 || i == height - 1) && !check_top_bottom(map[i]))
			return (0);
		else if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
