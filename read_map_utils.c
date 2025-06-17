/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:53:19 by ymaia-do          #+#    #+#             */
/*   Updated: 2025/06/17 15:05:28 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gnl_clear(int fd)
{
	char	*buffer;

	if (fd < 0)
		return ;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		free(buffer);
	}
	buffer = get_next_line(-1);
	if (buffer)
		free(buffer);
}

// count lines of map
int	get_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error to open map\n", NULL, NULL);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	gnl_clear(fd);
	close(fd);
	return (height);
}
