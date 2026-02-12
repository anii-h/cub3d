#include ".../../includes/cub3d.h"

static int	parse_color_code(int *component, char **line, int last)
{
	while (ft_isspace(**line))
		(*line)++;
	*component = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (!last)
	{
		if (**line == ',')
			(*line)++;
		else
			return (1);
	}
	return (0);
}

static int	parse_color_helper(char *line, t_color *color)
{
	int	r;
	int	g;
	int	b;

	if (!parse_color_code(&r, &line, 0) || !parse_color_code(&g, &line, 0) ||
			!parse_color_code(&b, &line, 1))
		return (1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	color->r = r;
	color->g = g;
	color->b = b;
	color->hex = (r << 16) | (g << 8) | b; //0xRRGGBB format
	return (0);
}

int	parse_color(t_game *game, char *line, char *temp)
{
	int	ret;

	ret = 0;
	if (*line == 'F')
		ret = parse_color_helper(line, game->floor_color);
	if (*line == 'C')
		ret = parse_color_helper(line, game->ceiling_color);
	if (ret == 1)
	{
		free(temp);
		printf("Error: Failed to parse color!\n");
	}
	return (ret);
}