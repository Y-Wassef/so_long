/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:57:57 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/07 15:58:02 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	flip_status(t_game *game, t_enemy *enemy);
static void	flip_direction(t_game *game, t_enemy *enemy);
static int	is_move_available(t_game *game, t_enemy *enemy);
static void	move_enemy(t_game *game, t_enemy *enemy);

void	update_enemies_status(t_game *game)
{
	int		offset_unit;
	t_enemy	*enemy;

	offset_unit = TILE_LENGTH / (ENEMY_RUN_PERIOD / E_RUN_RENDER_INTERVAL);
	enemy = game->map->enemies;
	while (enemy)
	{
		enemy->counter++;
		move_enemy(game, enemy);
		if (game->game_lost == TRUE)
			return ;
		if (enemy->status == IDLE)
		{
			if (!(enemy->counter % E_IDLE_RENDER_INTERVAL))
				game->render = TRUE;
		}
		else if (!(enemy->counter % E_RUN_RENDER_INTERVAL))
		{
			enemy->offset += offset_unit;
			game->render = TRUE;
		}
		enemy = enemy->next;
	}
}

static void	move_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->status == IDLE)
	{
		if (enemy->counter == ENEMY_REST_PERIOD)
		{
			flip_status(game, enemy);
			if (!is_move_available(game, enemy))
				flip_direction(game, enemy);
		}
	}
	else if (enemy->counter == (int) ENEMY_RUN_PERIOD * (0.30))
	{
		if (game->map->map[enemy->destination.y][enemy->destination.x] == \
		PLAYER_CHAR)
			lose_game(game);
		game->map->map[enemy->destination.y][enemy->destination.x] = \
		ENEMY_CHAR;
	}
	else if (enemy->counter == (int) ENEMY_RUN_PERIOD * (0.60))
		game->map->map[enemy->position.y][enemy->position.x] = FLOOR_CHAR;
	else if (enemy->counter == ENEMY_RUN_PERIOD)
	{
		append_to_render(game, enemy->position);
		enemy->position = enemy->destination;
		flip_status(game, enemy);
	}
}

static void	flip_status(t_game *game, t_enemy *enemy)
{
	if (enemy->status == IDLE)
		enemy->status = RUNNING;
	else
		enemy->status = IDLE;
	enemy->offset = 0;
	enemy->counter = 0;
	enemy->destination = get_enemy_destination(enemy->position, \
	enemy->direction);
	game->render = TRUE;
}

static void	flip_direction(t_game *game, t_enemy *enemy)
{
	if (enemy->direction == LEFT)
		enemy->direction = RIGHT;
	else if (enemy->direction == UP)
		enemy->direction = DOWN;
	else if (enemy->direction == RIGHT)
		enemy->direction = LEFT;
	else if (enemy->direction == DOWN)
		enemy->direction = UP;
	if (enemy->direction == UP || enemy->direction == RIGHT)
		enemy->orientation = RIGHT;
	else
		enemy->orientation = LEFT;
	enemy->destination = get_enemy_destination(enemy->position, \
	enemy->direction);
	if (!is_move_available(game, enemy))
		enemy->status = IDLE;
	game->render = TRUE;
}

static int	is_move_available(t_game *game, t_enemy *enemy)
{
	int	x;
	int	y;

	x = enemy->destination.x;
	y = enemy->destination.y;
	if (game->map->map[y][x] == WALL_CHAR)
		return (FALSE);
	if (game->map->map[y][x] == COLLECTIBLE_CHAR)
		return (FALSE);
	if (game->map->map[y][x] == EXIT_CHAR)
		return (FALSE);
	if (game->map->map[y][x] == ENEMY_CHAR)
		return (FALSE);
	return (TRUE);
}
