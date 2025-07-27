/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:58 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/26 16:32:51 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_info(t_game *g);
void	render_map(t_game *g);
int		move_player(t_game *g, int x, int y);
int		key_press_handler(int key, t_game *g);
int		exit_hook(t_game *g);

void	init_game_info(t_game *g)
{
	g->mlx_ptr = mlx_init();
	if (g->mlx_ptr == NULL)
		error_exit("mlx_init failed\n", g);
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->map.width * 64, \
		g->map.height * 64, "so_long");
	if (g->win_ptr == NULL)
		error_exit("mlx_new_window() failed\n", g);
	g->move_cnt = 0;
	g->wall.ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		WALL, &g->wall.width, &g->wall.height);
	g->floor.ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		FLOOR, &g->floor.width, &g->floor.height);
	g->player.ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		PLAYER, &g->player.width, &g->player.height);
	if (g->player.ptr == NULL)
		error_exit("failed to load player.xpm\n", g);
	g->col.ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		COL, &g->col.width, &g->col.height);
	if (g->col.ptr == NULL)
		error_exit("failed to load collect.xpm\n", g);
	g->exit.ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		EXIT, &g->exit.width, &g->exit.height);
	if (g->exit.ptr == NULL)
		error_exit("failed to load exit.xpm\n", g);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			put_image_helper(g, x, y);
			x++;
		}
		y++;
	}
}

int	move_player(t_game *g, int x, int y)
{
	char	move_to;

	if (x < 0 || x > g->map.width || y < 0 || y > g->map.height)
		return (-1);
	move_to = g->map.grid[y][x];
	if (move_to == '1')
		return (-1);
	g->move_cnt++;
	ft_printf("Moves : %d\n", g->move_cnt);
	if (move_to == 'C')
	{
		g->map.c_count--;
		g->map.grid[y][x] = '0';
	}
	if (move_to == 'E')
		return (reach_exit(g), 1);
	g->map.grid[g->map.player_y][g->map.player_x] = '0';
	g->map.player_x = x;
	g->map.player_y = y;
	g->map.grid[y][x] = 'P';
	return (render_map(g), 1);
}

int	key_press_handler(int key, t_game *g)
{
	if (key == ESC || key == Q)
	{
		ft_printf("Game exited.\n");
		ft_all_clean(g);
		exit(0);
	}
	if (key == W || key == UP)
		move_player(g, g->map.player_x, g->map.player_y - 1);
	else if (key == A || key == LEFT)
		move_player(g, g->map.player_x - 1, g->map.player_y);
	else if (key == S || key == DOWN)
		move_player(g, g->map.player_x, g->map.player_y + 1);
	else if (key == D || key == RIGHT)
		move_player(g, g->map.player_x + 1, g->map.player_y);
	return (0);
}

int	exit_hook(t_game *g)
{
	ft_printf("game is closed\n");
	ft_all_clean(g);
	exit(0);
	return (0);
}
