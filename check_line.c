/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:35:10 by darbib            #+#    #+#             */
/*   Updated: 2019/08/17 18:07:21 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/fdf.h"

static int		is_uphex(char c)
{
	char *hex_base;

	hex_base = "0123456789ABCDEF";
	while (*hex_base && c != *hex_base)
		hex_base++;
	if (!*hex_base)
		return (0);
	return (1);
}


static int		check_hex(char **line)
{
	char nb;

	if (**line != SEPX)
		return (1);
	*line += 1;
	if (**line != '0' || *(*line + 1) != 'x')
		return (0);
	*line += 2;
	nb = 0;
	while (**line && **line != SEP)
	{
		if (!is_uphex(**line))
			return (0);
		*line += 1;
		nb++;
	}
	if (nb != 6)
		return (0);
	return (1);
}

char			*is_valid_data(t_line *head, char *line)
{
	char	*b_line;
	int		nb_dig;	

	if ((!line || !(*line)) && !(head->line))
		data_error(head, line);	
	nb_dig = 0;
	b_line = line;
	while (*line)
	{
		if (*line == SEP || *line == SEPX)
			nb_dig = 0;
		if (ft_isdigit(*line))
			nb_dig++;
		if (nb_dig > 11)
			data_error(head, b_line);	
		if (*line == '-' && !ft_isdigit(*(line + 1)))
			data_error(head, b_line);	
		if (!ft_isdigit(*line) && *line != SEP && *line != SEPX && *line != '-') 
			data_error(head, b_line);	
		if (!(check_hex(&line)))
			data_error(head, b_line);	
		if (!*line)
			break;
		line++;
	}
	return (b_line);
}

/*
int main()
{
	char *hex = ",0xFFAAFF";
	char *hex1 = ",0xFF9900";
	char *no_hex = ",xFFFFFF";
	char *no_hex1 = ",0xFFF";
	char *no_hex2 = ",0FFFFFF";
	printf("hex : %d\n", check_hex(&hex));
	printf("hex1 : %d\n", check_hex(&hex1));
	printf("no hex : %d\n", check_hex(&no_hex));
	printf("no hex1 : %d\n", check_hex(&no_hex1));
	printf("no hex2 : %d\n", check_hex(&no_hex2));
	char *vdata = "0 5 -3 2,0x78FADC 35";
	char *vdata1 = "0,0xFFFFFF -65 0 2,0x78FADC 7";
	char *fdata = "0 5 -3 2,0x78DC 35";
	char *fdata1 = "0,0xFFFFFF -65 0 2, 7";
	char *fdata2 = "0 5 e 2,0x78FADC 35";
	printf("v : %d\n", is_valid_data(vdata));
	printf("v1 : %d\n", is_valid_data(vdata1));
	printf("f : %d\n", is_valid_data(fdata));
	printf("f1 : %d\n", is_valid_data(fdata1));
	printf("f2 : %d\n", is_valid_data(fdata2));
	return (0);
}
*/
