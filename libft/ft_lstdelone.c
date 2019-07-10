/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:40:33 by darbib            #+#    #+#             */
/*   Updated: 2019/06/27 15:49:41 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	(del)((*(alst))->content, (*(alst))->content_size);
	ft_memdel((void **)alst);
}
