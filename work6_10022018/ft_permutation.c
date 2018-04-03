/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:13:38 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/09 10:41:57 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_swapbitmap(unsigned short *bitmap1, unsigned short *bitmap2)
{
	int i;
	unsigned short temp;

	i = 0;
	while (i < 13)
	{
		temp = bitmap1[i];
		bitmap1[i] = bitmap2[i];
		bitmap2[i] = temp;
		i++;
	}
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


#include <stdio.h>
void	ft_permutation(unsigned short tetri[26][13], int start, int end, int square)
{
	int	i;
	int j;
	

	j = 0;
	if (start == end)
	{
		while (tetri[j][0] != 27)
		{
			ft_putchar(tetri[j][0] + 65);
			ft_putchar('-');
			j++;
		}
		j = 0;
		ft_putstr("|\n");
	}
	else
	{
		i = start;
		while(i <= end)
		{
			if (ft_comparetetri(&tetri[start][1], &tetri[i][1]))
			
			printf("tetri %d and %d are the same\n", start, i);
			else
			
				printf("tetri %d and %d are not the same\n", start, i);
			ft_swapbitmap(tetri[start], tetri[i]);
			ft_permutation(tetri, start + 1, end, square);
			ft_swapbitmap(tetri[start], tetri[i]);
			i++;
		}
	}

}

void	ft_heap_permutation(unsigned short tetri[26][13], int size, int square)
{
	int i;
	int j;

	j = 0;
	if (size == 1)
	{
		while (tetri[j][0] != 27)
		{
			ft_putchar(tetri[j][0] + 65);
			ft_putchar('-');
			j++;
		}
		j = 0;
		ft_putchar('|');
		return;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr("\nloop\n");
		ft_putchar(tetri[size-1][0] + 65);
		ft_putstr("\n\n");
		ft_heap_permutation(tetri, size - 1, square);
		if (size % 2 == 1)
			ft_swapbitmap(tetri[0], tetri[size - 1]);
		else
			ft_swapbitmap(tetri[i], tetri[size - 1]);
		i++;
	}
}
