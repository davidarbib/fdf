/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:07:55 by darbib            #+#    #+#             */
/*   Updated: 2019/08/13 17:50:37 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

int		init_fdf(t_param *pm)
{
	pm->bpp = 0;
	pm->ln_sz = 0;
	pm->endian = 0;
	if (!(pm->sk = mlx_init()))
		return (0);
	if (!(pm->wd = mlx_new_window(pm->sk, WIDTH, HEIGHT, "test")))
		return (0);
	if (!(pm->im = mlx_new_image(pm->sk, WIDTH, HEIGHT)))
		return (0);
	if (!(pm->im_addr = mlx_get_data_addr(pm->im, &(pm->bpp), &(pm->ln_sz),
					&(pm->endian))))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_param pm;
	t_pt	**map;
	int		i;
	int		j;
	int 	blue;

	if (ac != 2)
		//gestion erreur trop de param
		return (1);
	if (!init_fdf(&pm))
		//gestion erreur initialisation
		return (1);
	parsing(av[1], &pm);
	//displayloop(pm);
	printf("cc\n");
	printf("pm.map : %p\n", pm.map);
	printf("w : %d\n", pm.map->w);
	printf("h : %d\n", pm.map->h);
	map = pm.map->pts;  
	i = 0;
	j = 0;
	while (i < pm.map->h)
	{
		j = 0;
		while (j < pm.map->w)
		{
			ft_putnbr(map[i][j].z);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	printf("---------------\n\n\n");
	i = 0;
	while (i < pm.map->h)
	{
		j = 0;
		while (j < pm.map->w)
		{
			ft_putnbr(map[i][j].color);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	blue = 0x0000FF;
	alter_pixel(&pm, blue, 10, 10);
	mlx_put_image_to_window(pm.sk, pm.wd, pm.im, 0, 0);
	mlx_hook(pm.wd, EV_KEY_PRESS, 0, key_hk, &pm);
	mlx_hook(pm.wd, EV_MOUSE_PRESS, 0, ms_hk, &pm);
	mlx_loop(pm.sk);
	return (0);
}
