/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:11:08 by darbib            #+#    #+#             */
/*   Updated: 2019/08/12 22:31:27 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int to_little(unsigned int data)
{
	unsigned int out;

	out = 0;
	out += LLLLLL
}

short is_big_endian(void)
{
	int nb;

	nb = 0x0042;
	if (nb >> 8 == 0x00)
		return (1);
	return (0);
}
