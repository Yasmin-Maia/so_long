/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/30 17:59:24 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h> // open
# include <unistd.h> // close

# define TILE 64

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
    char    **map;
    int     map_width;
    int     map_height;

    int     num_collect;
    int     collectec;
    int     moves;

    t_pos   player_pos;
    t_pos   exit_pos;

    void    *mlx;
    void    *win;

    // sprites
    void    *player;
    void    *wall;
    void    *collect;
    void    *exit;
    void    *floor;
} t_game;

void	error_exit(char *msg);

char	**read_map(char *file);
int     get_map_height(char *file);
int     get_map_width(char *file);
void	find_player_position(t_game *game);

void	draw_map(t_game *game);
int     main(int ac, char **av);

int	validate_map(char **map);

int handle_keypress(int keycode, t_game *game);
int	count_collectibles(char **map);

#endif