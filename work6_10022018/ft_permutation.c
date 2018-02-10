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
			ft_putstr("i is:");
			ft_putnbr(i);
			ft_putstr("\n");
			ft_swapbitmap(tetri[start], tetri[i]);
			ft_permutation(tetri, start + 1, end, square);
			ft_putstr("backtrack i is-");
			ft_putnbr(i);
			putchar('\n');
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
