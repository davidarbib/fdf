/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:56:00 by darbib            #+#    #+#             */
/*   Updated: 2019/07/09 17:41:53 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "include/fdf.h"

void	ext_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	gnl_error(int gnl, char *line, t_line *head)
{
	if (gnl == -1)
	{
		if (line)
			free(line);
		if (head)
			del_lines(head);
		ext_error("gnl error");
		exit(EXIT_FAILURE);
	}
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

void	try_split(int error, t_map *map, t_line *head)
{
	if (error < 1)
	{
		del_lines(head);
		del_map(&map);
	}
	if (error == ONECOL)
		ext_error("map must have two columns at least");
	if (error == WNOINT)
		ext_error("map width must be an int");
	if (error == NOTRECT)
		ext_error("map must be rectangular");
	if (error == LINEALOC)
		ext_error("points line allocation problem");
	if (error == INVDATA)
		ext_error("invalid data");
}
