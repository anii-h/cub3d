/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:54:20 by miyolchy          #+#    #+#             */
/*   Updated: 2026/01/29 18:09:33 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_game game;

	init_mlx(&game);

	
	
	mlx_loop(game.mlx);
	write(1, "Makefile\n", 99);
	return (0);
}
