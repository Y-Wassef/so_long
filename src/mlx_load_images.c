/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:13:30 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/03 21:13:32 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	load_collectible_sprites(t_game *game);
static int	load_other_sprites(t_game *game);
static int	load_digits(t_game *game);

int	load_sprites(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	**sprites_xpm;

	sprites_xpm = (char *[PLAYER_SP_COUNT]){P_RIGHT_0_XPM, P_RIGHT_1_XPM, \
	P_RIGHT_2_XPM, P_RIGHT_3_XPM, P_LEFT_0_XPM, P_LEFT_1_XPM, P_LEFT_2_XPM, \
	P_LEFT_3_XPM};
	i = 0;
	while (i < PLAYER_SP_COUNT)
	{
		game->player_sprites[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			sprites_xpm[i], &width, &height);
		if (!game->player_sprites[i] || width != TILE_LENGTH || \
		height != TILE_LENGTH)
		{
			if (!game->player_sprites[i])
				destroy_images(game, i - 1, PLAYER_SPRITES);
			else
				destroy_images(game, i, PLAYER_SPRITES);
			return (SPRITES_FAIL);
		}
		i++;
	}
	return (load_collectible_sprites(game));
}

static int	load_collectible_sprites(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	**sprites_xpm;

	sprites_xpm = (char *[COLLECTIBLE_SP_COUNT]){COLLECTIBLE_0_XPM, \
	COLLECTIBLE_1_XPM, COLLECTIBLE_2_XPM, COLLECTIBLE_3_XPM};
	i = 0;
	while (i < COLLECTIBLE_SP_COUNT)
	{
		game->collectible_sprites[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			sprites_xpm[i], &width, &height);
		if (!game->collectible_sprites[i] || width != TILE_LENGTH || \
		height != TILE_LENGTH)
		{
			destroy_images(game, PLAYER_SP_COUNT - 1, PLAYER_SPRITES);
			if (!game->collectible_sprites[i])
				destroy_images(game, i - 1, COLLECTIBLE_SPRITES);
			else
				destroy_images(game, i, COLLECTIBLE_SPRITES);
			return (SPRITES_FAIL);
		}
		i++;
	}
	return (load_other_sprites(game));
}

static int	load_other_sprites(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	**sprites_xpm;

	sprites_xpm = (char *[OTHER_SP_COUNT]){FLOOR_XPM, WALL_XPM, \
	EXIT_CLOSED_XPM, EXIT_OPEN_XPM};
	i = 0;
	while (i < OTHER_SP_COUNT)
	{
		game->other_sprites[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			sprites_xpm[i], &width, &height);
		if (!game->other_sprites[i++] || width != TILE_LENGTH || \
		height != TILE_LENGTH)
		{
			destroy_images(game, PLAYER_SP_COUNT -1, PLAYER_SPRITES);
			destroy_images(game, COLLECTIBLE_SP_COUNT -1, COLLECTIBLE_SPRITES);
			if (!game->other_sprites[--i])
				destroy_images(game, i - 1, OTHER_SPRITES);
			else
				destroy_images(game, i, OTHER_SPRITES);
			return (SPRITES_FAIL);
		}
	}
	return (load_digits(game));
}

static int	load_digits(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	*digits_xpm;

	i = 0;
	while (i < 10)
	{
		digits_xpm = replace_char(DISP_0_XPM, '0', (char)(i + '0'));
		game->digits[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			digits_xpm, &width, &height);
		free(digits_xpm);
		if (!game->digits[i++] || width != TILE_LENGTH || height != TILE_LENGTH)
		{
			destroy_images(game, PLAYER_SP_COUNT -1, PLAYER_SPRITES);
			destroy_images(game, COLLECTIBLE_SP_COUNT -1, COLLECTIBLE_SPRITES);
			destroy_images(game, OTHER_SP_COUNT -1, OTHER_SPRITES);
			if (!game->digits[--i])
				destroy_images(game, i - 1, DIGITS);
			else
				destroy_images(game, i, DIGITS);
			return (DIGITS_FAIL);
		}
	}
	return (NO_ERROR);
}
