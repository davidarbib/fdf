/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:44:41 by darbib            #+#    #+#             */
/*   Updated: 2019/06/27 15:37:57 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*ptr;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	ptr = (char *)haystack;
	while (*ptr)
	{
		i = 0;
		while (ptr[i] == needle[i] && needle[i])
			i++;
		if (!needle[i])
			return (ptr);
		ptr++;
	}
	return (NULL);
}
