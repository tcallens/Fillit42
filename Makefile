# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdurst <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 14:58:58 by rdurst            #+#    #+#              #
#    Updated: 2018/01/25 17:49:22 by tcallens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m

SRCS = ./srcs/main.c		\
	   ./srcs/functions.c	\
	   ./srcs/checks.c		\
	   ./srcs/line_moves.c	\
	   ./srcs/side_moves.c	\
	   ./srcs/solver.c		\
	   ./srcs/functions_solver.c	\
	   ./srcs/map.c			\
	   ./srcs/rodeur.c		\

INCS = -I ./includes
LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	@cd libft && make re && cd ../
	$(CC) $(CFLAGS) $(INCS) $(LIB) $(SRCS) -o $(NAME)

clean:
	@cd libft && make fclean && cd ../

fclean:
	$(RM) $(NAME)
	@cd libft && make fclean && cd ../

re: fclean clean all
