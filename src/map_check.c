/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:17:40 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/28 17:07:03 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == (int)ft_strstr_len(map) - 1 || \
				j == 0 || j == (int)ft_strlen(map[i]) - 2) && \
				map[i][j] != WALL && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangular(char **map)
{
	int	i;

	if (!map || !map[0])
		return (0);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

t_comp	*check_comp(t_game *game, char **map)
{
	t_comp	*comps;

	if (!map || !map[0])
		return (NULL);
	comps = ft_calloc(sizeof(t_comp), 1);
	count_components(game, map, comps);
	if (comps->exit < 1 || comps->player != 1 || comps->collect < 1)
		throw_error(game, comps, "Invalid count of components!");
	return (comps);
}

void	map_check(t_game *game)
{
	t_comp	*comps;

	comps = check_comp(game, game->map);
	if (!check_rectangular(game->map))
		throw_error(game, comps, "Map is not rectangular!");
	if (!check_walls(game->map))
		throw_error(game, comps, "Map wall error!");
	if (!find_path(game, comps))
		throw_error(game, comps, "Map path is invalid");
	free(comps);
}
