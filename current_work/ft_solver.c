/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/15 07:57:12 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	ft_placable(unsigned short *bitmap, unsigned short *tetri, int square)
{
	if (ft_validbitmap(bitmap, tetri))
	{
		ft_overlap(tetri, bitmap);
		if (ft_square(bitmap) < square)
			return (1);
		else
		{
			ft_removetetri(tetri, bitmap);
			return (0);
		}
	}
	else
		return (0);
}

int	solve(unsigned short tetri[28][17], int *square, int index, char solution[17][17])
{
	int currentline;

	if (tetri[index][0] == 27)
	{
		if (ft_square(&tetri[26][1]) < *square)
			ft_save_solution(tetri, square, solution);
		return (1);
	}
	currentline = 0;
	while ((currentline < *square) && (ft_checkborder(&tetri[index][1])))
	{
		while ((ft_square(&tetri[index][1]) < *square) && (ft_checkborder(&tetri[index][1])))
		{
			if ((ft_placable(&tetri[26][1], &tetri[index][1], *square) > 0))
			{
				solve(tetri, square, index + 1, solution);
				ft_removetetri(&tetri[index][1], &tetri[26][1]);
			}
			ft_shiftright(&tetri[index][1]);
		}
		ft_sortnextline(&tetri[index][1]);
		currentline++;
	}
	ft_sortbitmap(&tetri[index][1]);
	return (0);
}
