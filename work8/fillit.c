/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:53:48 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/09 10:41:55 by ktlili           ###   ########.fr       */
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
	bzero(temp, 4);
	bzero(tetrimino,13*2);
	tetrimino[0] = i;
	if (ft_tobitflag(buffer, temp) == -1)
		return (0);
	ft_showtetrimino(temp);
	while ( j <= 4)
	{
		tetrimino[j] = temp[j -1];
	   	j++;
	}
	return (1);

}

int	ft_readfile(char *file, unsigned short tetri[26][13])
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

void ft_place(unsigned short tetri[26][13], int index, int pos, int *square);
void ft_solvecomb(unsigned short tetri[26][13], int index, int *square);

int	main(int ac, char **av)
{
	unsigned short tetri[26][13];
	int i;
	int size;
	int ret;
	int square;

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
	while (tetri[i][0] != 27)
	{
		ft_sortbitmap(&tetri[i][1]);
		i++;
	}
	ft_memcpy(&tetri[25][1],&tetri[0][1],24);
/*	ft_printbitmap(&tetri[25][1]);
	ft_putstr("that was tetri 25\n");
	ft_printbyorder(tetri);
*/
	size = i - 1 ;
	square = 16;


	ft_permutation(tetri, 0, size, &square);
/*	ft_solvecomb(tetri, 1, &square);
	ft_heap_permutation(tetri, size, &square);
*/	/*ft_solver(tetri,0, size, &square );
	
	ft_permutation(tetri, 0, size , square);

	ft_place(tetri, 0, 0, &square );
*/

printf("\n\n++function called: %d times\n", g_recursivecalls);

}
