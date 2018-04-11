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

int ft_comparetetri(unsigned short *tetri1, unsigned short *tetri2)
{
	int i;

	i = 0;

	while (i < 12)
	{
		if (tetri1[i] ^ tetri2[i] == 0)
			i++;
		else
			i = 99;
	}
	if (i == 99)
		return (0);
	return (1);
}

void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
}




int	solve(unsigned short tetri[26][13],int *square, int index)
{
	int currentline;
	int j;

	g_recursivecall++;
	if (tetri[index][0] == 27)
	{
		ft_printorderbitmap(tetri);
		*square = ft_square(tetri[25][13]);
		printf("job done %d times.\n", %d g_recursivecalls);
		return (1);
	}
	j = 1;
	currentline = 0;
	while ((currentline < *square) && (ft_checkborder(&tetri[index][1])))
	{
		while (j == 1) && (ft_checkborder(&tetri[index][1]))
		{
			if (ft_place(&tetri[25][1], &tetri[index][1], *square, &j))	
			{
				solve(tetri, square, index + 1);
				ft_removetetri(&tetri[index][1], &tetri[25][1]);
			}
			ft_shiftright(&tetri[index][1]);	
		}
		j = 1
		ft_sortnextline(&tetri[index][1]);
		currentline++;	
	}
	return (0);

}




int	ft_solvecomb(unsigned short tetri[26][13], int index, int *square)
{

	int len;
	int i;
	int currentline;

	if (tetri[0][0] == 27)
	{
		return (0);
	}
	len = ft_length(&tetri[25][1]);
	currentline = 0;
	while (currentline < *square)
	{
		i = 1;
	/*	printf("current line is: %d index is: %d trying until: %d\n", currentline, index, *square);
	*/	while ((i == 1) & (ft_checkborder(&tetri[index][1])))
		{
			
/*			if ((tetri[0][0] == 'A') & (currentline == 1) && (index == 0))
			{
				ft_putstr("****************\n");
				ft_printorderbitmap(tetri);
				ft_printbitmap(&tetri[25][1]);
				ft_putstr("****************\n");
			}*/
			if (ft_validbitmap(&tetri[25][1], &tetri[index][1]))
			{
				ft_overlap(&tetri[index][1], &tetri[25][1]);
				if (ft_square(&tetri[25][1]) < *square)
				{
					ft_solvecomb(tetri, index + 1, square);
				}
				else
				{
					i = 0;
				}
				ft_removetetri(&tetri[index][1], &tetri[25][1]);
			}
			ft_shiftright(&tetri[index][1]);
		}
	
	/*	printf("tried %c on line %d\n", tetri[index][0], currentline);
	*/	ft_sortnextline(&tetri[index][1]);
		
		currentline++;
	}
/*	ft_removetetri(&tetri[index][1], &tetri[25][1]);
*/	ft_sortbitmap(&tetri[index][1]);
}

