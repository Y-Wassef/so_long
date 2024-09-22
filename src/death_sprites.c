/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:41:22 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/09 22:41:25 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static char		**get_death_xpm_address(void);
static void		render_death(t_game *game, t_img *img, int x, int y);
static void		handle_orientation(t_game *game, t_img *img, int *x, int index);

void	die(t_game *game)
{
	static int		index = 0;
	t_img			img;
	int				x;

	game->map->map[game->map->player.y][game->map->player.x] = FLOOR_CHAR;
	if (index < DEATH_SP_COUNT / 2)
	{
		append_to_render(game, game->map->player);
		handle_orientation(game, &img, &x, index);
		img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, \
		&img.endian);
		render_frame(game);
		render_death(game, &img, x, game->map->player.y * TILE_LENGTH);
		index++;
	}
}

static void	handle_orientation(t_game *game, t_img *img, int *x, int index)
{
	if (game->orientation == RIGHT)
	{
		append_to_render(game, (t_point){game->map->player.x + 1, \
		game->map->player.y});
		img->mlx_img = game->death_sprites[DEATH_RIGHT_INDEX + index];
		*x = game->map->player.x * TILE_LENGTH;
	}
	else
	{
		append_to_render(game, (t_point){game->map->player.x - 1, \
		game->map->player.y});
		img->mlx_img = game->death_sprites[DEATH_LEFT_INDEX + index];
		*x = (game->map->player.x - 1) * TILE_LENGTH;
	}
}

static void	render_death(t_game *game, t_img *img, int x, int y)
{
	int	i;
	int	j;
	int	*px;

	j = 0;
	while (j < TILE_LENGTH)
	{
		i = 0;
		while (i < TILE_LENGTH * 2)
		{
			px = (int *)(img->addr + (j * img->line_len + i * (img->bpp / 8)));
			if (*px)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, *px);
			i++;
		}
		j++;
	}
}

int	load_death_sprites(t_game *game)
{
	int		length;
	char	**xpm_array;
	int		i;

	xpm_array = get_death_xpm_address();
	i = 0;
	while (i < DEATH_SP_COUNT)
	{
		game->death_sprites[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			xpm_array[i], &length, &length);
		if (!game->death_sprites[i])
		{
			destroy_images(game, i - 1, DEATH_SPRITES);
			destroy_images(game, PLAYER_SP_COUNT -1, PLAYER_SPRITES);
			destroy_images(game, COLLECTIBLE_SP_COUNT -1, COLLECTIBLE_SPRITES);
			destroy_images(game, OTHER_SP_COUNT -1, OTHER_SPRITES);
			destroy_images(game, ENEMY_SP_COUNT -1, ENEMY_SPRITES);
			destroy_images(game, 9, DIGITS);
			free_2d(xpm_array);
			return (SPRITES_FAIL);
		}
		i++;
	}
	free_2d(xpm_array);
	return (NO_ERROR);
}

static char	**get_death_xpm_address(void)
{
	char	**array;

	array = malloc((DEATH_SP_COUNT + 1) * sizeof(char *));
	array[0] = ft_strdup(DEATH_RIGHT_0_XPM);
	array[1] = ft_strdup(DEATH_RIGHT_1_XPM);
	array[2] = ft_strdup(DEATH_RIGHT_2_XPM);
	array[3] = ft_strdup(DEATH_RIGHT_3_XPM);
	array[4] = ft_strdup(DEATH_RIGHT_4_XPM);
	array[5] = ft_strdup(DEATH_RIGHT_5_XPM);
	array[6] = ft_strdup(DEATH_LEFT_0_XPM);
	array[7] = ft_strdup(DEATH_LEFT_1_XPM);
	array[8] = ft_strdup(DEATH_LEFT_2_XPM);
	array[9] = ft_strdup(DEATH_LEFT_3_XPM);
	array[10] = ft_strdup(DEATH_LEFT_4_XPM);
	array[11] = ft_strdup(DEATH_LEFT_5_XPM);
	array[12] = NULL;
	return (array);
}
