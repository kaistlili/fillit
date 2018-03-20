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


void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
}


void	ft_permutation(unsigned short tetri[26][13], int start, int end, int *square)
{








}


void	ft_solvecomb(unsigned short tetri[26][13], int index, int *square)
{

	int len;
	int currentline;

	if (tetri[index][0] == 27)
	{
		if (ft_square(&tetri[25][1]  < *square))
		{
			printf("solution found:\n");
			ft_printbitmap(&tetri[25][1]);
			ft_putstr("\n--------------------------------------\n");
			ft_printbyorder(tetri);
		}
		return ;
	}
	len = ft_length(&tetri[25][1]);
	currentline = 0;
	while (currentline <= len)
	{
		while (ft_checkborder(&tetri[index][1]))
		{
			if (ft_validbitmap(&tetri[25][1], &tetri[index][1]))
			{
				ft_overlap(&tetri[index][1], &tetri[25][1]);
				if (ft_square(&tetri[25][1]) < *square)
				{
					ft_solvecomb(tetri, index + 1, square);
				}
				ft_removetetri(&tetri[index][1]);
			}
			ft_shiftright(&tetri[index][1]);
		}
		ft_sortnextline(&tetri[index][1]);
		currentline++;
	}

}
