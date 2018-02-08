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

int	g_square = 0;

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
int ft_solve(unsigned int tetri[26][5])
{
	
}
int	ft_permute(unsigned char tetri[26][5], int size, int n)
{
	int i;

	i = 0;
	if (size == 1)
	{
		ft_solve(tetri[26][5])
	}
	




}
