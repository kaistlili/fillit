/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:00:12 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 16:00:19 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(unsigned short tetri[28][17],
			int *square, int index, char solution[17][17])
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
		while (ft_square(&tetri[index][1]) < *square)
		{
			if ((ft_placeable(&tetri[26][1], &tetri[index][1], *square) > 0))
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

int		ft_placeable(unsigned short *bitmap, unsigned short *tetri, int square)
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

void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
}

int		ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2)
{
	int i;

	i = 0;
	while (((bitmap1[i] & bitmap2[i]) == 0) & (i < 12))
		i++;
	if (i != 12)
		return (0);
	return (1);
}

void	ft_overlap(unsigned short *from, unsigned short *to)
{
	int i;

	i = 0;
	while (i < 12)
	{
		to[i] = from[i] | to[i];
		i++;
	}
}
