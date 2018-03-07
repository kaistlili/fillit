/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:57:55 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/09 10:33:08 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

void	ft_permutation(unsigned short tetri[26][13], int start, int end, int square);
void	ft_swapbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
void	ft_heap_permutation(unsigned short tetri[26][13], int size, int square);
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

#endif
