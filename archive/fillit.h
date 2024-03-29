/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:57:55 by ktlili            #+#    #+#             */
/*   Updated: 2018/01/29 18:47:54 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

void	ft_shiftleft(unsigned int *bitmap);
void	ft_shiftright(unsigned int *bitmap);
void	ft_shiftup(unsigned int *bitmap);
void	ft_shiftdown(unsigned int *bitmap);
void	ft_sortbitmap(unsigned int *bitmap);

void	ft_showbitmap(unsigned int *bitmap);
void	ft_showint(unsigned int x);
void	ft_swap(unsigned char *a, unsigned char *b);
void	ft_showtetrimino(unsigned char *tetrimino);
void	ft_shift(unsigned char *tetrimino);
void	ft_sort(unsigned char *tetrimino);

#endif
