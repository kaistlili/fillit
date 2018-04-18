/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:53:48 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/18 20:10:32 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include<fcntl.h>

int g_recursivecalls = 0;
int g_trials = 0;



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
	printf("Square is: %d\n", square);
	ft_printsolution(solution, square);

}
