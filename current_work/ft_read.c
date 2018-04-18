/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 07:59:53 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/18 20:25:50 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

void	ft_set_n_bit(unsigned short *line, int n)
{
	*line = *line | (1 << ft_abs(n - 15)); 
}

int	ft_connections(char *buffer, int i)
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

/* valid_tetri parses the char buffer and for each point '#' calculates how many orthogonal points, less than 6 connections is always an invalid piece */

int valid_tetri(char *buffer)
{
	int line;
	int i;
	int connections;

	i = 0;
	line = 0;
	connections = 0;
	while (line < 4)
	{
		while(buffer[i] != '\n')
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
		line++;
		i++;
	}
	if (connections < 6)
		return (0);
	return (1);
}

int	ft_tobitflag(char *buffer, unsigned short *flags)
{
	int line;
	int j;
	int count;

	count = 0;
	line = 0;
	j = 1;
	while (line < 4)
	{
		while ((j % 5) != 0)
		{
			if (buffer[j - 1] == '.')
				j++;
			else if (buffer[j - 1] == '#')
			{
				count++;
				ft_set_n_bit(&flags[line], j % 5);
				j++;
			}
			else
				return (0);
		}
		if (buffer[j - 1] != '\n')
			return (0);
		j++;
		line++;
	}
	if ((count != 4) || (!valid_tetri(buffer)))
		return (0);
	ft_sortbitmap(flags);
	return (1);
}

int	ft_readnext(char *buffer, unsigned short *tetrimino, int i)
{
	int j;
	char piece[20];
	j = 1;	
	ft_strncpy(piece, buffer, 20);
	ft_bzero(tetrimino,17*2);
	tetrimino[0] = i + 65;
	if (!ft_tobitflag(buffer, &tetrimino[1]))
		return (0);
	return (1);

}


int ft_parser(int fd, unsigned short tetri[28][17])
{
	char buffer[1024];
	int count;
	int i;

	count = read(fd, &buffer, 1024);
	if (count < 20)
		return (0);
	buffer[count] = '\0';
	i = 0;
	while (i < 26)
	{
		if (!(ft_readnext(buffer, tetri[i], i)))
			return (0);
		if (buffer[20] == '\n')
			ft_memmove(&buffer[0], &buffer[21], count);
		else if (buffer[20] == '\0')
		{
			tetri[i + 1][0] = 27;
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

