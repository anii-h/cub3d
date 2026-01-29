#include "../../include/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 960, "babken");
}