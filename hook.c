/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:29:28 by darbib            #+#    #+#             */
/*   Updated: 2019/06/27 15:04:42 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void exp_hk(void *param)
{
}
*/
int key_hk(int keycode, void *param)
{
	(void)param;
	printf("keycode : %d\n", keycode);
	return (1);
}

int	 ms_hk(int button, int x, int y, void *param)
{
	(void)param;
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

