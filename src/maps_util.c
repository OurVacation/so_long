/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:11:53 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/27 14:30:30 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_maps(t_map *map)
{
	map->grid = NULL;
	map->visited = NULL;
	map->found_c_cnt = 0;
	map->found_e_cnt = 0;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
}

int	init_visited(t_map *map)
{
	int	**visited;
	int	x;
	int	y;

	visited = malloc(sizeof(int *) * map->height);
	if (!visited)
		return (ft_printf("init_visited() malloc failed!\n"), -1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		visited[y] = ft_calloc(map->width, sizeof(int));
		if (!visited[y])
			return (free_visited(&map->visited, y), -1);
		while (x < map->width)
		{
			if (map->grid[y][x] == '1')
				visited[y][x] = 1;
			x++;
		}
		y++;
	}
	map->visited = visited;
	return (0);
}

int	add_line_to_grid(t_map *maps, char *new_line)
{
	char	**new_grid;
	int		i;

	if (!maps || !new_line)
		return (-1);
	new_grid = malloc(sizeof(char *) * (maps->height + 2));
	if (!new_grid)
		return (free_grid(&maps->grid), -1);
	i = -1;
	if (maps->grid)
	{
		while (maps->grid[++i])
			new_grid[i] = maps->grid[i];
		new_grid[i] = new_line;
	}
	else
		new_grid[++i] = new_line;
	new_grid[i + 1] = NULL;
	maps->height++;
	if (maps->grid)
		free(maps->grid);
	maps->grid = new_grid;
	return (1);
}
