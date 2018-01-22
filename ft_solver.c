/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/22 14:52:50 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_solver(unsigned char *tetri, int size)
{
	unsigned char	bitmap[32];
	int i;

	i = 0;
	ft_bzero(bitmap, 32);
	while (i < 7 )
	{
		bitmap[i] = tetri[i / 2];
	    i= i + 2;
	}
	i = 0;
	while (i < 32)
	{
		ft_showbits(bitmap[i]);
		i++;
		ft_putchar(' ');
		ft_showbits(bitmap[i]);
		i++;
		ft_putchar('\n');
	} 
	return (1);
}	
