/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:58:08 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/17 17:07:07 by taewonki         ###   ########.fr       */
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

# include "get_next_line.h"
# include "libft.h"
# include "libftprintf.h"

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

//free_util.c
void	free_grid(char **grid);
void	free_visited(t_map *map);

//maps_util.c
void	init_maps(t_map *map);
void	init_visited(t_map *map);
int		add_line_to_grid(t_map *maps, char *new_line);

//util.c
int	ft_strlen_gnl(char *line);

//check.c
void	read_map(int map_fd, t_map *map);

//dfs.c
void	dfs(int x, int y, t_map *map);

#endif
