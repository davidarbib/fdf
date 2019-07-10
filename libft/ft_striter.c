/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:32:37 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 23:52:38 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	if (!s || !(*f))
		return ;
	i = 0;
	while (s[i])
	{
		(f)(&s[i]);
		i++;
	}
}