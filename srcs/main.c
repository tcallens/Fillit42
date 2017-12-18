/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:01:10 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/18 17:11:36 by rdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_replace(t_piece *tmp, int a)
{
	while (tmp)
	{
		if (ft_check_count(ft_fill_map(ft_new_map(a), tmp->piece, '#'), a)
				== 4)
			tmp->piece = ft_fill_map(ft_new_map(a), tmp->piece, '#');
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		return (0);
	while ((i * i) <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int		ft_find_sqrt(int nb)
{
	while (ft_sqrt(nb) == 0)
		nb++;
	return (ft_sqrt(nb));
}

char	*motor(t_piece *list)
{
	char	*end;
	int		a;
	t_piece	*tmp;

	tmp = list;
	if (ft_count_pieces(list) == 0)
		a = 2;
	else
		a = ft_find_sqrt(ft_count_pieces(list));
	while (ft_replace(tmp, a) == 0)
		ft_replace(tmp, a++);
	end = ft_new_map(a);
	while (ft_main_solver(list, end, a) != 1)
	{
		ft_move_topleft(list->piece, a);
		a++;
		end = ft_new_map(a);
		ft_replace(tmp, a);
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
		ft_putendl("usage: ./fillit [file]");
}
