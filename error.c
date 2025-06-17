/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:07:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 13:13:52 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, char **map, t_game *game)
{
	if (map && !game)
		free_map(map);
	free_all(game);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}
