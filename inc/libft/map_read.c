/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:39:08 by ikhristi          #+#    #+#             */
/*   Updated: 2023/06/27 14:49:21 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	lines_count(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_game *game, char *map)
{
	char	**res;
	int		fd;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		throw_error(game, NULL, "File path is invalid!\n");
	res = ft_calloc(sizeof(char *), lines_count(fd) + 1);
	if (!res)
		return (NULL);
	close(fd);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		res[i] = str;
		str = get_next_line(fd);
		i++;
	}
	res[i] = 0;
	close(fd);
	return (res);
}
