/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:58:08 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/23 14:34:49 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "libftprintf.h"

//define key-handeler number
# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 110
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define WALL "./textures/wall.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER "./textures/player.xpm"
# define COL "./textures/collectible.xpm"
# define EXIT "./textures/exit.xpm"

typedef struct	s_map
{
	char	**grid;
	int		**visited;
	int		found_c_cnt;
	int		found_e_cnt;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		c_count;
	int		e_count;
	int		p_count;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		move_cnt;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	col;
	t_img	exit;
	t_map	map;
}	t_game;

//graphic.c
void	init_game_info(t_game *g);
void	render_map(t_game *g);
void	move_player(t_game *g, int x, int y);
int		key_press_handler(int key, t_game *g);
int		exit_hook(t_game *g);

//free_util.c
void	error_exit(char *error_msg, t_game *g);
void	ft_all_clean(t_game *g);
void	free_grid(char **grid);
void	free_visited(int **visited, int height);

//maps_util.c
void	init_maps(t_map *map);
int		init_visited(t_map *map);
int		add_line_to_grid(t_map *maps, char *new_line);

//util.c
int	ft_strlen_gnl(char *line);

//check.c
int		read_map(int map_fd, t_map *map);
int		validation_map(t_map *map);
int		validate_border(t_map *map);
int		validate_elements(t_map *map);
int		validate_route(t_map *map);

//dfs.c
void	dfs(int x, int y, t_map *map);

#endif
