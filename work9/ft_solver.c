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

void	ft_solvecomb(unsigned short tetri[26][13], int index, int *square)
{

	int len;
	int i;
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
		/*	ft_printbyorder(tetri);
	*/	}
		return ;
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

void	ft_permutation(unsigned short tetri[26][13], int start, int end, int *square)
{
	int i;
	int j;
	int currentline;


	j = 1;
	g_recursivecalls++;
	if (start > end)
	{
		if (ft_square(&tetri[25][1]) < *square )
		{
			*square = ft_square(&tetri[25][1]);
			printf("solution found square is: %d\n", *square);	
			ft_printorderbitmap(tetri);
			ft_putstr("\n--------------------------------------\n");
	/*		ft_printbyorder(tetri);*/
		}
		else
			printf("solution not found.\n");
	}
	else
	{
		i = start;
		while (i <= end)
		{
			
			currentline = 0;
			while (currentline < *square)
			{
				while ((j == 1) & (ft_checkborder(&tetri[start][1])))
				{
					printf("trying %d last sqr: %d\n", i, *square);
					ft_printbitmap(&tetri[i][1]);
					printf("on\n");	
					ft_printbitmap(&tetri[25][1]);
					if (ft_validbitmap(&tetri[25][1], &tetri[i][1]))
					{
						ft_overlap(&tetri[i][1], &tetri[25][1]);
						if (ft_square(&tetri[25][1]) < *square)
						{
							printf("\tswapping %d with i: %d", start, i);
							ft_swapbitmap(tetri[start], tetri[i]);
							ft_permutation(tetri, start + 1, end, square);
							ft_swapbitmap(tetri[start], tetri[i]);
							printf("returned swapping %d with i: %d\n", start, i);
						}
						else
							j = 0;
						ft_removetetri(&tetri[i][1], &tetri[25][1]);
					}
					printf("shifting right\n");
					ft_shiftright(&tetri[i][1]);
				}
				j = 1;
				printf("\tgetting next line\n");
				ft_sortnextline(&tetri[i][1]);
				currentline++;
			}
			printf("****\t*sorting %d\n",i);
			ft_sortbitmap(&tetri[i][1]);
			i++;			
		}
	}
}
