/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:13:13 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/07 03:14:36 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_top_movable(char *piece, int map_size)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (i < map_size + 1 && piece[i] == '#')
			return (0);
		if (piece[i] == '#' && (piece[i - (map_size + 1)] == '\n'
					|| piece[i - (map_size + 1)] == '\0'
					|| piece[i - 1] == '\0'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_move_top(char *piece, int map_size)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			piece[i - (map_size + 1)] = '#';
			piece[i] = '.';
		}
		i++;
	}
	return (piece);
}

int		ft_bot_movable(char *piece, int map_size)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (i > ((int)ft_strlen(piece) - map_size + 1) && piece[i] == '#')
			return (0);
		if (piece[i] == '#' && (piece[i + (map_size + 1)] == '\n'
					|| piece[i + (map_size + 1)] == '\0'
					|| piece[i + 1] == '\0'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_move_bot(char *piece, int map_size)
{
	int i;

	i = ((map_size + 1) * map_size) + 1;
	while (i >= 0)
	{
		if (piece[i] == '#')
		{
			piece[i + (map_size + 1)] = '#';
			piece[i] = '.';
		}
		i--;
	}
	return (piece);
}
