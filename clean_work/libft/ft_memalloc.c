/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:04:05 by ktlili            #+#    #+#             */
/*   Updated: 2017/12/05 18:23:47 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char*)malloc(size);
	if (p == NULL)
		return (NULL);
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
