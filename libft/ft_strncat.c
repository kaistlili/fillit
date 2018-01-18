/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:59:38 by ktlili            #+#    #+#             */
/*   Updated: 2017/12/05 17:43:13 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(s1);
	while ((s2[i] != '\0') && (n > 0))
	{
		s1[len] = s2[i];
		len++;
		i++;
		n--;
	}
	s1[len] = '\0';
	return (&s1[0]);
}
