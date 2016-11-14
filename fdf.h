/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

# define HEIGHT 720
# define WIDTH 1080

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*ptr_img;
	char	*img;
	int		height;
	int		width;
	int		bpp;
	int		size;
	int		endian;
}				t_mlx;

typedef struct	s_list
{
	int				x;
	int				y;
	int				z;
	int				tmp_z;
	int				un;
	struct s_list	*next;
}				t_list;

typedef struct	s_matrice
{
	double a1;
	double a2;
	double a3;
	double a4;
	double b1;
	double b2;
	double b3;
	double b4;
	double c1;
	double c2;
	double c3;
	double c4;
	double d1;
	double d2;
	double d3;
	double d4;
}				t_matrice;

typedef struct	s_param
{
	int		**tab;
	int		nbr_lines;
	int		size_line;
	int		space;
	int		t_x;
	int		t_y;
	double	degre_x;
	double	degre_y;
	t_mlx	mlx;
	t_list	*list;
}				t_param;

typedef struct	s_list2
{
	int x;
	int y;
	int tmp_z;
}				t_list2;

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_store
{
	int fdf_x;
	int fdf_y;
	int win_x;
	int win_y;
	int begin_x;
	int begin_y;
}				t_store;

int				t_list_size(t_list *begin_list);
void			check_contenu_list(t_list *toto);
t_param			*check_file(char *file);
int				**tab_points(char *file, t_param *p);
void			draw_line_v(t_param *p);
void			draw_line_h(t_param *p);
void			ft_list_clear(t_list **begin_list);
t_list			*list_coord_store(t_param *p);
void			draw_pixel(t_mlx mlx, int x, int y, int z);
t_list			*convert_coord(t_param *p);
void			apply_matrices(t_param *p);
void			draw_reload(t_param *p);
void			rotate_x_up(t_param *p);
void			rotate_x_down(t_param *p);
void			rotate_y_up(t_param *p);
void			rotate_y_down(t_param *p);
void			zoom_up(t_param *p);
void			zoom_down(t_param *p);
void			translate_p_x(t_param *p);
void			translate_n_x(t_param *p);
void			translate_p_y(t_param *p);
void			translate_n_y(t_param *p);
void			ft_error(int i);

#endif
