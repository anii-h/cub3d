#include "../../includes/cub3d.h"

static char	*skip_spaces(char **line)
{
	*line += 2;
	while (ft_isspace(**line))
		(*line)++;
	return (*line);
}

int	parse_texture(t_game *game, char *line, char *temp)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(line, "NO", 2))
		if (!(game->textures.north_path = ft_strdup(skip_spaces(&line))))
			ret = 1;
	else if (!ft_strncmp(line, "SO", 2))
		if(!(game->textures.south_path = ft_strdup(skip_spaces(&line))))
			ret = 1;
	else if(!ft_strncmp(line, "WE", 2))
		if(!(game->textures.west_path = ft_strdup(skip_spaces(&line))))
			ret = 1;
	else if (!ft_strncmp(line, "EA", 2))
		if(!(game->textures.east_path = ft_strdup(skip_spaces(&line))))
			ret = 1;
	if (ret == 1)
	{
		printf("Error: Failed to allocate memory for texture path!\n");
		free(temp);
	}
	return (ret);
}
