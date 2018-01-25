/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/25 16:57:34 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	ft_checkmask(unsigned int *bitmap, unsigned int *mask)
{
	int i;
	int ret;

	ret = 1;
	i = 0;
	while (i < 16 && ret == 1)
	{
		if ((bitmap[i] | mask[1]) == mask[1])
			i++;
		else
			ret = 0;
	}
	return (ret);
}

void ft_shiftleft(unsigned int *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] << 1;
		i++;
	}
}

void ft_shiftright(unsigned int *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] >> 1;
		i++;
	}
}

void ft_sortbitmap(unsigned int *bitmap)
{
	unsigned int	mask[16];
	int i;

	i = 0;
	while (i < 16)
	{
		mask[i] = 2147483647;
		i++;
	}
	i = 0;
	while (ft_checkmask(bitmap, mask))
	{
		ft_shiftleft(bitmap);
	}
	while (!bitmap[0])
	{
		while (i < 15)
		{
			bitmap[i] = bitmap[i] ^ bitmap[i + 1];
			bitmap[i + 1] = bitmap [i] ^ bitmap[i + 1];
			bitmap[i] = bitmap[i] ^ bitmap[i + 1];
			i++;

		}
	}
}


unsigned int	**ft_tobitmap(unsigned char *tetri, int size)
{
	int i;
	int j;
	unsigned int **bitmaparr;

	bitmaparr = malloc(size * sizeof(*bitmaparr));
	i = 0;
	j = 0;
	ft_putstr("done\n");
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

#include <stdio.h>
int	ft_valid(unsigned int *bitmap1, unsigned int *bitmap2)
{
	int i;

	i = 0;
	while  (((bitmap1[i] & bitmap2[i]) == 0) & (i < 15))
		i++;
	printf("i is: %d\n", i);
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

int	ft_solver(unsigned char *tetri, int size)
{
	int i;
	unsigned int **bitmaparr;

	bitmaparr = ft_tobitmap(tetri, size);
	i = 0;
	while (!ft_valid(bitmaparr[0], bitmaparr[1]))
	{	
		i++;
		ft_shiftright(bitmaparr[1]);


	}
	ft_overlap(bitmaparr[0], bitmaparr[1]);
	ft_showbitmap(bitmaparr[0]);	
	ft_putchar('\n');
	
	/*i = 0;
	while (i < size)
	{
		i++;
	}*/
	return (1);

}

