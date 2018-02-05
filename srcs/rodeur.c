/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:21 by tcallens          #+#    #+#             */
/*   Updated: 2018/01/25 17:56:54 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		check_endlines(char *rodeur)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (rodeur[i] == '\n')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}
