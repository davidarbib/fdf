/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:44:45 by darbib            #+#    #+#             */
/*   Updated: 2019/07/06 22:01:26 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

long ft_atoi_base(const char *str, const char *base)
{
	size_t	i;
	int		sign;
	long	nb;
	int		base_nb;
	int		c_idx;

	nb = 0;
	i = 0;
	sign = 1;
	base_nb = ft_strlen(base);
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((c_idx = ft_csearch(str[i], base)) >= 0)
	{
		nb = nb * base_nb + c_idx;
		i++;
	}
	return (sign * nb);
}
