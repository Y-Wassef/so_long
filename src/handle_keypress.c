/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:19:55 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:19:59 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	move_player(t_game *game, t_point old, t_point new);

int	handle_keypress(int keysym, t_game *game)
{
	int	x;
	int	y;

	x = game->map->player.x;
	y = game->map->player.y;
	if (keysym == XK_Escape)
		close_game(game);
	if (game->game_lost == TRUE)
		return (0);
	if (keysym == KEY_UP || keysym == KEY_W)
		move_player(game, (t_point){x, y}, (t_point){x, y - 1});
	else if (keysym == KEY_DOWN || keysym == KEY_S)
		move_player(game, (t_point){x, y}, (t_point){x, y + 1});
	else if (keysym == KEY_RIGHT || keysym == KEY_D)
	{
		game->orientation = RIGHT;
		move_player(game, (t_point){x, y}, (t_point){x + 1, y});
	}
	else if (keysym == KEY_LEFT || keysym == KEY_A)
	{
		game->orientation = LEFT;
		move_player(game, (t_point){x, y}, (t_point){x - 1, y});
	}
	return (0);
}

static void	move_player(t_game *game, t_point old, t_point new)
{
	if (game->map->map[new.y][new.x] == ENEMY_CHAR)
		lose_game(game);
	if (game->map->map[new.y][new.x] == WALL_CHAR)
		return ;
	if (game->map->map[new.y][new.x] == EXIT_CHAR)
	{
		if (game->exit_status == OPEN)
			win_game(game);
		else
			return ;
	}
	if (game->map->map[new.y][new.x] == COLLECTIBLE_CHAR)
	{
		game->map->collectibles--;
		if (game->map->collectibles == 0)
			game->exit_status = OPEN;
	}
	game->moves++;
	game->map->map[new.y][new.x] = PLAYER_CHAR;
	game->map->map[old.y][old.x] = FLOOR_CHAR;
	game->map->player = new;
	append_to_render(game, new);
}
