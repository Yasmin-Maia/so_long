/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:21:53 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/11 18:57:47 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gnl_clear(int fd)
{
    char	*buffer;
    
    while (1)
    {
        buffer = get_next_line(fd);
        if (!buffer)
            break;
        free(buffer);
    }
}

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
	fd = open(file, O_RDONLY);
	gnl_clear(fd);
	close(fd);
	return (height);
}

void	count_map_dimensions(t_game *game)
{
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	game->collectec = 0;
	game->num_collect = 0;
	game->moves = 0;
}

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
		{
			while (i > 0)
			{
				free(map[--i]);
			}
			free(map);			
			error_exit("Error reading the map line.");
		}
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
	int	y;
	int	x;

	y = 0;
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
