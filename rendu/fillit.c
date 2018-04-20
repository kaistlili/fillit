/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:04:15 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/19 20:21:20 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int	ft_readnext(char *buffer, unsigned short *tetrimino, int i)
{
	int		j;
	char	piece[20];

	j = 1;
	ft_strncpy(piece, buffer, 20);
	ft_bzero(tetrimino, 17 * 2);
	tetrimino[0] = i + 65;
	if (!ft_tobitflag(buffer, &tetrimino[1]))
		return (0);
	ft_sortbitmap(&tetrimino[1]);
	return (1);
}

int	ft_parser(int fd, unsigned short tetri[27][17])
{
	char	buffer[1024];
	int		count;
	int		i;

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

int	ft_square(unsigned short *bitmap)
{
	int length;
	int width;
	int i;

	i = 0;
	length = ft_length(bitmap);
	width = 0;
	while (i < length)
	{
		if (ft_width(bitmap[i]) > width)
			width = ft_width(bitmap[i]);
		i++;
	}
	if (width >= length)
		return (width);
	return (length);
}

int	main(int ac, char **av)
{
	unsigned short	tetri[27][17];
	int				fd;
	int				square;
	char			solution[17][17];

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	ft_parser(open(av[1], O_RDONLY), tetri);
	fd = open(av[1], O_RDONLY);
	if ((fd == -1) || (!ft_parser(fd, tetri)))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_bzero(&tetri[26][1], 24);
	square = 16;
	solve(tetri, &square, 0, solution);
	ft_printsolution(solution, square);
}
