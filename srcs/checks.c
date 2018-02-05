/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:24:37 by rdurst            #+#    #+#             */
/*   Updated: 2018/01/29 18:36:12 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i < 20 && str[i + 1] == '#')
				block++;
			if (i > 0 && str[i - 1] == '#')
				block++;
			if (i < 15 && str[i + 5] == '#')
				block++;
			if (i > 4 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	if (block == 6 || block == 8)
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

int		check_counts(char *str)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (check_connection(str) == 0)
		return (5);
	if (blocs < 4)
		return (6);
	if (str[20] != '\n' && str[20] == '\0')
		return (4);
	return (0);
}

int		ft_check_pieces(char *pieces)
{
	int num;

	num = 0;
	while (num == 0)
	{
		num = check_counts(pieces);
		if (num != 0 && num != 4)
			ft_error();
		if (num == 4)
			return (1);
		pieces += 21;
	}
	return (1);
}

int		ft_checks(char *pieces)
{
	if (ft_check_pieces(pieces) == 1)
		return (1);
	return (0);
}
