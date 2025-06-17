/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:21:53 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:05:23 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**init_map_reading(char *file, int *fd, int *height)
{
	char	**map;

	*height = get_map_height(file);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		error_exit("Error opening map\n", NULL, NULL);
	map = malloc(sizeof(char *) * (*height + 1));
	if (!map)
	{
		close(*fd);
		error_exit("Error: Memory error\n", NULL, NULL);
	}
	return (map);
}

static char	*process_map_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

static void	cleanup_resources(char **map, int count, int fd)
{
	while (count-- > 0)
		free(map[count]);
	free(map);
	gnl_clear(fd);
	close(fd);
}

char	**read_map(char *file)
{
	int		fd;
	int		i;
	int		height;
	char	**map;

	map = init_map_reading(file, &fd, &height);
	i = 0;
	while (i < height)
	{
		map[i] = process_map_line(fd);
		if (!map[i])
		{
			cleanup_resources(map, i, fd);
			error_exit("Error reading map line\n", NULL, NULL);
		}
		i++;
	}
	map[i] = NULL;
	gnl_clear(fd);
	close(fd);
	return (map);
}
