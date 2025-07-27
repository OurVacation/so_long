/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:36:27 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/27 13:29:28 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_gnl(char *line)
{
	int	i;

	if (!line)
	{
		return (-1);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void	put_image_helper(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor.ptr, \
		x * 64, y * 64);
	if (g->map.grid[y][x] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall.ptr, \
			x * 64, y * 64);
	else if (g->map.grid[y][x] == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->col.ptr, \
			x * 64, y * 64);
	else if (g->map.grid[y][x] == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit.ptr, \
			x * 64, y * 64);
	else if (g->map.grid[y][x] == 'P')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player.ptr, x \
			* 64, y * 64);
}

void	reach_exit(t_game *g)
{
	if (g->map.c_count == 0 && g->map.e_count == 1)
	{
		ft_printf("You reached the exit!\n");
		ft_all_clean(g);
		exit(0);
	}
	else
	{
		ft_printf("You cannot exit yet, collect all items first!\n");
		g->move_cnt--;
	}
}
