/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:23:24 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/06 15:14:44 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int init_map(t_game *game, const char *map_file)
{
	game->map.map = NULL;
	game->tmp_head = NULL;
	game->map.start_dir = 0; // 0 - not set yet
	game->map.width = 0;
	game->map.height = 0;
	game->map.start_pos_x = -1; // -1 - not found yet
	game->map.start_pos_y = -1;
	if (parse_map(&game->map, map_file) != 0)
	{
		printf("Error: failed to parse the .map file!\n");
		return (1);
	}
	return (0);
}
