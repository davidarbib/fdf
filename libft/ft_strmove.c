/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:18:56 by darbib            #+#    #+#             */
/*   Updated: 2019/06/27 15:53:03 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmove(char **s1)
{
	char	*dup;
	int		i;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + 1))))
		return (NULL);
	i = 0;
	while ((*s1)[i])
	{
		dup[i] = (*s1)[i];
		i++;
	}
	dup[i] = '\0';
	ft_strdel(s1);
	return (dup);
}
