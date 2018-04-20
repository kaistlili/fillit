/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showbits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:45:42 by ktlili            #+#    #+#             */
/*   Updated: 2017/12/17 18:25:32 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_showbits(unsigned char c)
{
	int		i;
	char	*buffer;

	buffer = (char*)malloc(9);
	i = 7;
	while (i >= 0)
	{
		buffer[i] = (c % 2) + '0';
		c = c / 2;
		i--;
	}
	buffer[8] = '\0';
	ft_putstr(buffer);
}
