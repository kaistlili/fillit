/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:59:40 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/29 18:53:15 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	ft_shiftleft(unsigned int *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] << 1;
		i++;
	}
}


void	ft_shiftright(unsigned int *bitmap)
{
	int i;

	i = 0;
	while (i < 16)
	{
		bitmap[i] = bitmap[i] >> 1;
		i++;
	}
}

void	ft_shiftup(unsigned int *bitmap)
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

void	ft_shiftdown(unsigned int *bitmap)
{
	int i;

	i = 15;
	while (i > 0)
	{
		bitmap[i] = bitmap[i - 1];
		i--;
	}
	bitmap[i] = 0;
}
#include <stdio.h>
int	ft_mask(unsigned int *bitmap)
{
	int i;

	i = 0;
	while ((i < 16) && ((bitmap[i] | 2147483647) == 2147483647))
		i++;
	printf("i is : %d\n",i );
	if (i != 16)
		return (0);
	return (1);
}

void ft_sortbitmap(unsigned int *bitmap)
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
