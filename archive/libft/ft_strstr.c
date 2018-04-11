/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:34:11 by ktlili            #+#    #+#             */
/*   Updated: 2017/12/05 17:51:18 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	while (haystack[i] != 0)
	{
		while (haystack[i] == needle[j] && j < len)
		{
			i++;
			j++;
		}
		if (j == len)
			return ((char*)&haystack[i - j]);
		else
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
