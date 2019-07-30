/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:39:17 by darbib            #+#    #+#             */
/*   Updated: 2019/07/30 15:33:47 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_realloc(void *area, size_t size, size_t size_ad)
{
	void 	*area_pp;

	if (!(area_pp = ft_memalloc(size + size_ad)))
		return (NULL);
	ft_memmove(area_pp, area, size);
	ft_memdel(&area);
	return (area_pp);
}
