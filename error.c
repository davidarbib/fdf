/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:56:00 by darbib            #+#    #+#             */
/*   Updated: 2019/08/19 16:38:13 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "include/fdf.h"

void	ext_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	gnl_error(int gnl, char *line, t_line *head)
{
	if (!gnl && !head)
		ext_error("Empty file");
	if (gnl == -1)
	{
		if (line)
			free(line);
		if (head)
			del_lines(head);
		ext_error("gnl error");
	}
}

void	data_error(t_line *head, char *line)
{
	if (head)
		del_lines(head);
	if (line)
		free(line);
	ext_error("invalid data");
}

void	height_error(long j, char *line, t_line *head)
{
	if (j > INT_MAX)
	{
		if (line)
			free(line);
		if (head)
			del_lines(head);
		ext_error("map height must be an int");
	}
}

void	try_split(int win_i , t_param *pm, t_line *head, int j)
{
	if (win_i < 1)
	{
		(void)head;
		//del_lines(head);
		if ( win_i >= NOTRECT)
			del_map(pm->map, j - 1);
		else
			del_map(pm->map, j);
		//free(pm->wd);
	}
	//while (1) {}
	if (win_i == ONECOL)
		ext_error("map must have two columns at least");
	if (win_i == WNOINT)
		ext_error("map width must be an int");
	if (win_i == NOTRECT)
		ext_error("map must be rectangular");
	if (win_i == LINEALOC)
		ext_error("points line allocation problem");
	if (win_i == INVDATA)
		ext_error("invalid data");
}
