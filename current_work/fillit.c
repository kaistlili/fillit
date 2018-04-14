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
int g_trials = 0;

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

int	ft_tobitflag(char *buffer, unsigned short *flags)
{
	int line;
	int j;
	int count;
	
	line = 0;
	j = 1;
	count = 0;
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
				return (-1);
		}
		if (buffer[j - 1] != '\n')
			return (-1);
		j++;
		line++;
	}
	if (count != 4) /* replace with function that determines if the tetri we just stored in flags is valid */
		return (-1);
	ft_sortbitmap(flags);
	return (1);
}
int	ft_readnext(char *buffer, unsigned short *tetrimino, int i)
{
	int j;

	j = 1;
	ft_bzero(tetrimino,17*2);
	tetrimino[0] = i + 65;
	if (ft_tobitflag(buffer, &tetrimino[1]) == -1)
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
		if (!(ft_readnext(buffer, tetri[i], i))) //change i to i + 65 on readnext
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



void	ft_printsolution(char solution[17][17], int square)
{
	int i;

	i = 0;
	while (i < square)
	{
		ft_putstr(solution[i]);
		ft_putchar('\n');
		i++;
	}
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
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	ret = ft_parser(open(av[1], O_RDONLY), tetri);
	if (ret == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_bzero(&tetri[26][1], 24);
	square = 16;
	solve(tetri, &square, 0, solution);
//	printf("++function called: %d times. %d trials. smallest square found %d\n", g_recursivecalls,g_trials, square);
	printf("Square is: %d\n", square);
	ft_printsolution(solution, square);
}
