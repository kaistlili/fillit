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

int ft_trailingzero(unsigned short data)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 16) 
	{
		if ((data >> i) & 1)
			i = 100;
		else
			count++;
	}
	return (count);
}

int ft_square(unsigned short *bitmap)
{
	int length;
	int width;
	int i;

	i = 0;
	length = 0;
	width = 0;
	while (bitmap[length] != 0)
	{
		if (ft_trailingzero(bitmap[length]) > width)
			width = ft_trailingzero(bitmap[length]);
		length++;
	}
	if (width >= length)
		return (width);
	return (length);
	
}

int ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2)
{
	int i;

	i = 0;
	while (((bitmap1[i] & bitmap2[i]) == 0) & (i < 13))
		i++;
	if (i != 13)
		return (0);
	return (1);
}

void ft_overlap(unsigned short *from, unsigned short *to)
{
	int i;

	i = 0;
	while (i < 12)
	{
		to[i] = from[i] | to[i];
		i++;
	}
}

int ft_validplace(unsigned short tetri[26][13], int index, int pos)
/*return 100 if overlap is invalid, return square if valid;*/
{
	unsigned short temp;
	int square;

	temp = tetri[0][pos + 1];
	while (temp != 0)
	{	
		ft_shiftright(&tetri[index][1]);
		temp = temp << 1;
	}
	while (!ft_validbitmap(&tetri[0][1],  &tetri[index][1]))
	{
		ft_shiftright(&tetri[index][1]);
	}
	ft_overlap(&tetri[index][1], &tetri[0][1]);
	square = ft_square(&tetri[0][1]);
	return (square);

}
int ft_length(unsigned short *bitmap)
{
	int len;

	len = 1;
	while (bitmap[len] != 0)
		len++;
	return (len);
}
void	ft_place(unsigned short tetri[26][13],int index, int pos, int square)
{
	int temp;
	int len;

	if (tetri[index][0] == 27)
	{
		if (ft_square(&tetri[0][1]) < square);
			square = ft_square(&tetri[0][1]);
		printf("done, square is: %d\n", square);
		return;
	}
	printf("here\n");
	len = ft_length(&tetri[0][1]);
	while (pos < len)
	{
		temp = ft_validplace(tetri, index, pos);
		printf("ft_validplace return is: %d\n", temp);
		if (temp < square)
		{
			ft_place(tetri, index + 1, 0, square);
		}
		pos++;
	}
}

void	ft_permutation(unsigned short tetri[26][13], int start, int end, int square)
{
	int	i;
	int j;
	
	/*printf("call. start: %d\n", start);*/
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
/*			ft_putstr("backtrack i is-");
			ft_putnbr(i);
			putchar('\n');*/
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
