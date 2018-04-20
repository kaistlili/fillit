/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:21 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 15:13:23 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	ft_sortbitmap(unsigned short *bitmap)
{
	int i;

	i = 0;
	while (!bitmap[0])
		ft_shiftup(bitmap);
	while (ft_mask(bitmap))
		ft_shiftleft(bitmap);
}
