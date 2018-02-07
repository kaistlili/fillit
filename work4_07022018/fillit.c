/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:53:48 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/07 21:26:56 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>
int	ft_parse(char *buffer, unsigned char *tetrimino, int i)
{

	tetrimino[0] = i + 65;
	ft_bzero(&tetrimino[1], 4);
	if (ft_tobitflag(buffer, &tetrimino[1]) == -1)
		return (0);
	return (1);

}

int	ft_readfile(char *file, unsigned char tetri[26][5])
{
	int fd;
	int i;
	int valid;
	char buffer[20];
	/*unsigned char **tetri;

	tetri = malloc(sizeof(unsigned char*) * 26);*/
	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	valid = 1;
	i = 0;
	while ((read(fd, &buffer, 20) == 20) & (valid))
	{
		valid = ft_parse(buffer, tetri[i], i);
		if ((valid) & (read(fd, &buffer[0], 1)))
			if (buffer[0] != '\n')
				valid = 0;	
		i++;
	}
	tetri[i][0] = '0';
	if (valid)
		return (1);
	return (-1);
}


int	main(int ac, char **av)
{
	unsigned char tetri[26][5];
	int i;
	int ret;
	if (ac != 2)
	{
		ft_putstr("Invalid input.\n");
		return (0);
	}
	ret = ft_readfile(av[1], tetri);
	printf("returned from read.\n");
	if (ret == -1)
	{
		ft_putstr("Invalid file");
		return (0);
	}
	i = 0;	
	printf("starting loop\n");
	while (tetri[i][0] != '0')
	{
		ft_putchar(tetri[i][0]);
		ft_putchar('\n');
		ft_showtetrimino(&tetri[i][1]);
		ft_putchar('\n');
		i++;
	}		
}
