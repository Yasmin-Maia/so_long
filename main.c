/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaia-do <ymaia-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:48:15 by yasmin            #+#    #+#             */
/*   Updated: 2025/06/03 15:41:12 by ymaia-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	int	w;
	int	h;

	game->player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/blood_vial.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/mystic_floor.xpm", &w, &h);
	if (!game->player || !game->wall || !game->collect
		|| !game->exit || !game->floor)
		error_exit("Erro ao carregar um ou mais sprites");
}

static void	put_tile_image(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, x * TILE, y * TILE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, x * TILE, y * TILE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect, x * TILE, y * TILE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, x * TILE, y * TILE);
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
				game->floor, x * TILE, y * TILE);
			put_tile_image(game, tile, x, y);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		error_exit("Uso: ./so_long map.ber");
	game.map = read_map(av[1]);
	game.num_collect = count_collectibles(game.map);
	game.collectec = 0;
	if (!validate_map(game.map))
		error_exit("Mapa inválido!");
	game.map_width = get_map_width(av[1]);
	game.map_height = get_map_height(av[1]);
	find_player_position(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, TILE * get_map_width(av[1]),
			TILE * get_map_height(av[1]), "So Long");
	load_sprites(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
