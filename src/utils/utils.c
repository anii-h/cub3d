/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:15:55 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/06 15:22:53 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if(map->map)
	{
		while (i < map->height)
		{
			free(map->map[i]);
			i++;
		}	
		free(map->map);
		map->map = NULL;
	}
	map->height = 0;
	map->width = 0;
}