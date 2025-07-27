/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:42:01 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/26 15:43:47 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height || \
			map->visited[y][x] == 1)
		return ;
	map->visited[y][x] = 1;
	if (map->grid[y][x] == 'C')
		map->found_c_cnt++;
	if (map->grid[y][x] == 'E')
		map->found_e_cnt++;
	dfs(x - 1, y, map);
	dfs(x + 1, y, map);
	dfs(x, y - 1, map);
	dfs(x, y + 1, map);
}
