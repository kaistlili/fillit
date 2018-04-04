/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:59:40 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/09 10:01:07 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



void	ft_showshortbyorder(unsigned short x, char order)
{
	int		i;
	char buffer[17];

	i = 15;
	while (i >= 0)
	{
		if (x % 2)
			buffer[i] = order;
		else
		buffer[i] = '0';
		x = x / 2;
		i--;
	}
	buffer[16] = '\0';
	ft_putstr(buffer);
}


void	ft_printbitmapbyorder(unsigned short *bitmap, char order)
{
	int i;

	i = 0;
	while (i < 12)
	{
		ft_showshortbyorder(bitmap[i], order);
		ft_putchar('\n');
		i++;
	}
}
void ft_printbyorder(unsigned short tetri[26][13])
{
	int i;

	i = 0;
	while (tetri[i][0] != 27)
	{	
		ft_printbitmapbyorder(&tetri[i][1], tetri[i][0]);
		ft_putchar('\n');
		i++;
	}
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
	buffer[16] = '\0';
}

void	ft_getline(unsigned short tetri[26][13], int line, char *buffer)
{
	int i;

	i = 0;

	while (tetri[i][0] != 27)
	{
		ft_bitstoorder(tetri[i][line], tetri[i][0], buffer);
		i++;
	}
	
}



void	ft_printorderbitmap(unsigned short tetri[26][13])
{
	int line;
	char buffer[17];
	int i;

	buffer[16] = '\0';
	i = 0;
	ft_memset(buffer, 46, 16);
	line = 1; /*tetri bitmap starts at index 1*/
	while (line < 13)
	{
		ft_getline(tetri, line, buffer);
		ft_putstr(buffer);
		ft_memset(buffer, 46, 16);
		ft_putchar('\n');
		line++;
	}
}

void	ft_shiftleft(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 12)
	{
		bitmap[i] = bitmap[i] << 1;
		i++;
	}
}


void	ft_shiftright(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 12)
	{
		bitmap[i] = bitmap[i] >> 1;
		i++;
	}
}

void	ft_shiftup(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 11)
	{
		bitmap[i] = bitmap[i + 1];
		i++;
	}
	bitmap[i] = 0;
}

void	ft_shiftdown(unsigned short *bitmap)
{
	int i;

	i = 11;
	while (i > 0)
	{
		bitmap[i] = bitmap[i - 1];
		i--;
	}
	bitmap[i] = 0;
}

int	ft_mask(unsigned short *bitmap)
{
	int i;

	i = 0;
	while ((i < 12) && ((bitmap[i] | 32767) == 32767))
		i++;
	if (i != 12)
		return (0);
	return (1);
}

void ft_sortbitmap(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (!bitmap[0])
		ft_shiftup(bitmap);
	while (ft_mask(bitmap))
		ft_shiftleft(bitmap);
}
	
void	ft_showint(unsigned int x)
{
	int		i;
	char	buffer[33];

	i = 31;
	while (i >= 0)
	{
		buffer[i] = (x % 2) + '0';
		x = x / 2;
		i--;
	}
	buffer[32] = '\0';
	ft_putstr(buffer);
}

void	ft_showshort(unsigned short x)
{
	int		i;
	char buffer[17];

	i = 15;
	while (i >= 0)
	{
		buffer[i] = (x % 2) + '0';
		x = x / 2;
		i--;
	}
	buffer[16] = '\0';
	ft_putstr(buffer);
}


void	ft_printbitmap(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (i < 12)
	{
		ft_showshort(bitmap[i]);
		ft_putchar('\n');
		i++;
	}
}
void	ft_showbitmap(unsigned int *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_showint(bitmap[i]);
		ft_putchar('\n');
		i++;
	}
}
void	ft_swap(unsigned char *a, unsigned char *b)
{
	unsigned char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_showtetrimino(unsigned char *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_showbits(tetrimino[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_shift(unsigned char *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetrimino[i] = tetrimino[i] << 1;
		i++;
	}
}


void	ft_sort(unsigned char *tetrimino)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j == 0)
	{
		j = 1;
		i = 0;
		while (i < 3)
		{
			if (tetrimino[i] == 0 & tetrimino[i + 1] != 0)
			{
				ft_swap(&tetrimino[i], &tetrimino[i+1]);
				i++;
				j = 0;
			}
			else
				i++;
		}
	}
	while (j == 1)
	{
		if (((tetrimino[0] & 128) == 0) && ((tetrimino[1] & 128) == 0 )
				&& ((tetrimino[2] & 128) == 0))
			ft_shift(tetrimino);
		else
			j = 0;
	}
	
}
