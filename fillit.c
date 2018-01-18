/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:25:12 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/18 09:43:01 by ktlili           ###   ########.fr       */
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
		if (((tetrimino[0] & 128) == 0) && ((tetrimino[1] & 128) == 0 ))
			ft_shift(tetrimino);
		else
			j = 0;
	}
	
}

t_list	**ft_readfile(int ac, char **av)
{
	int fd;
	int i;
	char buffer[20];
	unsigned char *bitflag;
	t_list *next;
	t_list **tetri;

	tetri = malloc(sizeof(t_list*));
	i = 0;
	if (ac != 2)
	{
		ft_putstr("Invalid input.\n");
		return (NULL);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot open file.\n");
		return (NULL);
	}
	bitflag = ft_memalloc(4);
	while (read(fd, &buffer, 20) == 20)
	{
		ft_bzero(bitflag, 4);
		ft_tobitflag(buffer, bitflag);
		if (i == 0)
		{
			*tetri = ft_lstnew(bitflag, 4);
			i++;
		}
		else
		{
			next = ft_lstnew(bitflag, 4);
			ft_lstadd(tetri, next);
			i++;
		}
	}

	return (tetri);
}

int main(int argc, char **argv)
{
	t_list **tetri;
	int		end;

	end = 0;
	tetri = ft_readfile(argc, argv);
	if (tetri == NULL)
		return (0);
	printf("returned\n");
	while (end < 2)
	{
		ft_sort((*tetri)->content);
		ft_showtetrimino((*tetri)->content);
		ft_putstr("\n");
		if (end == 0)
			*tetri = (*tetri)->next;
		else
			end = 2;
		if ( (*tetri)->next == NULL && end == 0)	
			end = 1;
	}
}
