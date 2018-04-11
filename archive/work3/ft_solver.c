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
/*
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
*/
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
int	ft_square(unsigned int *bitmap)
{
	int i;
	int square;

	i = 0;
	square = 0;
	while (i < 
}


int		ft_placenext(unsigned int *bitmap, unsigned int *next)
{
	int row;

	row = 0;
	while(bitmap[row] != 0)
	{
		ft_placetetri(next,
	}
}
*/
unsigned int	*ft_tobitmap(unsigned char *tetri)
{
	unsigned int *bitmap;
	int			 i;

	i = 0;
	bitmap = malloc(16 * sizeof(unsigned int));
	while (i < 4)
	{
		if (tetri[i] != 0)
			bitmap[i] = tetri[i];
		i++;		
	}
	ft_sortbitmap(bitmap);
	return (bitmap);
}
/*
void	ft_place(unsigned int *bitmap, unsigned char *tetri, int pos)
{

}*/
int	ft_permutations(t_list **tetri, int size)
{

}
int	ft_solver(t_list **tetri)
{
	unsigned int *first;
	t_list *current;
	int size;

	size = 0;
	current = *tetri;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	first = ft_tobitmap((*tetri)->content);
	
	ft_showbitmap(first);
	return (1);	
}
