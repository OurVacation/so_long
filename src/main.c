/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:21:06 by taewonki          #+#    #+#             */
/*   Updated: 2025/07/26 15:56:25 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*file_ext;

	ft_bzero(&game, sizeof(game));
	if (ac < 2)
		error_exit("av is less than 2\n", &game);
	file_ext = ft_strchr(av[1], '.');
	if (!file_ext || (ft_strncmp(file_ext, ".ber", 4) != 0 && \
		ft_strlen(file_ext) != 4))
		error_exit("file extension is invalid\n", &game);
	init_maps(&game.map);
	if (read_map(open(av[1], O_RDONLY), &game.map) == -1)
		error_exit("read_map() failed\n", &game);
	if (validation_map(&game.map) == -1)
		error_exit("map is not vaild\n", &game);
	init_game_info(&game);
	render_map(&game);
	mlx_key_hook(game.win_ptr, key_press_handler, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
