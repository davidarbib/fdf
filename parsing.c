/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:04:51 by darbib            #+#    #+#             */
/*   Updated: 2019/07/11 01:15:28 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include "include/fdf.h"
#include "libft/include/get_next_line.h"
#include "libft/include/libft.h"

static t_line		*store_count_lines(int fd, long *j)
{
	t_line 	*head;
	t_line	*node;
	int		gnl;
	char	*line;

	line = NULL;
	head = NULL;
	while ((gnl = get_next_line(fd, &line)))
	{
		printf("line : ()%s()\n", line);
		node = new_line(line);
		if (*j == 0)
			head = node;
		node = node->next;
		*j += 1;
	}
	gnl_error(gnl, line, head);
	height_error(*j, line, head);
	return (head);
}

static t_line		*file_read(int fd, t_param *pm)
{
	t_line	*head;
	long	j;

	j = 0;
	head = store_count_lines(fd, &j);
	if (!(pm->map = (t_map *)malloc(sizeof(t_map))))
	{
		del_lines(head);
		ext_error("map allocation error");
	}
	if (!(pm->map->pts = (t_pt **)malloc(sizeof(t_pt *) * j)))
	{
		del_map(&(pm->map));
		del_lines(head);
		ext_error("pts allocation error");
	}
	pm->map->h = j;
	pm->map->w = 0;
	return (head);
}

/*
**  
*/

static int		atoptl(char *line, t_pt *pts, int expect_i)
{
	int 	i;

	i = 0;
	while (*line)
	{
		pts[i].z = ft_atoi_spe(&line); 
		if (*line == SEPX)
		{
			if (!(*line + 1 == '0' && *line + 2 == 'X'))
				return (0);
			*line += 2;
			pts[i].color = ft_atoi_base_spe(&line, "0123456789ABCDEF");
			while (*line && *line != SEP)
				line++;
		}
		if (pts[i].color > INT_MAX || pts[i].z < INT_MIN || pts[i].z > INT_MAX)
			return (0);
		i++;
	}
	if (i != expect_i)
		return (0);
	return (1);
}

/*
** split the line
** and putaway (altitude, color) tuplet in pts[j]
** program exit if :
**  - less than 2 lines
**  - points number overflow int-max digit number
**  - map isnt a rectangle
**  - allocation problem
**  - invalid data in map
*/

static int		split_and_putaway(char *line, t_map *map, int j)
{
	char 		*p_line;
	long		i;

	//printf("line : ()%s()\n", line);
	i = 0;
	p_line = line;
	while (*p_line == SEP)
		p_line++;
	while (*p_line)
	{
		i = (*p_line != SEP && *(p_line + 1) == SEP)? (i + 1) : i;	
		p_line++;
	}
	if (i < 2)
		return (0);
	if (i > INT_MAX)
		return (-1);
	printf("cc\n");
	if (map->w != 0 && (int)i != map->w)
		return (-2);
	if (!(map->pts[j] == (t_pt *)malloc(sizeof(t_pt) * i)))
		return (-3);
	map->w = i;
	if (!(atoptl(line, map->pts[j], map->w)))
		return (-4);
	return (1);
}


int		parsing(char *fname, t_param *pm)
{
	int		fd;
	int		j;
	t_line  *head;
	t_line  *node;

	if ((fd = open(fname, O_RDONLY)) < 0)
		ext_error("fail to open");
	head = file_read(fd, pm);
	node = head;
	printf("node address : %p\n", node);
	j = 0;
	while (node)
	{
		printf("node->line : |%s|\n", node->line);
		printf("j : %d\n", j);
		try_split(split_and_putaway(node->line, pm->map, j), pm->map, head);
		node = node->next;
		j++;
	}
	return (1);
}
