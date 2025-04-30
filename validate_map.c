/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmin <yasmin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:34 by yasmin            #+#    #+#             */
/*   Updated: 2025/04/30 20:14:16 by yasmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map)
{
	if (!retangular_map(map))
		error_exit("A map is not rectangular.");
	if (!required_elements(map))
		error_exit("Map must contain exactly 1 'P', 1 'E', and at least "
			"1 'C'.");
	if (!check_surrounded(map))
		error_exit("Map must be surrounded by walls.");
	return (1);
}
