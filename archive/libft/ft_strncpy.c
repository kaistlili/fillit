/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:18 by ktlili            #+#    #+#             */
/*   Updated: 2017/12/05 17:42:30 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < len)
	{
		if ((flag == 1) || (src[i] == '\0'))
		{
			flag = 1;
			dst[i] = '\0';
			i++;
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (&dst[0]);
}
