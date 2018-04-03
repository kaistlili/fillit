/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/04 18:59:16 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

unsigned short **ft_solver(unsigned short tetri[26][13], int start, int end, int *square)
{
	int i;

	if (start == end)
	{
		/*print all, copy current combination into mallocced array return pointer*/
	}
	else
	{
		i = start;
		while (i <= end)
		{
			ft_swapbitmap(tetri[start], tetri[i])

			ft_solver(tetri, start + 1, end, square);
			swapbitmap(tetri[start],tetri[i]);
			i++;
		}
	}
	
}
