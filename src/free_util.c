/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:16:12 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/27 11:55:04 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_msg, t_game *g);
void	ft_all_clean(t_game *g);
void	free_grid(char ***grid);
void	free_visited(int ***visited, int height);

void	error_exit(char *error_msg, t_game *g)
{
	if (g)
	{
		ft_printf("%s", error_msg);
		ft_all_clean(g);
		exit(EXIT_FAILURE);
	}
}

void	ft_all_clean(t_game *g)
{
	if (g)
	{
		if (g->wall.ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->wall.ptr);
		if (g->floor.ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->floor.ptr);
		if (g->player.ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->player.ptr);
		if (g->col.ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->col.ptr);
		if (g->exit.ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->exit.ptr);
		if (g->win_ptr && g->mlx_ptr)
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		if (g->mlx_ptr)
			mlx_destroy_display(g->mlx_ptr);
		if (g->map.grid != NULL)
			free_grid(&g->map.grid);
		if (g->map.visited != NULL)
			free_visited(&g->map.visited, g->map.height);
	}
}

void	free_grid(char ***grid)
{
	int		i;
	char	**grid_temp;

	if (!grid || !*grid)
		return ;
	i = 0;
	grid_temp = *grid;
	while (grid_temp[i])
	{
		free(grid_temp[i]);
		i++;
	}
	free(grid_temp);
	*grid = NULL;
}

void	free_visited(int ***visited, int height)
{
	int	i;
	int	**visited_temp;

	if (!visited || !*visited)
		return ;
	i = 0;
	visited_temp = *visited;
	while (i < height)
	{
		if (visited_temp[i])
			free(visited_temp[i]);
		i++;
	}
	free(visited_temp);
	*visited = NULL;
}
