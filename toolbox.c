/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:04:54 by darbib            #+#    #+#             */
/*   Updated: 2019/07/30 19:30:21 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include/fdf.h"

void	del_map(t_map *map, int j)
{
	while (j > -1)
	{
		free(map->pts[j]);
		j--;
	}
	free(map->pts);
	free(map);
}

void	del_lines(t_line *head)
{
	t_line *pre_node;
	t_line *node;

	if (!head)
		return ;
	node = head;
	while (node->next)
	{
		pre_node = node->next;
		node->next = node->next->next;
		free(pre_node->line);
		free(pre_node);
	}
	free(node->line);
	free(node);
}

t_line	*new_line(char *line)
{
	t_line *node;

	if (!(node = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

long ft_atoi_base_spe(char **str, const char *base)
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
	while (**str == '\f' || **str == '\t' || **str == ' ' || **str == '\n'
			|| **str == '\r' || **str == '\v')
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		*str += 1;
	}
	while ((c_idx = ft_csearch(**str, base)) >= 0)
	{
		nb = nb * base_nb + c_idx;
		*str += 1;
	}
	return (sign * nb);
}

int	ft_atoi_spe(char **str)
{
	size_t	i;
	int		sign;
	long	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (**str == '\f' || **str == '\t' || **str == ' ' || **str == '\n'
			|| **str == '\r' || **str == '\v')
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		*str += 1;
	}
	while (ft_isdigit(**str))
	{
		nb = nb * 10 + (int)(**str - '0');
		*str += 1;
	}
	while (!(ft_isdigit(**str)) && **str && **str != SEP && **str != SEPX)
		*str += 1;
	return (sign * nb);
}
