/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:09:43 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 16:01:36 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
