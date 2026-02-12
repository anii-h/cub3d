/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:34:10 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/06 15:04:29 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// too long, needs to be refactored and broken down into smaller functions
int parse_map(t_game *game, const char *map_file)
{
	int 	fd;
	int 	*temp;
	char	*line;

	if(!map_file || !game->map || (fd = open(map_file, 0, RDONLY)) < 0)
		return (1);
	while (temp = get_next_line(fd))
	{
		line  = temp;
		while(ft_isspace(*line))
			line++;
		if (*line == '\n' || *line == '\0')
		{	free(temp);
			continue;
		}
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
					!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2))
		{
			if (parse_texture(game, *line, temp) == 1)
				return (1);
		} else if (*line == 'F' || *line == 'C')
		{
			if (parse_color(game, *line, temp) == 1)
				return (1);
		} else if (*line == '1' || *line == '0' || *line == 'N' ||
					*line == 'S' || *line == 'E' || *line == 'W')
		{
			if (parse_map_layout(game, temp) == 1)
				return (1);
		} else
		{
			printf("Error: Invalid line in map file!\n");
			free(temp);
			return (1);
		}
	}
	close (fd);
	return (finalize_map(game));
}