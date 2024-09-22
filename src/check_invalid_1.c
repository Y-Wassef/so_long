/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:22:09 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:22:11 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	check_empty(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->line_map);
	if (!len)
		return (EMPTY_MAP);
	if (map->line_map[0] == '\n' || ft_strnstr(map->line_map, "\n\n", len))
		return (EMPTY_LINE);
	return (0);
}

int	check_components(t_map *map)
{
	char	*unrecognized;
	int		check_fail;

	map->enemies = NULL;
	parse_enemies(map);
	unrecognized = ft_strtrim(map->line_map, COMPONENTS);
	if (unrecognized[0] == '\0')
		check_fail = 0;
	else
		check_fail = 1;
	free(unrecognized);
	return (check_fail);
}

int	check_rectangular(t_map *map)
{
	size_t	len;
	size_t	i;
	int		check_fail;

	check_fail = 0;
	len = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
			check_fail = 1;
		i++;
	}
	return (check_fail);
}

int	check_large_map(t_map *map)
{
	size_t	height;
	size_t	width;
	size_t	max_height;
	size_t	max_width;

	max_width = 1920 / TILE_LENGTH + 1;
	max_height = 1080 / TILE_LENGTH - 2;
	width = ft_strlen(map->map[0]);
	height = 0;
	while (map->map[height])
		height++;
	map->width = width;
	map->height = height;
	if (height > max_height || width > max_width)
		return (1);
	else
		return (0);
}

int	check_surrounding(t_map *map)
{
	char	wall;
	size_t	width;
	size_t	height;
	size_t	i;
	int		check_fail;

	width = map->width;
	height = map->height;
	wall = WALL_CHAR;
	check_fail = 0;
	i = 0;
	while (i < height)
	{
		if (map->map[i][0] != wall || map->map[i][width - 1] != wall)
			check_fail = 1;
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map->map[0][i] != wall || map->map[height - 1][i] != wall)
			check_fail = 1;
		i++;
	}
	return (check_fail);
}
