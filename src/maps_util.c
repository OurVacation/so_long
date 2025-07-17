/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:11:53 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/17 13:35:17 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_maps(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
}

int	add_line_to_grid(t_map *maps, char *new_line)
{
	char	**new_grid;
	int		i;

	if (!maps || !new_line)
		return (0);
	new_grid = malloc(sizeof(char *) * (maps->height + 2));
	if (!new_grid)
		return (free_grid(maps->grid), free(new_line), 0);
	i = 0;
	if (maps->grid)
	{
		while (maps->grid[i])
		{
			new_grid[i] = maps->grid[i];
			i++;
		}
	}
	new_grid[i] = new_line;
	new_grid[i + 1] = NULL;
	if (maps->grid)
		free(maps->grid);
	maps->height++;
	maps->grid = new_grid;
	return (0);
}
