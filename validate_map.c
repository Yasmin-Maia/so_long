/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:34 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/11 17:46:16 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(char **map)
{
	size_t	len;
	int		i;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static void	count_elements(char **map, int *p, int *e, int *c)
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

static int	check_elements(char **map)
{
	int	p;
	int	e;
	int	c;

	count_elements(map, &p, &e, &c);
	if (p != 1)
		return (0);
	if (e != 1)
		return (0);
	if (c < 1)
		return (0);
	return (1);
}

static int	check_walls(char *line)
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

static int	check_surrounded(char **map)
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
		if (i == 0 || i == height - 1)
		{
			if (!check_walls(map[i]))
				return (0);
		}
		else if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && 
				map[i][j] != 'P' && map[i][j] != 'E' && 
				map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_rectangular(game->map))
		error_exit("Map is not rectangular");
	if (!check_elements(game->map))
		error_exit("Invalid elements count");
	if (!check_surrounded(game->map))
		error_exit("Map not surrounded by walls");
	if (!check_chars(game->map))
		error_exit("Invalid characters in map");
	return (1);
}