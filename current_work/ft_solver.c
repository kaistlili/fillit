/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/09 20:13:30 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>


int	ft_placable(unsigned short *bitmap, unsigned short *tetri, int square, int *j)
{
	if (ft_validbitmap(bitmap, tetri)) 
	{
		ft_overlap(tetri, bitmap); 
		if (ft_square(bitmap) < square)
			return(ft_square(bitmap));
		else
		{
			*j = 0;
			
            ft_removetetri(tetri, bitmap);
			return (0);
		}	
	}
	else
		return (-1);
}

// we can ditch the J variable by breaking loop when ft_square(tetri[index]) > *square
int solve(unsigned short tetri[26][13],int *square, int index)
{
	int currentline;
	int j;
	int decision;

	g_recursivecalls++;
	if (tetri[index][0] == 27)
	{
		if (ft_square(&tetri[25][1]) < *square)
		{
			*square = ft_square(&tetri[25][1]);
			printf("solved. new square is: %d\n", *square);
			ft_printorderbitmap(tetri, *square);
			return (1);
		}
		return (0);
	} 
	j = 1;
	currentline = 0;
	while ((currentline < *square) && (ft_checkborder(&tetri[index][1])))
	{
		while ((j == 1) && (ft_checkborder(&tetri[index][1])))
		{
	/*	
			printf("trying tetri %d\n", index);
			ft_printbitmap(&tetri[index][1]);
			printf("on bitmap\n");
			ft_printbitmap(&tetri[25][1]);
		*/	decision = ft_placable(&tetri[25][1], &tetri[index][1], *square, &j);
			

			if ((decision  < *square) & (decision > 0))
			{
                 
				 solve(tetri, square, index + 1);
				 ft_removetetri(&tetri[index][1], &tetri[25][1]);
            }
            ft_shiftright(&tetri[index][1]);
         }
         j = 1;
         ft_sortnextline(&tetri[index][1]);
         currentline++;
     }
	 ft_sortbitmap(&tetri[index][1]);
	 return (0);
}

