/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:28:18 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/20 14:57:17 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		read_map(int map_fd, t_map *map);
int		validation_map(t_map *map);
int		validate_border(t_map *map);
int		validate_elements(t_map *map);
int		validate_route(t_map *map);

int	read_map(int map_fd, t_map *map)
{
	char	*line;
	int		width;

	if (map_fd < 0 || !map)
		return (-1);
	while ((line = get_next_line(map_fd)) != NULL)
	{
		width = ft_strlen_gnl(line);
		if (map->height == 0)
			map->width = width;
		if (width == 0)
			return (free(line), free_grid(map->grid), -1);
		if (map->width != width)
			return (free(line), free_grid(map->grid), -1);
		add_line_to_grid(map, line);
	}
	if (map->height == 0)
		return (-1);
	return (close(map_fd), 0);
}

int	validation_map(t_map *map)
{
	if (map->width < 3 || map->height < 3)
		return (-1);
	if (validate_border(map) == -1)
		return (-1);
	if (validate_elements(map) == -1)
		return (-1);
	if (map->c_count < 1 || map->e_count > 1 || map->p_count > 1)
		return (-1);
	init_visited(map);
	if (validate_route(map) == -1)
		return (-1);
	free_visited(map->visited, map->height);
	return (1);
}

int	validate_border(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			return (-1);
		x++;
	}
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	validate_elements(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == 'C')
				map->c_count++;
			else if (map->grid[y][x] == 'E')
				map->e_count++;
			else if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				map->p_count++;
			}
			else if (map->grid[y][x] != '1' && map->grid[y][x] != '0' &&\
					map->grid[y][x] != 'P' && map->grid[y][x] != 'C' &&\
					map->grid[y][x] != 'E')
			{
				return (ft_printf("invalid character!\n"), -1);
			}
		}
	}
	return (1);
}

int	validate_route(t_map *map)
{
	dfs(map->player_x, map->player_y, map);
	if (map->found_c_cnt != map->c_count)
		return (ft_printf("not match C count!\n"), -1);
	else if (map->found_e_cnt != 1)
		return (ft_printf("exit is 0 or more than 1\n"), -1);
	else
		return (1);
}
