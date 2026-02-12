#include "../../include/cub3d.h"

int	init_mlx(t_game *game, t_map *map)
{
	game->mlx.mlx = NULL;
	game->mlx.win = NULL;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		free_map(map);
		printf("Error: mlx initialization failed!/n");
		return (1);
	}
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_WIDTH,
		WIN_HEIGHT, "cub3d");
	if (!game->mlx.win)
	{
		free_map(map);
		printf("Error: mlx window creation failed!/n");
		return (1);
	}
	game->mlx.win_height = WIN_HEIGHT;
	game->mlx.win_width = WIN_WIDTH;
	return (0);
}

int	render_img(t_game *game)
{
	game->mlx.render.img = mlx_new_image(game->mlx.mlx, game->mlx.win_width, game->mlx.win_height);
	if(!game->mlx.render.img)
	{
		printf("Error: failed to create new image!\n");
		return (1);
	}
	game->mlx.render.img_data = mlx_get_data_addr(game->mlx.render.img, &game->mlx.render.bpp,
			&game->mlx.render.line_length, &game->mlx.render.endian);
	if(!game->mlx.render.img_data)
	{
		printf("Error: failed to get the image data address!\n");
		mlx_destroy_image(game->mlx.mlx, game->mlx.render.img);
		return (1);
	}
	return (0);
}