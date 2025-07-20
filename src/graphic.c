/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:58 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/20 14:59:15 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_info(t_game *g);
void	render_map(t_game *g);
void	move_player(t_game *g, int x, int y);
int		key_press_handler(int key, t_game *g);
int		exit_hook(t_game *g);

void	init_game_info(t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->map.width * 64, \
		g->map.height * 64, "so_long");
	g->move_cnt = 0;
	g->wall.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		"../textures/wall.xpm", &g->wall.width, &g->wall.height);
	g->floor.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		"../textures/floor.xpm", &g->floor.width, &g->floor.height);
	g->player.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		"../textures/player.xpm", &g->player.width, &g->player.height);
	g->col.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		"../textures/collectible.xpm", &g->col.width, &g->col.height);
	g->exit.img_ptr = mlx_xpm_file_to_image(g->mlx_ptr, \
		"../textures/exit.xpm", &g->exit.width, &g->exit.height);
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
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->floor.img_ptr, x * 64, y * 64);
			if (g->map.grid[y][x] == '1')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall.img_ptr, x * 64, y * 64);
			else if (g->map.grid[y][x] == 'C')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->col.img_ptr, x * 64, y * 64);
			else if (g->map.grid[y][x] == 'E')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit.img_ptr, x * 64, y * 64);
			else if (g->map.grid[y][x] == 'P')
				mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->player.img_ptr, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
void	move_player(t_game *g, int x, int y)
{
	char	move_to;

	if (x < 0 || x > g->map.width || y < 0 || y > g->map.height)
		return ;
	move_to = g->map.grid[y][x];
	if (move_to == '1')
		return ;
	g->move_cnt++;
	ft_printf("Moves : %d\n", g->move_cnt);
	if (move_to == 'C')
	{
		g->map.c_count--;
		g->map.grid[y][x] = '0';
	}
	if (move_to == 'E')
	{
		if (g->map.c_count == 0)
		{
			ft_printf("You win!\n");
			ft_all_clean(g);
			exit(0);
		}
		else
			return ;
	}
	g->map.grid[g->map.player_y][g->map.player_x] = '0';
	g->map.player_x = x;
	g->map.player_y = y;
	g->map.grid[y][x] = 'P';
	render_map(g);
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
