/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:44 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/17 17:56:53 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (ac != 2)
		error_exit("error");
	game.map = read_map(av[1]);
	if(!validate_map(game.map))
		error_exit("Invalid map");
	while (game.map[i])
	{
		ft_putstr_fd(game.map[i], 1);
		i++;
	}
	return (0);
}