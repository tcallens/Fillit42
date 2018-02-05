/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:00 by rdurst            #+#    #+#             */
/*   Updated: 2018/01/25 18:30:12 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_read_file(char *file, char *buf)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		read(fd, buf, BUFSIZE);
		buf[BUFSIZE] = '\0';
		close(fd);
	}
	else
		ft_error();
	if (ft_strlen(buf) > 545)
		ft_error();
	return ((char *)buf);
}

void		ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

t_piece		*ft_createlist(void)
{
	t_piece *piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->piece = NULL;
	piece->letter = '\0';
	piece->next = NULL;
	return (piece);
}

t_piece		*ft_newpiece(char *pieces, char letter)
{
	t_piece *piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->piece = (char *)malloc(sizeof(char) * 20);
	ft_strncpy(piece->piece, pieces, 19);
	while (ft_left_movable(piece->piece))
		ft_move_left(piece->piece);
	while (ft_top_movable(piece->piece, 4))
		ft_move_top(piece->piece, 4);
	piece->piece[19] = '\0';
	piece->letter = letter;
	return (piece);
}

t_piece		*ft_pieceslist(char *pieces)
{
	char	letter;
	t_piece	*piece;
	t_piece	*begin;

	letter = 'A';
	piece = ft_createlist();
	begin = piece;
	while (*pieces)
	{
		piece->next = ft_newpiece(pieces, letter++);
		piece = piece->next;
		pieces += 21;
	}
	piece->next = NULL;
	return (begin);
}
