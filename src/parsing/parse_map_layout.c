#include "../../includes/cub3d.h"

int	parse_map_layout(t_game *game, char *line)
{
	static	t_mapnode	*head;
	static	t_mapnode	*tail;
	static	int			height;

	head = NULL;
	tail = NULL;
	height = 0;
	t_mapnode	*node = ft_malloc(sizeof(t_mapnode));
	if (!node)
	{
		printf("Error: malloc failed!\n");
		return (1);
	}
	node->line = ft_strdup(line);
	if (!node->line)
	{
		printf("Error: strdup failed\n");
		free(node);
		return (1);
	}
	node->next = NULL;
	if (!head)
		head = node;
	else
		tail->next = node;
	tail = node;
	height++;
	game->map.tmp_head = head;
	game->map.height = height;
	return (0);
}

static void	set_map_width(t_game *game)
{
	int			max_width;
	t_mapnode	*current;

	max_width = 0;
	current = game->map.tmp_head;
	while(current)
	{
		if (ft_strlen(current->line) > max_width)
			max_width = ft_strlen(current->line);
		current = current->next;
	}
	game->map.width = max_width;
}

static int	fill_map(t_map *map)
{
	int			i;
	t_mapnode	*current;

	i = 0;
	current = map->tmp_head;
	map->map = ft_malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
	{
		printf("Error: malloc failed!\n");
		return 1;
	}
	while (current)
	{
		map->map[i] = ft_malloc(sizeof(char *) * (map->width + 1));
		if (!map->map[i])
		{
			printf("Error: malloc failed!\n");
			free_map(map);
			return 1;
		}
		ft_memset(map->map[i], ' ', map->width);
		ft_memcpy(map->map[i], current->line, ft_strlen(current->line));
		map->map[i][map->width] = '\0';
		i++;
		current = current->next;
	}
	map->map[i] = NULL;
	return (0);
}

int	finalize_map(t_game *game)
{
	set_map_width(game);
	return (fill_map(&game->map));
}