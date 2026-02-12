/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:15:55 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/12 22:47:23 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if(map->map)
	{
		while (i < map->height)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}	
		free(map->map);
		map->map = NULL;
	}
	t_mapnode	*cur = map->tmp_head;
	while(cur)
	{
		if (cur->line)
			free(cur->line);
		t_mapnode *temp = cur->next;
		free(cur);
		cur = temp;
	}
	map->tmp_head = NULL;
	map->height = 0;
	map->width = 0;
}