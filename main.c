/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:48:15 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/12 16:29:11 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	int	w;
	int	h;

	game->player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &w, &h);
	if (!game->player)
		error_exit("failed to load player");
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &w, &h);
	if (!game->wall)
		error_exit("failed to load wall");
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/blood_vial.xpm", &w, &h);
	if (!game->collect)
		error_exit("failed to load collect");
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &w, &h);
	if (!game->exit)
		error_exit("failed to load exit");
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/mystic_floor.xpm", &w, &h);
	if (!game->floor)
		error_exit("failed to load floor");
}

static void	put_tile_image(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, x * 64, y * 64);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			tile = game->map[y][x];
			mlx_put_image_to_window(game->mlx, game->win,
				game->floor, x * 64, y * 64);
			put_tile_image(game, tile, x, y);
			x++;
		}
		y++;
	}
}

int close_window(t_game *game)
{
	free_all(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		error_exit("Uso: ./so_long map.ber");
	game.map_file = av[1];
	game.map = read_map(av[1]);
	if (!game.map)
    	error_exit("Failed to read map");
	game.num_collect = count_collectibles(game.map);
	game.collectec = 0;
	if (!validate_map(&game))
	{
		free_map(game.map);
		error_exit("Invalid map!");
	}
	if (!init_game(&game))
	{
		free_map(game.map);
		error_exit("Failed to initialize game.");
	}
	if (!validate_path(&game))
		error_exit("No valid path in map");
	draw_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	init_game(t_game *game)
{
	count_map_dimensions(game);
	find_player_position(game);
	game->mlx = mlx_init();
	if (!game->mlx)
    	return (0);
	game->win = mlx_new_window(game->mlx, 64 * game->map_width, 64 * game->map_height, "So Long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
    	free(game->mlx);
    	return (0);
	}
	load_sprites(game);
	return (1);
}
