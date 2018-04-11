/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/29 18:51:41 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

unsigned int	**ft_tobitmap(unsigned char *tetri, int size)
{
	int i;
	int j;
	unsigned int **bitmaparr;

	bitmaparr = malloc(size * sizeof(*bitmaparr));
	i = 0;
	j = 0;	
	while ((i) < size)
	{
		bitmaparr[i] = malloc(16 * sizeof(unsigned int));
		ft_bzero(bitmaparr[i], 16 * 4);
		while (j  < 4 )
		{
			bitmaparr[i][j] = tetri[j + (i*4)];
		    j++;
		}
		j = 0;
		ft_sortbitmap(bitmaparr[i]);	
		i++;
	}
	
	return (bitmaparr);

}

int	ft_valid(unsigned int *bitmap1, unsigned int *bitmap2)
{
	int i;

	i = 0;
	while  (((bitmap1[i] & bitmap2[i]) == 0) & (i < 15))
		i++;
	if (i != 15)
	   return(0);
	return (1);
}

void	ft_overlap(unsigned int *bitmap1, unsigned int *bitmap2)
{
	int i;

	i = 0;
	while (i < 15)
	{
		bitmap1[i] = bitmap1[i] | bitmap2[i] ;
		i++;
	}
}
/*
int	ft_placenext(unsigned int *base, unsigned int *bitmap)
{
	if (ft_valid(base, bitmap))
	{
		ft_overlap(base, bitmap);
		return (1);
	}
	while (!ft_valid(base, bitmap))
	{
		ft_shiftright(bitmap)
			
	}
	return (0);
}
*/
int	ft_solver(unsigned char *tetri, int size)
{
	int i;
	int j;
	unsigned int **bitmaparr;

	bitmaparr = ft_tobitmap(tetri, size);
	i = 2;
	j = 0;
	while (j < (size - 1))
	{
		ft_showbitmap(bitmaparr[0]);	
		ft_putchar('\n');
		while ((!ft_valid(bitmaparr[0], bitmaparr[j + 1])) && i < 20 )
		{
			if (i % 2 == 0)		
			{
				ft_shiftright(bitmaparr[j + 1]);
				if (ft_valid(bitmaparr[0], bitmaparr[j + 1]))
					i = -2;
				else
					ft_shiftleft(bitmaparr[j + 1]);
			}	
			else
			{
				ft_shiftdown(bitmaparr[j + 1]);
				if (ft_valid(bitmaparr[0], bitmaparr[j + 1]))
					i = -2;
				else
					ft_shiftup(bitmaparr[j + 1]);
			}	
			i++;
		}
		i = 2;
		ft_overlap(bitmaparr[0], bitmaparr[j + 1]);
		j++;
		
	}
	ft_putstr("final is: \n");
	ft_showbitmap(bitmaparr[0]);	
	ft_putchar('\n');
	
	/*i = 0;
	while (i < size)
	{
		i++;
	}*/
	return (1);
}

