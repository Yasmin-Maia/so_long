/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:07:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:52:30 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, char **map, t_game *game)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (game)
		free_all(game);
	if (map && (!game || (game && game->map != map)))
		free_map(map);
	exit(1);
}
