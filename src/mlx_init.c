/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:20:30 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:20:34 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	ft_error_exit(t_game *game, int flag);
static void	map_render_init(t_game *game);

void	ft_mlx_init(t_game *game)
{
	int	flag;

	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_exit(game, MLX_PTR_FAIL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width * \
	TILE_LENGTH, game->map->height * TILE_LENGTH, "so_long");
	if (game->win_ptr == NULL)
		ft_error_exit(game, WIN_PTR_FAIL);
	flag = load_sprites(game);
	if (flag)
		ft_error_exit(game, flag);
	flag = load_enemy_sprites(game);
	if (flag)
		ft_error_exit(game, flag);
	flag = load_death_sprites(game);
	if (flag)
		ft_error_exit(game, flag);
	game->counter = 0;
	game->game_lost = FALSE;
	game->exit_status = CLOSED;
	game->orientation = RIGHT;
	game->points_to_render = NULL;
	map_render_init(game);
	game->render = TRUE;
}

static void	ft_error_exit(t_game *game, int flag)
{
	free(game->map->line_map);
	free_2d(game->map->map);
	clear_enemy_list(&game->map->enemies);
	if (flag == MLX_PTR_FAIL)
		ft_printf("Error\nCouldn't properly initialize MLX display\n");
	else
	{
		if (flag == WIN_PTR_FAIL)
			ft_printf("Error\nCouldn't create MLX window\n'");
		else
		{
			if (flag == SPRITES_FAIL)
				ft_printf("Error\nCouldn't load sprites. ");
			if (flag == DIGITS_FAIL)
				ft_printf("Error\nCouldn't load digits. ");
			ft_printf("Check filenames, sizes and permissions\n");
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		}
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(1);
}

static void	map_render_init(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (j < game->map->height)
	{
		i = 0;
		while (i < game->map->width)
		{
			append_to_render(game, (t_point){i, j});
			i++;
		}
		j++;
	}
}
