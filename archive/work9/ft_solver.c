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
			return (0);
	}
	return (1);
}

void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
}

int should_swap(unsigned short tetri[26][13], int start, int curr, int n)
{
	int i;

	i = start;
	while (i < curr)
	{	
		if (ft_comparetetri(&tetri[i][1], &tetri[curr][1]))
		{
			printf("should not swap\n");
			return (0);
		}
	}
	return (1);
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
			while ((/*(ft_square(&tetri[i][1])*/ currentline < *square) & (ft_checkborder(&tetri[i][1])))
			{
//				printf("Trying index: %d on line %d\r", i, currentline);
				while ((j == 1) & (ft_checkborder(&tetri[i][1])))
				{
		//			printf("trying %d last sqr: %d\n", i, *square);
		//			ft_printbitmap(&tetri[i][1]);
		//			printf("on\n");	
		//			ft_printbitmap(&tetri[25][1]);
					if (ft_validbitmap(&tetri[25][1], &tetri[i][1]))
					{
						ft_overlap(&tetri[i][1], &tetri[25][1]);
						if (ft_square(&tetri[25][1]) < *square)/* & (should_swap(tetri, start, i, end)))*/
						{
		//					printf("\tswapping %d with i: %d", start, i);
							ft_swapbitmap(tetri[start], tetri[i]);
							ft_permutation(tetri, start + 1, end, square);
							ft_swapbitmap(tetri[start], tetri[i]);
		//					printf("returned swapping %d with i: %d\n", start, i);
						}
						else
							j = 0;
						ft_removetetri(&tetri[i][1], &tetri[25][1]);
					}
		//			printf("shifting right\n");
					ft_shiftright(&tetri[i][1]);
				}
				j = 1;
		//		printf("\tgetting next line\n");
				ft_sortnextline(&tetri[i][1]);
				currentline++;
			}
		//	printf("****\t*sorting %d\n",i);
			ft_sortbitmap(&tetri[i][1]);
			i++;			
		}
	}
}
