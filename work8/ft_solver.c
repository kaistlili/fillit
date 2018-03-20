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

void	ft_solvecomb(unsigned short tetri[26][13], int index, int *square)
{

	int len;
	int currentline;

	if (tetri[index][0] == 27)
	{
		if (ft_square(&tetri[25][1])  < *square)
		{
			*square = ft_square(&tetri[25][1]);
			printf("solution found square is: %d\n", *square);
			/*ft_printbitmap(&tetri[25][1]);
			*/
			ft_printorderbitmap(tetri);
			ft_putstr("\n--------------------------------------\n");
			ft_printbyorder(tetri);
		}
		return ;
	}
	len = ft_length(&tetri[25][1]);
	currentline = 0;
	while ((currentline - len) < 2)
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
				ft_removetetri(&tetri[index][1], &tetri[25][1]);
			}
			ft_shiftright(&tetri[index][1]);
		}
		ft_sortnextline(&tetri[index][1]);
		currentline++;
	}
	ft_sortbitmap(&tetri[index][1]);
}

void ft_printcombination(unsigned short tetri[26][13])
{
	int i;

	i = 0;
	while (tetri[i][0] != 27)
	{
		ft_putchar(tetri[i][0]);
		ft_putchar('-');
		i++;
	}
	ft_putchar('\n');

}
void	ft_permutation(unsigned short tetri[26][13], int start, int end, int *square)
{
	int i;

	if (start == end)
	{
	/*	printf("combination constructed, solving...");
	*/	/*ft_printcombination(tetri);*/
		ft_memcpy(&tetri[25][1], &tetri[0][1], 24);
		ft_solvecomb(tetri, 1, square);
	}
	else
	{
		i = start;
		while (i <= end)
		{
			ft_swapbitmap(tetri[start], tetri[i]);
			ft_permutation(tetri, start + 1, end, square);
			ft_swapbitmap(tetri[start], tetri[i]);
			i++;
		}

	}
}
