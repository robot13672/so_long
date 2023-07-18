/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:39:27 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/28 17:07:42 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_image(t_game *game, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, \
		sprite.x * x, sprite.y * y);
}

void	pick_image(char comp, t_game *game, int x, int y)
{
	render_image(game, game->floor, x, y);
	if (comp == WALL)
		render_image(game, game->wall, x, y);
	else if (comp == COLLECTIBLE)
		render_image(game, game->collectible, x, y);
	else if (comp == MAP_EXIT)
		render_image(game, game->map_exit, x, y);
}

void	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			pick_image(map[i][j], game, j, i);
			j++;
		}
		i++;
	}
}

int	game_loop(t_game *game)
{
	if (game->direction == KEY_A)
		render_image(game, game->player_left, \
			game->player_pos.x, game->player_pos.y);
	if (game->direction == KEY_S)
		render_image(game, game->player_down, \
			game->player_pos.x, game->player_pos.y);
	if (game->direction == KEY_W)
		render_image(game, game->player_up, \
			game->player_pos.x, game->player_pos.y);
	if (game->direction == KEY_D)
		render_image(game, game->player_right, \
			game->player_pos.x, game->player_pos.y);
	return (1);
}
