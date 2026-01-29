#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include "../lib/minilibx-linux/mlx.h"

typedef struct s_game
{
	void *mlx;
	void *win;
}	t_game;

void	init_mlx(t_game *game);

#endif