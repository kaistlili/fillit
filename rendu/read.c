/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:05:10 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 20:19:14 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_connections(char *buffer, int i)
{
	int connections;

	connections = 0;
	if ((i - 5) >= 0)
	{
		if (buffer[i - 5] == '#')
			connections++;
	}
	if ((i + 1) < 19)
	{
		if (buffer[i + 1] == '#')
			connections++;
	}
	if ((i + 5) < 19)
	{
		if (buffer[i + 5] == '#')
			connections++;
	}
	if ((i - 1) >= 0)
	{
		if (buffer[i - 1] == '#')
			connections++;
	}
	return (connections);
}

int				valid_tetri(char *buffer)
{
	int i;
	int connections;

	i = 0;
	connections = 0;
	while (i < 20)
	{
		while (buffer[i] != '\n')
		{
			if (buffer[i] == '#')
			{
				if (!ft_connections(buffer, i))
					return (0);
				else
					connections = connections + ft_connections(buffer, i);
			}
			i++;
		}
		i++;
	}
	if (connections < 6)
		return (0);
	return (1);
}

int				ft_tobitflag(char *buffer, unsigned short *flags)
{
	int j;
	int count;

	count = 0;
	j = 1;
	while (j <= 20)
	{
		while ((j % 5) != 0)
		{
			if ((buffer[j - 1] != '.') & (buffer[j - 1] != '#'))
				return (0);
			else if (buffer[j - 1] == '#')
			{
				count++;
				ft_set_n_bit(&flags[j / 5], j % 5);
			}
			j++;
		}
		if (buffer[j - 1] != '\n')
			return (0);
		j++;
	}
	if ((count != 4) || (!valid_tetri(buffer)))
		return (0);
	return (1);
}

void			ft_set_n_bit(unsigned short *line, int n)
{
	*line = *line | (1 << ft_abs(n - 15));
}

unsigned int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}
