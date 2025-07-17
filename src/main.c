/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:21:06 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/17 14:14:13 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_map	map;
	void	*mlx_ptr;
	int		fd_maps;

	mlx_ptr = mlx_init(void);
	if (read_map(open(av[1], O_RDONLY), &map) == -1)
		return (ft_printf("read_map()fail\n"), 0);
	if (validation_map(&map) == -1)
		return (ft_printf("validation_map()fail\n"), 0);
}
