/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:36:28 by tcallens          #+#    #+#             */
/*   Updated: 2017/12/07 04:12:33 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_move_topleft(char *piece, int a)
{
	while (ft_left_movable(piece) == 1)
		ft_move_left(piece);
	while (ft_top_movable(piece, a) == 1)
		ft_move_top(piece, a);
}

void	ft_move_botright(char *piece, int a)
{
	while (ft_right_movable(piece))
		ft_move_right(piece, a);
	while (ft_bot_movable(piece, a))
		ft_move_bot(piece, a);
}

int		ft_main_solver(t_piece *p, char *end, int a)
{
	char	*secours;
	int		b;

	b = 0;
	if (p == NULL)
		return (1);
	secours = ft_new_map(a);
	ft_strcpy(secours, end);
	while ((ft_bot_movable(p->piece, a) == 1
				|| ft_right_movable(p->piece) == 1) || b == 1)
	{
		if (ft_check_count(ft_fill_map(ft_new_map(a), p->piece, '#'), a) != 4)
			return (0);
		b > 1 ? ft_move(p->piece, a) : 0;
		if (ft_can_be_placed(p->piece, end, a) == 1)
		{
			ft_fill_map(end, p->piece, p->letter);
			if (ft_main_solver(p->next, end, a))
				return (1);
			ft_move_topleft(p->next->piece, a);
			ft_strcpy(end, secours);
		}
		b++ == 0 ? ft_move(p->piece, a) : 0;
	}
	return (0);
}
