/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:32:42 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/06 22:32:46 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	render_enemy(t_game *game, t_enemy *enemy, int x, int y)
{
	int		i;
	int		j;
	int		*px;
	t_img	img;

	img.mlx_img = game->enemy_sprites[get_enemy_index(enemy)];
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, \
	&img.line_len, &img.endian);
	j = 0;
	while (j < TILE_LENGTH)
	{
		i = 0;
		while (i < TILE_LENGTH)
		{
			px = (int *)(img.addr + (j * img.line_len + i * (img.bpp / 8)));
			if (*px)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, *px);
			i++;
		}
		j++;
	}
}

void	render_enemies(t_game *game)
{
	t_point	pos;
	t_enemy	*enemy;

	enemy = game->map->enemies;
	while (enemy)
	{
		pos.x = enemy->position.x * TILE_LENGTH;
		pos.y = enemy->position.y * TILE_LENGTH;
		if (enemy->status == RUNNING)
		{
			if (enemy->direction == UP)
				render_enemy(game, enemy, pos.x, pos.y - enemy->offset);
			else if (enemy->direction == DOWN)
				render_enemy(game, enemy, pos.x, pos.y + enemy->offset);
			else if (enemy->direction == RIGHT)
				render_enemy(game, enemy, pos.x + enemy->offset, pos.y);
			else if (enemy->direction == LEFT)
				render_enemy(game, enemy, pos.x - enemy->offset, pos.y);
			append_to_render(game, enemy->destination);
		}
		else
			render_enemy(game, enemy, pos.x, pos.y);
		enemy = enemy->next;
	}
}
