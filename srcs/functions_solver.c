/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:36:28 by tcallens          #+#    #+#             */
/*   Updated: 2017/12/14 02:41:50 by rdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_can_be_placed(char *str, char *end, int map_size)
{
	int a;
	int counter;

	counter = 0;
	a = 0;
	while (end[a])
	{
		if (str[a] == '#')
			counter++;
		a++;
	}
	if (str[a] == '#')
		counter++;
	if (counter != 4)
		return (0);
	a = 0;
	while (a < (map_size + 1) * map_size)
	{
		if ((str[a] != '.' && end[a] != '.')
				&& (str[a] != '\n' && end[a] != '\n'))
			return (0);
		a++;
	}
	return (1);
}

void	ft_place(char *str, char *end, char c)
{
	int		a;

	a = 0;
	while (a < 20)
	{
		if (end[a] == '.' && str[a] == '#')
			end[a] = c;
		a++;
	}
}

int		ft_move(char *str, int a)
{
	if (ft_right_movable(str) == 1)
	{
		str = ft_move_right(str, a);
		return (1);
	}
	if (ft_right_movable(str) == 0 && ft_bot_movable(str, a) == 1)
	{
		while (ft_left_movable(str) == 1)
			str = ft_move_left(str);
		if (ft_bot_movable(str, a))
			str = ft_move_bot(str, a);
		return (1);
	}
	return (0);
}
