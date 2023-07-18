/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:24:07 by ikhristi          #+#    #+#             */
/*   Updated: 2023/04/14 15:24:20 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_check(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		res = ft_strjoin("", s2);
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
	}
	return (res);
}
