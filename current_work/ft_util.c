/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:59:40 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/15 08:30:55 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
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

int		ft_length(unsigned short *bitmap)
{
	int len;

	len = 11;
	while (bitmap[len] == 0)
		len--;
	return (len + 1);
}

int		ft_width(unsigned short data)
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

int		ft_square(unsigned short *bitmap)
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

int		ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2)
{
	int i;

	i = 0;
	while (((bitmap1[i] & bitmap2[i]) == 0) & (i < 12))
		i++;
	if (i != 12)
		return (0);
	return (1);
}

void	ft_overlap(unsigned short *from, unsigned short *to)
{
	int i;

	i = 0;
	while (i < 12)
	{
		to[i] = from[i] | to[i];
		i++;
	}
}

int		ft_checkborder(unsigned short *tetri)
{
	int i;
	int counter;

	i = 0;
	counter = 1;
	if (tetri[11] != 0)
		return (0);
	while ((i < 12) & (counter))
	{
		if (tetri[i] & 1)
			return (0);
		i++;
	}
	if (counter == 1)
		return (counter);
	return (0);
}

void	ft_bitstoorder(unsigned short x, char order, char *buffer)
{
	int		i;

	i = 15;
	while (i >= 0)
	{
		if (x % 2)
			buffer[i] = order;
		x = x / 2;
		i--;
	}
}

void	ft_getline(unsigned short tetri[28][17], int line, char *buffer)
{
	int i;

	i = 0;
	while (tetri[i][0] != 27)
	{
		ft_bitstoorder(tetri[i][line], tetri[i][0], buffer);
		i++;
	}
}

void	ft_save_solution(unsigned short tetri[28][17],
						int *square, char solution[17][17])
{
	int line;

	*square = ft_square(&tetri[26][1]);
	line = 1;
	while (line < (*square + 1))
	{
		ft_memset(solution[line - 1], 46, 17);
		ft_getline(tetri, line, solution[line - 1]);
		solution[line - 1][*square] = '\0';
		line++;
	}
}

void	ft_shiftleft(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] << 1;
		i++;
	}
}

void	ft_shiftright(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] >> 1;
		i++;
	}
}

void	ft_shiftdown(unsigned short *bitmap)
{
	int i;

	i = 15;
	while (i > 0)
	{
		bitmap[i] = bitmap[i - 1];
		i--;
	}
	bitmap[0] = 0;
}

void	ft_shiftup(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 15)
	{
		bitmap[i] = bitmap[i + 1];
		i++;
	}
	bitmap[i] = 0;
}

/* takes u for shift up, d for shift down, r for shift right. l for shift left*/
int		ft_mask(unsigned short *bitmap)
{
	int i;

	i = 0;
	while ((i < 12) && ((bitmap[i] | 32767) == 32767))
		i++;
	if (i != 12)
		return (0);
	return (1);
}

void	ft_sortbitmap(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (!bitmap[0])
		ft_shiftup(bitmap);
	while (ft_mask(bitmap))
		ft_shiftleft(bitmap);
}
