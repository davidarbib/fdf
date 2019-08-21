/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:51:59 by darbib            #+#    #+#             */
/*   Updated: 2019/08/19 16:12:48 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/get_next_line.h"
#include <stdio.h>

static int		init_gnl(char **after_eol, char **line, int *eol)
{
	char *eol_addr;

	*line = NULL;
	if (!*after_eol)
	{
		if (!(*line = ft_strdup("")))
			return (0);
	}
	else
	{
		if (!(*line = ft_strdup(*after_eol)))
			return (0);
		ft_strdel(after_eol);
		if (!*line)
			return (0);
		if ((eol_addr = ft_strchr(*line, '\n')))
			*eol = eol_addr - *line; 
	}
	return (1);
}

static int		rd(int fd, int *eol, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int 	ret;
	int 	i;
	int 	d;

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[BUFF_SIZE] = 0;
	if ((ret && (int)ft_strlen(buf) != ret) 
		|| !(*line = ft_realloc(*line, ft_strlen(*line) + 1, ret)))
		return (-1);
	d = 0;
	while ((*line)[d])
		d++;
	i = -1;
	while (++i < ret)
	{
		if ((i + d) > 2147483640)
			return (-1);
		if (*eol < 0 && buf[i] == '\n')
			*eol = i + d;
		(*line)[i + d] = buf[i]; 
	}
	(*line)[i + d] = 0;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*after_eol; 
	size_t			ret;
	int				eol;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	eol = -1;
	if (!(init_gnl(&after_eol, line, &eol)))
		return (-1);
	ret = 1;
	while (eol < 0 && ret > 0)
	{
		if ((ret = rd(fd, &eol, line)) == -1)
			return (-1);
	}
	if (eol >= 0)
	{
		if (!(after_eol = ft_strdup(*line + eol + 1)))
			return (-1);
		(*line)[eol] = 0;
		return (1); 
	}
	return (0);
}
