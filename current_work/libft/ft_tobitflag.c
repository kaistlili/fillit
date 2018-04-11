/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:40:52 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/08 19:53:53 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* return -1 on invalid input*/
#include <stdio.h>

int	ft_tobitflag(char *buffer, unsigned char *flags)
{
	int i;
	int j;
	int count;
	
	i = 0;
	j = 0;
	count = 0;
	while (i < 4 & count >= 0 & count < 5)
	{
		while (buffer[j] != '\n' & count >= 0 & count < 5)
		{
			if (buffer[j] == '.')
				j++;
			else if (buffer[j] == '#')
			{
				count++;
				flags[i] = flags[i] | (1 << (7 - (j % 5)));
				j++;
			}
			else
				count = -1;
		}
		j++;
		i++;
	}
	if (count != 4)
		count = -1;

	return (count);
}
