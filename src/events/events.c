#include "../../includes/cub3d.h"

int	ft_exit(void *param)
{
	t_game 	*game;

	game = (t_game *)param;
	cleanup_and_exit(game, 0);
	return (0);
}

int	key_pressed(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		cleanup_and_exit(game, 0);
	else if (keycode == 119)	// W
		game->keys.w = 1;
	else if (keycode == 97)		// A
		game->keys.a = 1;
	else if (keycode == 115)	// S
		game->keys.s = 1;
	else if (keycode == 100)	// D
		game->keys.d = 1;
	else if (keycode == 276)	// letf arrow
		game->keys.left = 1;
	else if (keycode == 275)	// right arrow
		game->keys.right = 1;
	return (0);
}

int	key_released(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		cleanup_and_exit(game, 0);
	else if (keycode == 119)	// W
		game->keys.w = 0;
	else if (keycode == 97)		// A
		game->keys.a = 0;
	else if (keycode == 115)	// S
		game->keys.s = 0;
	else if (keycode == 100)	// D
		game->keys.d = 0;
	else if (keycode == 276)	// letf arrow
		game->keys.left = 0;
	else if (keycode == 275)	// right arrow
		game->keys.right = 0;
	return (0);
}

int	cube_loop(void *param)
{
	t_game *game;

	game = (t_game *)param;

	/*
			TODO - the main game loop:
				1. handle player movement based on keys pressed
				2. perform raycasting to determine visible walls and sprites
				3. render the scene to the off-screen image
				4. display the rendered image in the window
	*/
	
	return (0)
}