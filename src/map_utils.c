/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:34:08 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/26 15:55:36 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	add_comp(char c, t_comp *comps)
{
	if (c == MAP_EXIT)
		comps->exit += 1;
	else if (c == COLLECTIBLE)
		comps->collect += 1;
	else if (c == PLAYER)
		comps->player += 1;
	else if (c != WALL && c != FLOOR && c != '\n')
		return (0);
	return (1);
}

void	count_components(t_game *game, char **map, t_comp *comps)
{
	int	i;
	int	j;

	i = 0;
	init_comp(comps);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!add_comp(map[i][j], comps))
				throw_error(game, comps, "Map has invalid characters!");
			j++;
		}
		i++;
	}
}
