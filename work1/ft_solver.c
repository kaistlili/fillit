/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/31 15:49:00 by ktlili           ###   ########.fr       */
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

int	ft_placenext(unsigned int *base, unsigned int *bitmap)
{
	int i;
	int j;

	i = 1;
	j = 0;

	while ((i < 9) && (ft_valid(base, bitmap) == 0))
	{
		j = i;
		while ((j > 0) && (ft_valid(base, bitmap) == 0))
		{
			ft_shiftright(bitmap);
			j--;
		}

		j = i;
		while (j > 0 && ft_valid(base, bitmap) == 0)
		{
			ft_shiftdown(bitmap);
			j--;
		}
			j = i;
		while ((j > 0) && (ft_valid(base, bitmap) == 0))
		{
			ft_shiftup(bitmap);
			j--;
		}
		j = i;
		while ((j > 0) && (ft_valid(base, bitmap) == 0))
		{
			ft_shiftleft(bitmap);
			j--;
		}
		i++;
	}
	if (ft_valid(base, bitmap))
	{
		ft_overlap(base, bitmap);
		return (1);
	}
	return (0);
}


int	ft_square(unsigned int *bitmap)
{
	int i;
	int square;

	i = 0;
	square = 0;
	while (i < 
}

int	ft_solver(unsigned char *tetri, int size)
{
	int i;
	int j;
	unsigned int **bitmaparr;

	bitmaparr = ft_tobitmap(tetri, size);

	i = 1;
	while (i < size)
	{
		ft_placenext(bitmaparr[0], bitmaparr[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		ft_showbitmap(bitmaparr[i]);
		ft_putchar('\n');
		i++;
	}
	ft_showbitmap(bitmaparr[0]);
	return (1);
}

