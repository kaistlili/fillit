/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:07:30 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 15:59:31 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mask(unsigned short *bitmap)
{
	int i;

	i = 0;
	while ((i < 16) && ((bitmap[i] | 32767) == 32767))
		i++;
	if (i != 16)
		return (0);
	return (1);
}

void	ft_printsolution(char solution[17][17], int square)
{
	int i;

	i = 0;
	while (i < square)
	{
		ft_putstr(solution[i]);
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
