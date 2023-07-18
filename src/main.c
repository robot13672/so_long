/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:27:17 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/28 17:06:50 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (argc != 2)
		throw_error(game, NULL, "Wrong amount of arguments!\n");
	game->map = read_map(game, argv[1]);
	map_check(game);
	game->map_x = ft_strlen(game->map[0]) - 1;
	game->map_y = ft_strstr_len(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_x * 64, \
		game->map_y * 64, "Game");
	init_images(game);
	render_map(game, game->map);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
