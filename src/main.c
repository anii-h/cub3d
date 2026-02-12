/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:54:20 by miyolchy          #+#    #+#             */
/*   Updated: 2026/02/12 22:38:37 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_game game;
	t_map map;
	
	init_mlx(&game, &map);

	/* for now */
	mlx_hook(game->mlx.win, 17, 0, on_window_close, &game);		// TODO - destroyNOtify - X
	mlx_hook(game->mlx.win, 2, 1L<<0, on_key_press, &game);     // TODO - whne the key is pressed
	mlx_hook(game->mlx.win, 3, 1L<<1, on_key_release, &game);	// TODO - when the key is released 
	mlx_loop_hook(game->mlx.mlx, game_loop, &game);				// TODO - the main game loop
	mlx_loop(game->mlx.mlx);
}
