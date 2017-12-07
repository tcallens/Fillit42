/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:08:36 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/07 03:52:34 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_left_movable(char *piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#' && (piece[i - 1] == '\n' || piece[i - 1]
					== '\0' || i == 0))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_move_left(char *piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			piece[i - 1] = '#';
			piece[i] = '.';
		}
		i++;
	}
	return (piece);
}

int		ft_right_movable(char *piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#' && (piece[i + 1] == '\n' || piece[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_move_right(char *piece, int map_size)
{
	int i;

	i = ((map_size + 1) * map_size) + 1;
	while (i >= 0)
	{
		if (piece[i] == '#')
		{
			piece[i + 1] = '#';
			piece[i] = '.';
		}
		i--;
	}
	return (piece);
}
