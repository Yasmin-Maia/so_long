/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:34 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/03 16:01:28 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			j++;
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
		error_exit("Map must contain exactly 1 'P', 1 'E', and at least "
			"1 'C'.");
	if (!check_surrounded(map))
		error_exit("Map must be surrounded by walls.");
	if (!validate_char(map))
		error_exit("invalid charactere");
	return (1);
}
