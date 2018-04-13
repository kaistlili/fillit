/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:53:48 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/13 09:07:42 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include<fcntl.h>

int g_recursivecalls = 0;

int	ft_parse(char *buffer, unsigned short *tetrimino, int i)
{
	unsigned char temp[4];
	int j;


	j = 1;
	ft_bzero(temp, 4);
	ft_bzero(tetrimino,17*2);
	tetrimino[0] = i;
	if (ft_tobitflag(buffer, temp) == -1)
		return (0);
	
	printf("\ntetri %c\n", i);
	ft_showtetrimino(temp);
	while ( j <= 4)
	{
		tetrimino[j] = temp[j - 1];
	   	j++;
	}
	return (1);

}

int	ft_readfile(char *file, unsigned short tetri[28][17])
{
	int fd;
	int i;
	int valid;
	char buffer[20];

	if (!(fd = open(file, O_RDONLY)) | (tetri == NULL))
		return (-1);
	valid = 1;
	i = 65;
	while ((read(fd, &buffer, 20) == 20) & (valid))
	{
		valid = ft_parse(buffer, tetri[i - 65], i);
		if ((valid) & (read(fd, &buffer[0], 1)))
			if (buffer[0] != '\n')
				valid = 0;
		i++;
	}
	tetri[i - 65][0] = 27;
	return (1) ;
}
/*
 * -changed tetri[26][13] to tetri[28][17]
 * -each tetri[n][0] holds the order of our tetri by letter (A, B....)
 * -tetri[n][1..16] holds our tetrimino in bit flags
 * -solution[17][17] is the bitmap that will hold the last smallest square
 * the solver algorithm has found.
 */

/* TO DO:
 * - file reading error handling.
 * - invalid tetrimino checking(we can just compare each piece to every possible piece return invalid if it dosnet match).
 * - cleaning util.c function.
 * - solve function has to be shorter.
 * - ????
 */
int 	solve(unsigned short tetri[28][17], int *square, int index, char solution[17][17]);


int	main(int ac, char **av)
{
	unsigned short tetri[28][17];
	int i;
	int size;
	int ret;
	int square;
	char solution[17][17];
	
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
	while (tetri[i][0] != 27)
	{
		ft_sortbitmap(&tetri[i][1]);
		i++;
	}
	ft_bzero(&tetri[26][1], 24);
	square = 16;
	solve(tetri, &square, 0, solution);
	printf("\n\n++function called: %d times. smallest square found %d\n", g_recursivecalls, square);
	i = 0;
	while (i < square)
		{
		ft_putstr(solution[i]);
		ft_putchar('\n');
		i++;
	}
}
