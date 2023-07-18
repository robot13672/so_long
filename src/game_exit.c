/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:56:36 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/22 16:03:52 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_game(t_game *game)
{
	if (game->map)
		ft_strstr_free(game->map);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	if (game->map_exit.xpm_ptr)
		mlx_destroy_image(game->mlx, game->map_exit.xpm_ptr);
	if (game->collectible.xpm_ptr)
		mlx_destroy_image(game->mlx, game->collectible.xpm_ptr);
	if (game->player_left.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_left.xpm_ptr);
	if (game->player_right.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_right.xpm_ptr);
	if (game->player_up.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_up.xpm_ptr);
	if (game->player_down.xpm_ptr)
		mlx_destroy_image(game->mlx, game->player_down.xpm_ptr);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit (0);
	return (0);
}
