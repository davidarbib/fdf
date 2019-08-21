/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:29:28 by darbib            #+#    #+#             */
/*   Updated: 2019/08/13 17:56:27 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/fdf.h"

/*
void exp_hk(void *param)
{
}
*/
int key_hk(int keycode, t_param *pm)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_R)
	{
		mlx_destroy_image(pm->sk, pm->im);
		pm->im = mlx_new_image(pm->sk, WIDTH, HEIGHT);
		pm->im_addr = mlx_get_data_addr(pm->im, &(pm->bpp), &(pm->ln_sz),
					&(pm->endian));
		alter_pixel(pm, 0xFF0000, 20, 20);
		mlx_put_image_to_window(pm->sk, pm->wd, pm->im, 0, 0);
	}
	if (keycode == KEY_G)
	{
		mlx_destroy_image(pm->sk, pm->im);
		pm->im = mlx_new_image(pm->sk, WIDTH, HEIGHT);
		pm->im_addr = mlx_get_data_addr(pm->im, &(pm->bpp), &(pm->ln_sz),
					&(pm->endian));
		alter_pixel(pm, 0x00FF00, 20, 20);
		mlx_put_image_to_window(pm->sk, pm->wd, pm->im, 0, 0);
	}
	if (keycode == KEY_B)
	{
		mlx_destroy_image(pm->sk, pm->im);
		pm->im = mlx_new_image(pm->sk, WIDTH, HEIGHT);
		pm->im_addr = mlx_get_data_addr(pm->im, &(pm->bpp), &(pm->ln_sz),
					&(pm->endian));
		alter_pixel(pm, 0x0000FF, 20, 20);
		mlx_put_image_to_window(pm->sk, pm->wd, pm->im, 0, 0);
	}
	return (1);
}

int	 ms_hk(int button, int x, int y, void *pm)
{
	(void)pm;
	printf("mouse button : %d\n", button);
	printf("mouse x : %d\n", x);
	printf("mouse y : %d\n", y);
	return (1);
}

/*
void lp_hk(void *param)
{
}

*/

