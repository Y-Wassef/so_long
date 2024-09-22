/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:47:33 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/06 15:47:51 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static char	**get_enemy_xpm_address(void);
static void	destroy_previous_images(t_game *game);

void	parse_enemies(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (ft_strchr(ENEMY_DIRECTIONS, map->map[j][i]))
			{
				if (map->map[j][i] == '^')
					append_to_enemy_list(&map->enemies, i, j, UP);
				else if (map->map[j][i] == '>')
					append_to_enemy_list(&map->enemies, i, j, RIGHT);
				else if (map->map[j][i] == 'v')
					append_to_enemy_list(&map->enemies, i, j, DOWN);
				else if (map->map[j][i] == '<')
					append_to_enemy_list(&map->enemies, i, j, LEFT);
				map->map[j][i] = ENEMY_CHAR;
			}
			i++;
		}
		j++;
	}
}

int	load_enemy_sprites(t_game *game)
{
	int		width;
	int		height;
	char	**xpm_array;
	int		i;

	xpm_array = get_enemy_xpm_address();
	i = 0;
	while (i < ENEMY_SP_COUNT)
	{
		game->enemy_sprites[i] = mlx_xpm_file_to_image(game->mlx_ptr, \
			xpm_array[i], &width, &height);
		if (!game->enemy_sprites[i++] || width != TILE_LENGTH || \
		height != TILE_LENGTH)
		{
			free_2d(xpm_array);
			destroy_previous_images(game);
			if (!game->enemy_sprites[--i])
				destroy_images(game, i - 1, ENEMY_SPRITES);
			else
				destroy_images(game, i, ENEMY_SPRITES);
			return (SPRITES_FAIL);
		}
	}
	free_2d(xpm_array);
	return (NO_ERROR);
}

static char	**get_enemy_xpm_address(void)
{
	char	**array;

	array = malloc((ENEMY_SP_COUNT + 1) * sizeof(char *));
	array[0] = ft_strdup(E_RIGHT_IDLE_0_XPM);
	array[1] = ft_strdup(E_RIGHT_IDLE_1_XPM);
	array[2] = ft_strdup(E_RIGHT_IDLE_2_XPM);
	array[3] = ft_strdup(E_RIGHT_IDLE_3_XPM);
	array[4] = ft_strdup(E_RIGHT_RUN_0_XPM);
	array[5] = ft_strdup(E_RIGHT_RUN_1_XPM);
	array[6] = ft_strdup(E_RIGHT_RUN_2_XPM);
	array[7] = ft_strdup(E_RIGHT_RUN_3_XPM);
	array[8] = ft_strdup(E_RIGHT_RUN_4_XPM);
	array[9] = ft_strdup(E_RIGHT_RUN_5_XPM);
	array[10] = ft_strdup(E_LEFT_IDLE_0_XPM);
	array[11] = ft_strdup(E_LEFT_IDLE_1_XPM);
	array[12] = ft_strdup(E_LEFT_IDLE_2_XPM);
	array[13] = ft_strdup(E_LEFT_IDLE_3_XPM);
	array[14] = ft_strdup(E_LEFT_RUN_0_XPM);
	array[15] = ft_strdup(E_LEFT_RUN_1_XPM);
	array[16] = ft_strdup(E_LEFT_RUN_2_XPM);
	array[17] = ft_strdup(E_LEFT_RUN_3_XPM);
	array[18] = ft_strdup(E_LEFT_RUN_4_XPM);
	array[19] = ft_strdup(E_LEFT_RUN_5_XPM);
	array[20] = NULL;
	return (array);
}

static void	destroy_previous_images(t_game *game)
{
	destroy_images(game, PLAYER_SP_COUNT -1, PLAYER_SPRITES);
	destroy_images(game, COLLECTIBLE_SP_COUNT -1, COLLECTIBLE_SPRITES);
	destroy_images(game, OTHER_SP_COUNT -1, OTHER_SPRITES);
	destroy_images(game, 9, DIGITS);
}
