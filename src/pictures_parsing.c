/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:48:57 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/26 16:21:59 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	read_xmp_image(void *mlx, char *file, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, file, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		throw_error(game, NULL, "Sprites path is invalid!");
	return (sprite);
}

int	init_images(t_game *game)
{
	if (!game)
		return (0);
	game->wall = read_xmp_image(game->mlx, WALL_PATH, game);
	game->player_left = read_xmp_image(game->mlx, PLAYER_LEFT_PATH, game);
	game->player_up = read_xmp_image(game->mlx, PLAYER_UP_PATH, game);
	game->player_right = read_xmp_image(game->mlx, PLAYER_RIGHT_PATH, game);
	game->player_down = read_xmp_image(game->mlx, PLAYER_DOWN_PATH, game);
	game->floor = read_xmp_image(game->mlx, FLOOR_PATH, game);
	game->collectible = read_xmp_image(game->mlx, COLLECTIBLE_PATH, game);
	game->map_exit = read_xmp_image(game->mlx, MAP_EXIT_PATH, game);
	return (1);
}
