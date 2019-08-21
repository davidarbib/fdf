/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:32:31 by darbib            #+#    #+#             */
/*   Updated: 2019/08/13 23:01:43 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "include/fdf.h"

/*
** transforms color code in chars
** color format is BBGGRRAA
*/

void	color_chars(unsigned int color, char *str)
{
	str[0] = color & 0x000000FF;
	str[1] = (color >> 8) & 0x000000FF;
	str[2] = (color >> 16) & 0x000000FF;
}

void	alter_pixel(t_param *pm, unsigned int color, int x, int y)
{
	char *p_im;

	p_im = pm->im_addr + x * (pm->bpp / 8) + y * pm->ln_sz;
	color_chars(mlx_get_color_value(pm->sk, color), p_im);
}

/*
int main()
{
	int color;
	char *c_str = malloc(4);

	color = 0x15FF42;
	color = add_alpha(color, 1);
	color_chars((color), c_str);
	printf("red : %hhu\n", c_str[0]);
	printf("green : %hhu\n", (unsigned char)c_str[1]);
	printf("blue : %hhu\n", c_str[2]);
	printf("alpha : %hhu\n", c_str[3]);
	return (0);
}
*/
