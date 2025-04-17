/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:34 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/17 18:02:15 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int retangular_map(char **map)
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

static int	required_elements(char **map)
{
	int	i = 0;
	int	j;
	int	player = 0;
	int	exit = 0;
	int	collectible = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
}

static int check_surrounded(char **map)
{
	int	i;
	int	j;
	int	width = ft_strlen(map[0]);
	int	height = 0;

	while (map[height])
		height++;
	i = 0;
	while (map[i])
	{
		if (i == 0 || i == height - 1)
		{
			// Verifica se a linha do topo e do fundo tem só '1'
			j = 0;
			while (j < width)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			// Verifica se as laterais são '1'
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
} 

int	validate_map(char **map)
{
	if (!retangular_map(map))
		error_exit("A map is not rectangular.");
	if (!required_elements(map))
		error_exit("Map must contain exactly 1 'P', 1 'E', and at least 1 'C'.");
	if (!check_surrounded(map))
		error_exit("Map must be surrounded by walls.");
	return (1);
}
