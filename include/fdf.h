/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:23:16 by darbib            #+#    #+#             */
/*   Updated: 2019/08/17 17:34:07 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include "key_macos.h"
# include <stdlib.h>

/*
** --- point in map ---
** store altitude and color in hexa
*/

typedef struct	s_pt	
{
	int			z;
	int			color;
}				t_pt;

/*
** --- lines of map file ---
** to store the lines read
** in parsing.c
*/

typedef struct	s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

/*
** --- about the map ---
** x, y : window-relative coordinates
** w, h : map width and map height
** pts : map points (altitude, color)
*/

typedef struct	s_map	
{
	int			x;
	int			y;
	int			w;
	int			h;
	t_pt		**pts;
}				t_map;

/*
** --- general params ---
** sk : X window connection
** wd : window
** map : obviously...
*/

typedef struct	s_param
{
	void		*sk;
	void		*wd;
	void		*im;
	char		*im_addr;
	t_map		*map;
	int			bpp;
	int			ln_sz;
	int			endian;
}				t_param;

/*
** --- event-management functions ---
** (exposure, keystroke, mouse and loop respectively)
*/

int		exp_hk(void *param);
int		key_hk(int keycode, t_param *param);
int		ms_hk(int button, int x,int y, void *param);
int		lp_hk(void *param);

/*
** ----- parsing specific -----
*/

int		ft_atoi_spe(char **str);
long 	ft_atoi_base_spe(char **str, const char *base);
void	parsing(char *fname, t_param *pm);
void	ext_error(char *msg);
void	gnl_error(int gnl, char *line, t_line *head);
void	height_error(long j, char *line, t_line *head);
void	try_split(int win_i, t_param *pm, t_line *head, int j);
void	del_lines(t_line *head);
t_line	*new_line(char *line);
char	*is_valid_data(t_line *head, char *line);
void	data_error(t_line *head, char *line);

/*
** ----------------------------------
*/

void	del_map(t_map *map, int j);
void	color_chars(unsigned int color, char *str);
void	alter_pixel(t_param *pm, unsigned int color, int x, int y);

/* 
** --- events codes ---
*/

# define EV_KEY_PRESS	2
# define EV_KEY_RELEA	3
# define EV_MOUSE_PRESS	4
# define EV_MOUSE_RELEA	5
# define EV_MOUSE_MOVE	6
# define EV_CLOSE_WIN	17

# define WIDTH	800
# define HEIGHT	400
# define SEP	' '
# define SEPX	','

/*
** --- error codes in split ---
*/

# define ONECOL		0
# define WNOINT 	-1
# define NOTRECT 	-2
# define LINEALOC 	-3
# define INVDATA 	-4

#endif
