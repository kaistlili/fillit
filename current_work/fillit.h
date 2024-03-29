/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:57:55 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/08 18:50:32 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

extern int g_recursivecalls;

void	ft_sortnextline(unsigned short *tetri);
void	ft_solve_all(unsigned short tetri[26][13], int start, int end, int *square);
void	ft_swapbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
void	ft_heap_permutation(unsigned short tetri[26][13], int size, int *square);
void	ft_shiftleft(unsigned short *bitmap);
void	ft_shiftright(unsigned short *bitmap);
void	ft_shiftup(unsigned short *bitmap);
void	ft_shiftdown(unsigned short *bitmap);
void	ft_sortbitmap(unsigned short *bitmap);
void	ft_showbitmap(unsigned int *bitmap);
void	ft_showint(unsigned int x);
void	ft_printbitmap(unsigned short *bitmap);
void	ft_showshort(unsigned short x);
void	ft_swap(unsigned char *a, unsigned char *b);
void	ft_showtetrimino(unsigned char *tetrimino);
void	ft_shift(unsigned char *tetrimino);
void	ft_sort(unsigned char *tetrimino);
void	ft_showshortbyorder(unsigned short x, char order);
void	ft_printorder(unsigned short *bitmap, char order);
void	ft_printbyorder(unsigned short tetri[26][13]);
void	ft_swapbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
int		ft_mask(unsigned short *bitmap);
/**/
void	ft_solver(unsigned short tetri[26][13], int start, int end, int *square);
void	ft_placenext(unsigned short tetri[26][13], int index, int end, int *square);

/**/

void	ft_printorderbitmap(unsigned short tetri[26][13], int square);
int ft_length(unsigned short *bitmap);
int ft_width(unsigned short data);
int ft_square(unsigned short *bitmap);
int ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
void ft_overlap(unsigned short *from, unsigned short *to);
int ft_checkborder(unsigned short *tetri);
void    ft_removetetri(unsigned short *tetri, unsigned short *bitmap);

#endif
