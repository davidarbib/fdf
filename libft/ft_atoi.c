/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:24:25 by darbib            #+#    #+#             */
/*   Updated: 2019/06/27 17:40:29 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"


int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (int)(str[i] - '0');
		i++;
	}
	return (sign * nb);
}
