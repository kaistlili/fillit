/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:25:12 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/22 14:30:52 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int	ft_tobitflag(char *buffer, unsigned char *flag);

void	ft_swap(unsigned char *a, unsigned char *b)
{
	unsigned char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_showtetrimino(unsigned char *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_showbits(tetrimino[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_shift(unsigned char *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetrimino[i] = tetrimino[i] << 1;
		i++;
	}
}

void	ft_sort(unsigned char *tetrimino)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j == 0)
	{
		j = 1;
		i = 0;
		while (i < 3)
		{
			if (tetrimino[i] == 0 & tetrimino[i + 1] != 0)
			{
				ft_swap(&tetrimino[i], &tetrimino[i+1]);
				i++;
				j = 0;
			}
			else
				i++;
		}
	}
	while (j == 1)
	{
		if (((tetrimino[0] & 128) == 0) && ((tetrimino[1] & 128) == 0 )
				&& ((tetrimino[2] & 128) == 0))
			ft_shift(tetrimino);
		else
			j = 0;
	}
	
}

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
	
}
