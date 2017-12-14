/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:37:24 by rdurst            #+#    #+#             */
/*   Updated: 2017/12/14 04:06:10 by rdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <fcntl.h>

# define BUFSIZE 4096

typedef struct		s_piece
{
	char			letter;
	char			*piece;
	struct s_piece	*next;
}					t_piece;

void				ft_replace(t_piece *tmp, int a);
void				ft_move_topleft(char *piece, int a);
char				*ft_new_map(int size);
char				*ft_get_next_line(char *piece);
char				*ft_fill_map(char *map, char *piece, char c);
int					ft_move(char *str, int a);
char				*ft_newmap(void);
int					ft_can_be_placed(char *str, char *end, int map_size);
void				ft_place(char *str, char *end, char c);
int					ft_main_solver(t_piece *piece, char *end, int a);
char				*ft_read_file(char *file, char *buf);
int					ft_check_error(char *pieces);
void				ft_error(void);
t_piece				*ft_newpiece(char *pieces, char letter);
int					ft_check_piece(char *piece);
int					ft_check_count(char *piece, int size);
int					ft_check_pieces(char *pieces);
int					ft_checks(char *pieces);
t_piece				*ft_createlist(void);
t_piece				*ft_pieceslist(char *pieces);
char				*ft_move_left(char *piece);
int					ft_left_movable(char *piece);
char				*ft_move_top(char *piece, int map_size);
int					ft_top_movable(char *piece, int map_size);
char				*ft_move_right(char *piece, int map_size);
int					ft_right_movable(char *piece);
char				*ft_move_bot(char *piece, int map_size);
int					ft_bot_movable(char *piece, int map_size);
int					ft_count_pieces(t_piece *pieces);
int					ft_sqrt(int nb);
int					ft_find_sqrt(int nb);
int					ft_count_endl(char *pieces);

#endif
