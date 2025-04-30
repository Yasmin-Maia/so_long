/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:21:53 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/30 15:33:39 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// count lines of map
int	get_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error to open map");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_map_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	width = 0;
	if (fd < 0)
		error_exit("Error to open map");
	line = get_next_line(fd);
	if(!line)
		error_exit("Empty map file");
	while (line[width] && line[width] != '\n')
		width++;
	free(line);
	close(fd);
	return (width);
}

// read map and put in char**
char	**read_map(char *file)
{
	int		fd;
	int		i;
	int		height;
	char	**map;

	height = get_map_height(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error to open map");
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		error_exit("memory error");
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			error_exit("Error reading the map line.");
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	find_player_position(t_game *game)
{
	int	y = 0;
	int	x;

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
	error_exit("Posição inicial do jogador não encontrada!");
}
