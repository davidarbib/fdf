/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:07:55 by darbib            #+#    #+#             */
/*   Updated: 2019/07/11 19:01:56 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

int		init_fdf(t_param *pm)
{
	if (!(pm->sk = mlx_init()))
		return (0);
	if (!(pm->wd = mlx_new_window(pm->sk, WIDTH, HEIGHT, "test")))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_param pm;
	t_pt	**map;
	int		i;
	int		j;

	if (ac != 2)
		//gestion erreur trop de param
		return (1);
	if (!init_fdf(&pm))
		//gestion erreur initialisation
		return (1);
	if (!parsing(av[1], &pm))
		//erreur de parsing
		return (1);
	printf("cc\n");
	map = pm.map->pts;  
	i = 0;
	j = 0;
	printf("w : %d\n", pm.map->w); 
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
	mlx_string_put(pm.sk, pm.wd, 0, 0, 0xFF0000, "coucou");
	mlx_hook(pm.wd, EV_KEY_PRESS, 0, key_hk, &pm);
	mlx_hook(pm.wd, EV_MOUSE_PRESS, 0, ms_hk, &pm);
	mlx_loop(pm.sk);
	return (0);
}
