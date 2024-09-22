/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:21:53 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/02 21:21:55 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static size_t	get_map_size(char *map_file);
static char		*read_map_file(char *map_file);
static void		handle_invalid_map(t_map *map);
static void		print_map_error(int flag);

void	parse_map_file(char *map_file, t_map *map)
{
	char	*ext;

	ext = ft_strrchr(map_file, '.');
	if (ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
	{
		ft_printf("Error\nUnknown file type: Use (.ber) file\n");
		exit (1);
	}
	map->line_map = read_map_file(map_file);
	map->map = ft_split(map->line_map, '\n');
	handle_invalid_map(map);
}

static size_t	get_map_size(char *map_file)
{
	char	*line;
	int		fd;
	size_t	len;

	fd = open(map_file, O_RDONLY);
	if (errno)
	{
		perror("Error\nCannot open file");
		exit (1);
	}
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len += ft_strlen(line);
		free(line);
	}
	close(fd);
	return (len);
}

static char	*read_map_file(char *map_file)
{
	char	*line;
	char	*map;
	int		fd;
	size_t	len;

	len = get_map_size(map_file);
	map = malloc(len + 1);
	if (!map)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	map[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_strlcat(map, line, ft_strlen(map) + ft_strlen(line) + 1);
		free(line);
	}
	close(fd);
	return (map);
}

static void	handle_invalid_map(t_map *map)
{
	int		flag;

	flag = VALID_MAP;
	if (check_empty(map))
		flag = check_empty(map);
	else if (check_rectangular(map))
		flag = NOT_RECTANGULAR;
	else if (check_large_map(map))
		flag = MAP_TOO_LARGE;
	else if (check_components(map))
		flag = UNRECOGNIZED;
	else if (check_surrounding(map))
		flag = NOT_SURROUNDED;
	else if (check_missing_components(map))
		flag = MISSING_COMPONENT;
	else if (check_duplicates(map))
		flag = DUPLICATE;
	else if (check_valid_path(map))
		flag = NO_VALID_PATH;
	if (flag != VALID_MAP)
	{
		free_2d(map->map);
		free(map->line_map);
		print_map_error(flag);
	}
}

static void	print_map_error(int flag)
{
	if (flag == EMPTY_MAP)
		ft_printf("Error\nEmpty map file\n");
	if (flag == EMPTY_LINE)
		ft_printf("Error\nEmpty line in map file\n");
	else if (flag == UNRECOGNIZED)
		ft_printf("Error\nUnrecognized character in map\n");
	else if (flag == NOT_RECTANGULAR)
		ft_printf("Error\nMap is not rectangular\n");
	else if (flag == MAP_TOO_LARGE)
		ft_printf("Error\nMap is too large\n");
	else if (flag == NOT_SURROUNDED)
		ft_printf("Error\nMap not surrounded entirely by walls\n");
	else if (flag == MISSING_COMPONENT)
		ft_printf("Error\nMissing component(s)\n");
	else if (flag == DUPLICATE)
		ft_printf("Error\nDuplicate exit or starting position\n");
	else if (flag == NO_VALID_PATH)
		ft_printf("Error\nNo valid path\n");
	exit (1);
}
