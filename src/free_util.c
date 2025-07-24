/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:16:12 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/23 14:20:29 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_msg, t_game *g);
void	ft_all_clean(t_game *g);
void	free_grid(char **grid);
void	free_visited(int **visited, int height);

void	error_exit(char *error_msg, t_game *g)
{
	printf("error_exit() start\n");
	if (g)
	{
		ft_printf("%s", error_msg);
		ft_all_clean(g);
		exit(EXIT_FAILURE);
	}
}

void	ft_all_clean(t_game *g)
{
	printf("ft_all_clean() start\n");
	if (g)
	{
		printf("wall img destroy\n");
		if (g->wall.img_ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->wall.img_ptr);
		printf("floor img destroy\n");
		if (g->floor.img_ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->floor.img_ptr);
		printf("player img destroy\n");
		if (g->player.img_ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->player.img_ptr);
		printf("collective img destroy\n");
		if (g->col.img_ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->col.img_ptr);
		printf("exit img destroy\n");
		if (g->exit.img_ptr && g->mlx_ptr)
			mlx_destroy_image(g->mlx_ptr, g->exit.img_ptr);
		printf("win_ptr destroy\n");
		if (g->win_ptr && g->mlx_ptr)
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		printf("mlx_ptr destroy\n");
		if (g->mlx_ptr)
			mlx_destroy_display(g->mlx_ptr);
		printf("free_grid()\n");
		if (g->map.grid)
			free_grid(g->map.grid);
		printf("free_visited()\n");
		if (g->map.visited)
			free_visited(g->map.visited, g->map.height);
	}
}

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_visited(int **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
	{
		if (visited[i])
			free(visited[i]);
		i++;
	}
	free(visited);
}
