/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:46:47 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/30 15:50:49 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player(t_game *game, int dx, int dy)
{
	int		new_x = game->player_pos.x + dx;
	int		new_y = game->player_pos.y + dy;
	char	next_tile;

	if (new_x < 0 || new_y < 0 || new_y >= game->map_height
		|| new_x >= game->map_width)
		return ;
	next_tile = game->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->collectec++;
	if (next_tile == 'E' && game->collectec < game->num_collect)
		return ;
	if (next_tile == 'E' && game->collectec == game->num_collect)
	{
		ft_printf("Congratulations! You won in %d movements.", game->moves + 1);
		exit(0);
	}
	if (game->map[game->player_pos.y][game->player_pos.x] != 'E')
		game->map[game->player_pos.y][game->player_pos.x] = '0';
	if (next_tile != 'E')
		game->map[new_y][new_x] = 'P';
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	game->moves++;
	ft_printf("Movements: %d\n", game->moves);
}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)	
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	draw_map(game);
	return (0);
}