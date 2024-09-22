/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:22:00 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:22:02 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	check_missing_components(t_map *map)
{
	int		flag;
	size_t	i;
	char	*components;

	components = ft_strdup(ESSENTIAL_COMPONENTS);
	flag = 0;
	i = 0;
	while (i < 5)
	{
		if (!ft_strchr(map->line_map, (int)components[i]))
			flag = 1;
		i++;
	}
	free(components);
	return (flag);
}

int	check_duplicates(t_map *map)
{
	int		i;
	size_t	p_count;
	size_t	e_count;

	p_count = 0;
	e_count = 0;
	i = 0;
	map->collectibles = 0;
	while (map->line_map[i] != '\0')
	{
		if (map->line_map[i] == PLAYER_CHAR)
			p_count++;
		else if (map->line_map[i] == EXIT_CHAR)
			e_count++;
		else if (map->line_map[i] == COLLECTIBLE_CHAR)
			(map->collectibles)++;
		i++;
	}
	if (e_count != 1 || p_count != 1)
		return (1);
	else
		return (0);
}

static int	find_in_map(char **map, char component, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == component)
				return (j * width + i);
			i++;
		}
		j++;
	}
	return (-1);
}

static void	populate_map(char **map, int i, int j)
{
	map[i][j] = 'x';
	if (ft_strchr(ACCESSIBLE, (int)map[i + 1][j]))
		populate_map(map, i + 1, j);
	if (ft_strchr(ACCESSIBLE, (int)map[i - 1][j]))
		populate_map(map, i - 1, j);
	if (ft_strchr(ACCESSIBLE, (int)map[i][j + 1]))
		populate_map(map, i, j + 1);
	if (ft_strchr(ACCESSIBLE, (int)map[i][j - 1]))
		populate_map(map, i, j - 1);
}

int	check_valid_path(t_map *map)
{
	char	**temp_map;
	int		width;
	int		height;
	int		i;
	int		j;

	width = map->width;
	height = map->height;
	i = find_in_map(map->map, EXIT_CHAR, map->width, map->height);
	map->exit.x = i % map->width;
	map->exit.y = i / map->width;
	i = find_in_map(map->map, PLAYER_CHAR, map->width, map->height);
	j = i % map->width;
	i = i / map->width;
	map->player.x = j;
	map->player.y = i;
	temp_map = ft_split(map->line_map, '\n');
	populate_map(temp_map, i, j);
	i = find_in_map(temp_map, COLLECTIBLE_CHAR, width, height);
	free_2d(temp_map);
	if (i != -1)
		return (1);
	return (0);
}
