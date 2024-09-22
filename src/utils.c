/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:20:22 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:20:25 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	free_2d(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	get_index(t_game *game, char c)
{
	int	index_offset;

	if (c == WALL_CHAR)
		return (WALL_INDEX);
	if (c == EXIT_CHAR && game->exit_status == CLOSED)
		return (EXIT_CLOSED_INDEX);
	if (c == EXIT_CHAR && game->exit_status == OPEN)
		return (EXIT_OPEN_INDEX);
	if (c == COLLECTIBLE_CHAR)
	{
		index_offset = (game->counter / (C_RENDER_INTERVAL)) % \
		(COLLECTIBLE_SP_COUNT);
		return (COLLECTIBLE_INDEX + index_offset);
	}
	if (c == PLAYER_CHAR)
	{
		index_offset = (game->counter / (P_RENDER_INTERVAL)) % \
		(PLAYER_SP_COUNT / 2);
		if (game->orientation == LEFT)
			return (PLAYER_LEFT_INDEX + index_offset);
		if (game->orientation == RIGHT)
			return (PLAYER_RIGHT_INDEX + index_offset);
	}
	return (FLOOR_INDEX);
}

int	get_enemy_index(t_enemy *enemy)
{
	int	index;

	if (enemy->orientation == RIGHT)
		index = ENEMY_RIGHT_IDLE_INDEX;
	else
		index = ENEMY_LEFT_IDLE_INDEX;
	if (enemy->status == RUNNING)
	{
		index += ENEMY_RIGHT_RUN_INDEX;
		index += (enemy->counter / (E_RUN_RENDER_INTERVAL)) % 6;
	}
	else
		index += (enemy->counter / (E_IDLE_RENDER_INTERVAL)) % 4;
	return (index);
}

char	*replace_char(char *string, char replace, char c)
{
	char	*mod;
	int		i;

	mod = malloc(ft_strlen(string) + 1);
	mod[0] = '\0';
	ft_strlcat(mod, string, ft_strlen(string) + 1);
	i = 0;
	while (mod[i] != '\0')
	{
		if (mod[i] == replace)
			mod[i] = c;
		i++;
	}
	return (mod);
}
