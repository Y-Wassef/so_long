/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:22:22 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:22:26 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	win_game(t_game *game)
{
	game->moves++;
	ft_printf("------------------------\n");
	ft_printf("YOU WIN!\n");
	ft_printf("Total Movements: %d\n", game->moves);
	ft_printf("------------------------\n");
	close_game(game);
}

void	lose_game(t_game *game)
{
	game->game_lost = TRUE;
	ft_printf("------------------------\n");
	ft_printf("\tYOU LOSE!\n");
	ft_printf("------------------------\n");
}

void	destroy_images(t_game *game, int i, int type)
{
	if (type == PLAYER_SPRITES)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->player_sprites[i--]);
	else if (type == ENEMY_SPRITES)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->enemy_sprites[i--]);
	else if (type == COLLECTIBLE_SPRITES)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->collectible_sprites[i--]);
	else if (type == OTHER_SPRITES)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->other_sprites[i--]);
	else if (type == DEATH_SPRITES)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->death_sprites[i--]);
	else if (type == DIGITS)
		while (i >= 0)
			mlx_destroy_image(game->mlx_ptr, game->digits[i--]);
}

int	close_game(t_game *game)
{
	clear_enemy_list(&game->map->enemies);
	clear_render_list(&game->points_to_render);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	game->win_ptr = NULL;
	destroy_images(game, PLAYER_SP_COUNT -1, PLAYER_SPRITES);
	destroy_images(game, ENEMY_SP_COUNT - 1, ENEMY_SPRITES);
	destroy_images(game, COLLECTIBLE_SP_COUNT -1, COLLECTIBLE_SPRITES);
	destroy_images(game, DEATH_SP_COUNT -1, DEATH_SPRITES);
	destroy_images(game, OTHER_SP_COUNT -1, OTHER_SPRITES);
	destroy_images(game, 9, DIGITS);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game->map->line_map);
	free_2d(game->map->map);
	exit(0);
}
