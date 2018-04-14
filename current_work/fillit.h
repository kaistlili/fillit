/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:57:55 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/13 09:22:05 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

extern int g_recursivecalls;
extern int g_trials;

void	ft_sortnextline(unsigned short *tetri);
void	ft_shiftleft(unsigned short *bitmap);
void	ft_shiftright(unsigned short *bitmap);
void	ft_shiftup(unsigned short *bitmap);
void	ft_shiftdown(unsigned short *bitmap);
void	ft_sortbitmap(unsigned short *bitmap);
void	ft_showint(unsigned int x);
void	ft_printbitmap(unsigned short *bitmap);
void	ft_showshort(unsigned short x);
void	ft_showtetrimino(unsigned char *tetrimino);
void	ft_shift(unsigned char *tetrimino);
void	ft_sort(unsigned char *tetrimino);
void	ft_showshortbyorder(unsigned short x, char order);
void	ft_printorder(unsigned short *bitmap, char order);
void	ft_printbyorder(unsigned short tetri[28][17]);
int		ft_mask(unsigned short *bitmap);
void	ft_save_solution(unsigned short[28][17], int *square, char solution[17][17]);
void	ft_printorderbitmap(unsigned short tetri[28][17], int square);
int		ft_length(unsigned short *bitmap);
int		ft_width(unsigned short data);
int 	ft_square(unsigned short *bitmap);
int 	ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
void 	ft_overlap(unsigned short *from, unsigned short *to);
int		ft_checkborder(unsigned short *tetri);
void    ft_removetetri(unsigned short *tetri, unsigned short *bitmap);

#endif
