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

int ft_length(unsigned short *bitmap)
{
	int len;

	len = 1;
	while (bitmap[len] != 0)
		len++;
	return (len);
}


int ft_width(unsigned short data)
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
		{
			count++;
			i++;
		}
	}

	return (16 - count);
}

int ft_square(unsigned short *bitmap)
{
	int length;
	int width;

	length = 0;
	width = 0;/*
	printf("--------square for:\n");
	ft_printbitmap(bitmap);
	printf("\n");*/
	while (bitmap[length] != 0)
	{
		if (ft_width(bitmap[length]) > width)
			width = ft_width(bitmap[length]);
		length++;
		/*printf("++length is: %d width is: %d\n", length, width);*/
	}
	if (width >= length)
		return (width);
	return (length);
	
}

int ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2)
{
	int i;

	i = 0;
	while (((bitmap1[i] & bitmap2[i]) == 0) & (i < 12))
		i++;
	if (i != 12)
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


int	ft_checkborder(unsigned short *tetri)
{
	int i;
	int counter;

	i = 0;
	counter = 1;

	while ((i < 12) & (counter))
	{
		
		if (tetri[i] & 1)
		{
			
			counter = 0;
		}
		i++;
	}
	if (counter == 1)
		return (counter);
	return (0);
}

int ft_validplace(unsigned short tetri[26][13], int index, int line)
/*return 100 if overlap is invalid, return square if valid;*/
{
	unsigned short temp;
	int square;
	int counter;
/*
	temp = tetri[0][pos + 1];
	counter = 0;
	while (temp != 0)
	{	
		counter++;
		ft_shiftright(&tetri[index][1]);
		temp = temp << 1;
	}
	printf("---shifted %d times\n", counter);
	*/
	counter = 0;
	temp = line;
	while (temp > 0)
	{
		ft_shiftdown(&tetri[index][1]);
		temp--;
	}
	while (ft_checkborder(&tetri[index][1]) & (!ft_validbitmap(&tetri[25][1], &tetri[index][1])))
	{
		ft_shiftright(&tetri[index][1]);
	}
	if  (!ft_checkborder(&tetri[index][1]) & (!ft_validbitmap(&tetri[25][1], &tetri[index][1])))
	{	
		printf("HOLLA, index is: %d\n", index);
		return (-1);
	}
	ft_overlap(&tetri[index][1], &tetri[25][1]);
	square = ft_square(&tetri[25][1]);
/*printf("----Square is: %d\n", square);*/
	return (square);

}

void	ft_removetetri(unsigned short *tetri, unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 12)
	{
		bitmap[i] = bitmap[i] ^ tetri[i];
		i++;
	}
}

void	ft_place(unsigned short tetri[26][13],int index, int pos, int *square)
{
	int temp;
	int len;
	unsigned short save[12];
	
	/*
	if ((index == 1) & (pos == 0))
	{
	ft_bzero(save, 24);
	ft_memcpy(save, &tetri[0][1], 24);
	}*/
	g_recursivecalls++;
	if (tetri[index][0] == 27)
	{
		printf("square was: %d\n", *square);
		if (ft_square(&tetri[25][1]) <= *square);
			*square = ft_square(&tetri[25][1]);
		printf("done, square is: %d\n", *square);
		printf("\n");
		ft_putstr("solution:\n");
		ft_printbitmap(&tetri[25][1]);
		ft_putstr("\n");
		ft_printbyorder(tetri);
		/*ft_memcpy(&tetri[25][1], &tetri[0][1], 24);
		*/
		/*
		ft_printbitmap(&tetri[0][1]);*/
		return;
	}
	len = ft_length(&tetri[25][1]);
	printf("len is: %d\n", len);
	while (pos <= len)
	{
		printf("calling ft_validplace with index: %d pos: %d len: %d square: %d\n", index, pos,len, *square);
		temp = ft_validplace(tetri, index, pos);
		printf("ft_validplace return is: %d\n", temp);
		if ((temp <= *square) & (temp != -1))
		{
			printf("exploring index: %d\n", index + 1);
			ft_place(tetri, index + 1, 0, square);
		}
		/*printf("removing index: %d\n", index);
		ft_printbitmap(&tetri[25][1]);
		ft_putchar('\n');*/
		if (temp != -1)
			ft_removetetri(&tetri[index][1], &tetri[25][1]);
		ft_sortbitmap(&tetri[index][1]);
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
