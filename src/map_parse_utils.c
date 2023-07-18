/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:30:41 by ikhristi          #+#    #+#             */
/*   Updated: 2023/05/25 16:04:01 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_comp(t_comp *comps)
{
	comps->collect = 0;
	comps->exit = 0;
	comps->player = 0;
}

void	throw_error(t_game *game, t_comp *comp, char *msg)
{
	if (game)
		free(game);
	if (comp)
		free(comp);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

size_t	ft_strstr_len(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**ft_strstrdup(char **str, int size)
{
	char	**res;
	int		i;

	res = ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_strstr_free(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strstr_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
