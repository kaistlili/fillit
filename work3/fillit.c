/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:25:12 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/03 18:18:58 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list *current;

	current = *alst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_list	**ft_readfile(int ac, char **av)
{
	int fd;
	int i;
	char order;
	char buffer[20];
	unsigned char *bitflag;
	t_list *next;
	t_list **tetri;

	order = 'A';
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
			*tetri = ft_lstnew(bitflag, order);	
			i++;
		}
		else
		{
			next = ft_lstnew(bitflag, order);
			
			ft_lstaddlast(tetri, next);
			i++;
		}
		order++;
	}

	return (tetri);
}
void	ft_printlist(t_list **tetri)
{ 
	int end;
	t_list **temp;

	temp = tetri;
	end = 0;
	while (end < 2)
	{
		ft_putchar( (*temp)->order);
		ft_putchar('\n');
		ft_showtetrimino((*temp)->content);
		ft_putchar('\n');
		if (end == 0)
			*temp = (*temp)->next;
		else
			end = 2;
		if ( (*temp)->next == NULL && end == 0)	
			end = 1;
	}


}
int	ft_solver(t_list **tetri);

int main(int argc, char **argv)
{
	t_list **tetri;
	
	tetri = ft_readfile(argc, argv);
	if (tetri == NULL)
		return (0);
/*	ft_printlist(tetri);*/
	ft_solver(tetri);

}
