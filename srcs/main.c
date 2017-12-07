/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:01:10 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/07 03:52:13 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*motor(t_piece *list)
{
	char	*end;
	int		a;
	t_piece	*tmp;

	a = 2;
	end = ft_new_map(a);
	while (ft_main_solver(list, end, a) != 1)
	{
		tmp = list;
		ft_move_topleft(list->piece, a);
		a++;
		end = ft_new_map(a);
		while (tmp)
		{
			if (ft_check_count(ft_fill_map(ft_new_map(a), tmp->piece, '#'), a)
					== 4)
				tmp->piece = ft_fill_map(ft_new_map(a), tmp->piece, '#');
			tmp = tmp->next;
		}
	}
	return (end);
}

int		main(int ac, char **av)
{
	char	pieces[BUFSIZE + 1];
	t_piece	*list;

	if (ac == 2)
	{
		ft_read_file(av[1], pieces);
		if (ft_checks(pieces) == 1 && *pieces != '\0')
		{
			list = ft_pieceslist(pieces);
			list = list->next;
			ft_putstr(motor(list));
		}
		else
			ft_error();
	}
	else
		ft_error();
}
