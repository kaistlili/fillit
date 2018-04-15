/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:57:55 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/15 08:05:40 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

extern int g_recursivecalls;
extern int g_trials;

int 	solve(unsigned short tetri[28][17], int *square, int index, char solution[17][17]);
void	ft_sortnextline(unsigned short *tetri);
void	ft_shiftleft(unsigned short *bitmap);
void	ft_shiftright(unsigned short *bitmap);
void	ft_shiftup(unsigned short *bitmap);
void	ft_shiftdown(unsigned short *bitmap);
void	ft_sortbitmap(unsigned short *bitmap);
int		ft_mask(unsigned short *bitmap);
void	ft_save_solution(unsigned short[28][17], int *square, char solution[17][17]);
int		ft_length(unsigned short *bitmap);
int		ft_width(unsigned short data);
int 	ft_square(unsigned short *bitmap);
int 	ft_validbitmap(unsigned short *bitmap1, unsigned short *bitmap2);
void 	ft_overlap(unsigned short *from, unsigned short *to);
int		ft_checkborder(unsigned short *tetri);
void    ft_removetetri(unsigned short *tetri, unsigned short *bitmap);
int		ft_abs(int n);
void	ft_set_n_bit(unsigned short *line, int n);
int		ft_tobitflag(char *buffer, unsigned short *flags);
int		ft_readnext(char *buffer, unsigned short *tetrimino, int i);
int		ft_parser(int fd, unsigned short tetri[28][17]);

#endif
