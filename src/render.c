/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:21:40 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:21:43 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void		print_moves(t_game *game);
static t_render	*trim_list(t_game *game);

int	check_render(t_game *game)
{
	game->counter++;
	if (game->game_lost == TRUE)
	{
		if (!(game->counter % DEATH_RENDER_INTERVAL))
			die(game);
		return (0);
	}
	update_enemies_status(game);
	if (game->game_lost == TRUE)
		return (0);
	if (game->render == TRUE)
		render_frame(game);
	else if (!(game->counter % C_RENDER_INTERVAL) || \
	!(game->counter % P_RENDER_INTERVAL))
		render_frame(game);
	return (0);
}

void	render_frame(t_game *game)
{
	int			index;
	void		*tile;
	t_point		point;
	t_render	*to_render;

	to_render = game->points_to_render;
	while (to_render)
	{
		point = to_render->point;
		index = get_index(game, game->map->map[point.y][point.x]);
		if (game->map->map[point.y][point.x] == PLAYER_CHAR)
			tile = game->player_sprites[index];
		else if (game->map->map[point.y][point.x] == COLLECTIBLE_CHAR)
			tile = game->collectible_sprites[index];
		else
			tile = game->other_sprites[index];
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, tile, \
		point.x * TILE_LENGTH, point.y * TILE_LENGTH);
		to_render = to_render->next;
	}
	render_enemies(game);
	print_moves(game);
	game->points_to_render = trim_list(game);
	game->render = FALSE;
}

static void	print_moves(t_game *game)
{
	int	disp;
	int	disp_tile;

	if (game->moves > 999)
		return ;
	disp_tile = (game->map->width - 3);
	disp = game->moves % 10;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->digits[disp], (disp_tile + 2) * TILE_LENGTH, 0);
	disp = (game->moves % 100) / 10;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->digits[disp], (disp_tile + 1) * TILE_LENGTH, 0);
	disp = game->moves / 100;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->digits[disp], disp_tile * TILE_LENGTH, 0);
}

static t_render	*trim_list(t_game *game)
{
	t_point		point;
	t_render	*node;
	t_render	*next_node;

	node = game->points_to_render;
	while (node)
	{
		point = node->point;
		next_node = node->next;
		if (game->map->map[point.y][point.x] == WALL_CHAR || \
		(game->map->map[point.y][point.x] == FLOOR_CHAR && \
		game->map->map[point.y + 1][point.x] != ENEMY_CHAR && \
		game->map->map[point.y - 1][point.x] != ENEMY_CHAR && \
		game->map->map[point.y][point.x + 1] != ENEMY_CHAR && \
		game->map->map[point.y][point.x - 1] != ENEMY_CHAR))
			clear_node(&game->points_to_render, node);
		node = next_node;
	}
	return (game->points_to_render);
}
