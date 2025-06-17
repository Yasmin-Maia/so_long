/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:48:15 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/17 15:14:34 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_all(game);
	return (0);
}

static int	is_ber(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (len > 4 && !ft_strncmp(filename + len - 4, ".ber", 4));
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		error_exit("Error: Uso: ./so_long map.ber\n", NULL, NULL);
	if (!is_ber(av[1]))
		error_exit("Error: Please insert file .ber\n", NULL, NULL);
	game.map_file = av[1];
	game.map = read_map(av[1]);
	if (!game.map)
		error_exit("Error: Failed to read map\n", NULL, NULL);
	game.num_collect = count_collectibles(game.map);
	game.collectec = 0;
	if (!validate_map(&game))
		error_exit(NULL, game.map, NULL);
	if (!init_game(&game))
		error_exit("Error: Failed to initialize game.\n", game.map, NULL);
	if (!validate_path(&game))
		error_exit(NULL, game.map, &game);
	draw_map(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
