/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:18 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/24 18:38:02 by yasmin           ###   ########.fr       */
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

# define TILE 32

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

    // Adicionar os campos para os sprites
    void    *player;
    void    *wall;
    void    *collect;
    void    *exit;
    void    *floor;
} t_game;

void	error_exit(char *msg);

char	**read_map(char *file);

int	main(int ac, char **av);

int	validate_map(char **map);

#endif