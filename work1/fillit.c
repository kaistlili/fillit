/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:25:12 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/25 15:34:53 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int ft_solver(unsigned char *tetri, int size);

int	ft_readfile(int ac, char **av, unsigned char *tetri)
{
	int fd;
	int i;
	char buffer[20];
	
	i = 0;
	if (ac != 2)
	{
		ft_putstr("Invalid input.\n");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot open file.\n");
		return (-1);
	}
	if (tetri == NULL)
		return (-1);
	while (read(fd, &buffer, 20) == 20)
	{
		ft_tobitflag(buffer, &tetri[i]);

		i = i + 4;
	}

	return (i / 4);
}

int main(int argc, char **argv)
{
	unsigned char tetri[26 * 4];
	int		size;
	int		i;

	i = 0;
	ft_bzero(tetri, 26*4);
	size = ft_readfile(argc, argv, tetri);
	while ((i / 4) < size)
	{
		ft_showtetrimino(&tetri[i]);
		ft_putstr("\n");
		i = i + 4;
	}
	ft_solver(tetri, size);
	
}
