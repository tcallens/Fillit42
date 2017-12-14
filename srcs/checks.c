/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:24:37 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/14 04:09:46 by rdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_piece(char *piece)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (i < 20)
	{
		if (piece[i] == '#')
		{
			if (piece[i + 1] == '#')
				counter++;
			if (piece[i - 1] == '#')
				counter++;
			if (i < 15 && piece[i + 5] == '#')
				counter++;
			if (i > 4 && piece[i - 5] == '#')
				counter++;
		}
		i++;
	}
	if (counter == 8 || counter == 6)
		return (1);
	return (0);
}

int		ft_check_count(char *piece, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < ((size + 1) * size))
	{
		if (piece[i] == '#')
			count++;
		i++;
	}
	return (count);
}

int		ft_check_error(char *pieces)
{
	if (ft_count_endl(pieces) == 0)
		return (0);
	while (*pieces)
	{
		if (pieces[4] == '\n' && pieces[9] == '\n' && pieces[14] == '\n'
				&& pieces[19] == '\n')
		{
			if (pieces[20] == '\n' && (pieces[21] == '.' || pieces[21] == '#'))
				return (1);
			else
			{
				if (pieces[20] == '\0')
					return (2);
				else
					return (0);
			}
		}
		else
			return (0);
	}
	return (1);
}

int		ft_check_pieces(char *pieces)
{
	if (*pieces == '\0')
		return (1);
	if (ft_check_piece(pieces) == 1 && ft_check_count(pieces, 4) == 4)
	{
		if (ft_check_error(pieces) == 1)
			return (ft_check_pieces(pieces + 21));
		else if (ft_check_error(pieces) == 2)
			return (ft_check_pieces(pieces + 20));
		else
			return (0);
	}
	else
		return (0);
}

int		ft_checks(char *pieces)
{
	int i;

	i = 0;
	while (pieces[i])
	{
		if (pieces[i] != '\n' && pieces[i] != '#' && pieces[i] != '.')
			return (0);
		i++;
	}
	if (ft_check_pieces(pieces) == 1)
		return (1);
	return (0);
}
