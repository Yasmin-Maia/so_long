/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:11:33 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 14:40:07 by ymaia-do         ###   ########.fr       */
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
