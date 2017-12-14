/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:11:18 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/04 15:57:09 by rdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_new_map(int size)
{
	char	*newmap;
	int		i;
	int		lines;
	int		col;

	i = 0;
	lines = 0;
	col = 0;
	if (!(newmap = (char *)malloc(sizeof(char) * ((size + 1) * size) + 1)))
		return (NULL);
	while (i < (size + 1) * size)
	{
		while (col < size)
		{
			newmap[i++] = '.';
			col++;
		}
		newmap[i++] = '\n';
		col = 0;
		lines++;
	}
	newmap[i] = '\0';
	return (newmap);
}

char	*ft_get_next_line(char *piece)
{
	int i;

	i = 0;
	while (piece[i] && piece[i] != '\n')
		i++;
	return (piece + i + 1);
}

char	*ft_fill_map(char *map, char *piece, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = map;
	while (piece[i])
	{
		if ((piece[i] == '\n' && piece[i + 1] != '\0')
				|| (map[i] == '\n' && map[i + 1] != '\0'))
		{
			map = ft_get_next_line(map);
			piece = ft_get_next_line(piece);
			i = 0;
		}
		if (map[i] == '.' && piece[i] == '#')
			map[i] = c;
		i++;
	}
	return (tmp);
}
