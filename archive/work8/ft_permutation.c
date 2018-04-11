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

	len = 11;
	while (bitmap[len] == 0)
		len--;
	return (len + 1);
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
	int i;

	i = 0;
	length = ft_length(bitmap);
	width = 0;
	while (i < length)
	{
		if (ft_width(bitmap[i]) > width)
			width = ft_width(bitmap[i]);
		i++;
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
	if (tetri[11] != 0)
		counter == 0;
	while ((i < 12) & (counter))
	{
		
		if (tetri[i] & 1)		
			counter = 0;
		i++;
	}
	if (counter == 1)
		return (counter);
	return (0);
}

int ft_validplace(unsigned short tetri[26][13], int index, int line, int order)
/*return 100 if overlap is invalid, return square if valid;*/
{
	unsigned short temp;
	int square;
	int counter;

	counter = 0;
	temp = line;
	while ((temp > 0) && (tetri[index][12] == 0))
	{
		ft_shiftdown(&tetri[index][1]);
		temp--;
	}
	if ((temp != 0) && (tetri[index][12] != 0))
		return (-1);
	
	temp = tetri[25][line];
	while (temp != 0)
	{
		if ((temp & 32767) == 32767)
		{
			
		}
		temp = temp << 1;
	}
	/*while (ft_checkborder(&tetri[index][1]) & (!ft_validbitmap(&tetri[25][1], &tetri[index][1])))
	{
		ft_shiftright(&tetri[index][1]);
	}*/
	if  (!ft_checkborder(&tetri[index][1]) & (!ft_validbitmap(&tetri[25][1], &tetri[index][1])))
	{	
		/*printf("HOLLA, index is: %d\n", index);
	*/	return (-1);
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
	int order;
	int lastplace;
	unsigned short save;
	
	g_recursivecalls++; /*global variable to track recursive calls count*/
	if (tetri[index][0] == 27) /*if all tetri placed, check square and print if smaller then previous*/
	{
		if (ft_square(&tetri[25][1]) < *square);
		{
			*square = ft_square(&tetri[25][1]);
			printf("done, solution found, square is: %d\n\n", *square);
			ft_putstr("solution is:\n");
			ft_printbitmap(&tetri[25][1]);
			ft_putstr("\n");
			ft_printbyorder(tetri);
		}
		return;
	}
	len = ft_length(&tetri[25][1]);
	order = 0;
	lastplace = 2;
	while (pos <= len)
	{
		save = pos;
		while (save)
		{
			ft_shiftdown(&tetri[index][1]);
			save--;
		}
		save =  tetri[25][pos + 1];
		lastplace = 2;
		while (((save != 0) | (lastplace > 0)) & (ft_checkborder(&tetri[index][1])))
		{
			if ((save & 32768) == 0) /*if current bit in current line is 0 then check if valid placement*/
			{	
				ft_validbitmap(&tetri[25][1], &tetri[index][1]);
				if (ft_validbitmap(&tetri[25][1], &tetri[index][1])) /*if valid overlap current tetri on bitmap and check square*/
				{
					ft_overlap(&tetri[index][1], &tetri[25][1]);
					if (ft_square(&tetri[25][1]) < *square) /*if current square < previous square explore further (recrusive call) */
						ft_place(tetri, index + 1, 0, square);
					
					ft_removetetri(&tetri[index][1], &tetri[25][1]);
				}
			}
			save = save << 1;
			if (save == 0) /*if current line is 0 iterate one last time*/
				lastplace--;
			ft_shiftright(&tetri[index][1]);
			order++;
		}
		ft_sortbitmap(&tetri[index][1]);
		pos++;
	}
}



void	ft_heap_permutation(unsigned short tetri[26][13], int size, int *square)
{
	int i;
	int j;

	j = 0;
	if (size == 1)
	{
		ft_memcpy(&tetri[25][1], &tetri[0][1], 24);	
		ft_place(tetri, 1, 0, square);
		return;
	}
	i = 0;
	while (i < size)
	{
		ft_putchar(tetri[size-1][0] + 65);
		ft_heap_permutation(tetri, size - 1, square);
		if (size % 2 == 1)
			ft_swapbitmap(tetri[0], tetri[size - 1]);
		else
			ft_swapbitmap(tetri[i], tetri[size - 1]);
		i++;
	}
}
