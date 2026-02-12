#include "../../includes/cub3d.h"

static void free_textures(t_game *game)
{
	if (!game || game->mlx.mlx)
		return ;
	if (game->textures.north && hame->mlx.mlx)
		mlx_destroy_image(game->mlx.mlx, game->textures.north.img);
	if (game->textures.south && game->mlx.mlx)
		mlx_destroy_image(game->mlx.mlx, game->textures.south.img);
	if (game->textures.east && game->mlx.mlx)
		mlx_destroy_image(game->mlx.mlx, game->textures.east.img);
	if (game->textures.west && game->mlx.mlx)
		mlx_destroy_image(game->mlx.mlx, game->textures.west.img);
}

static void free_texture_paths(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north_path)
		free(textures->north_path);
	if (textures->south_path)
		free(textures->south_path);
	if (textures->east_path)
		free(textures->east_path);
	if (textures->west_path)
		free(textures->west_path);
}

static void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	if (game->mlx.win && game->mlx.mlx)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.img && game->mlx.mlx)
		mlx_destroy_image(game->mlx.mlx, game->mlx.render.img);
	free_texture_paths(&game->textures);
	free_map(&game->map);
}

void	cleanup_and_exit(t_game *game, int exit_code)
{
	cleaup_game(game);
	exit(exit_code);
}