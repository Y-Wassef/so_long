/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:21:32 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/11 21:03:13 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	argc--;
	argv++;
	if (argc != 1)
	{
		if (argc == 0)
			ft_printf("Add map file ending with .ber as argument\n");
		else
			ft_printf("Too many arguments\n");
		exit(1);
	}
	parse_map_file(argv[0], &map);
	game.map = &map;
	game.moves = 0;
	ft_mlx_init(&game);
	mlx_loop_hook(game.mlx_ptr, check_render, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, ButtonPressMask, close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
