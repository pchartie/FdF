/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		mlx_setup(t_param *p)
{
	p->mlx.init = mlx_init();
	p->mlx.width = WIDTH;
	p->mlx.height = HEIGHT;
	p->mlx.win = mlx_new_window(p->mlx.init, p->mlx.width,
					p->mlx.height, "FdF");
	p->mlx.ptr_img = mlx_new_image(p->mlx.init, p->mlx.width, p->mlx.height);
	p->mlx.img = mlx_get_data_addr(p->mlx.ptr_img, &p->mlx.bpp,
					&p->mlx.size, &p->mlx.endian);
}

void			apply_matrices(t_param *p)
{
	t_list *save_pos;

	save_pos = p->list;
	while (p->list != NULL)
	{
		p->list = convert_coord(p);
		p->list = p->list->next;
	}
	p->list = save_pos;
}

static int		key_hook(int keycode, t_param *p)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 8)
		zoom_up(p);
	if (keycode == 7)
		zoom_down(p);
	if (keycode == 126)
		rotate_x_up(p);
	if (keycode == 125)
		rotate_x_down(p);
	if (keycode == 124)
		rotate_y_up(p);
	if (keycode == 123)
		rotate_y_down(p);
	if (keycode == 2)
		translate_p_x(p);
	if (keycode == 0)
		translate_n_x(p);
	if (keycode == 1)
		translate_p_y(p);
	if (keycode == 13)
		translate_n_y(p);
	return (0);
}

static t_param	*init_main_struct(char *argv)
{
	t_param *p;

	p = (t_param*)malloc(sizeof(t_param));
	p = check_file(argv);
	if (p->nbr_lines * p->size_line > 30000)
		ft_error(5);
	p->tab = tab_points(argv, p);
	p->degre_x = 0.4;
	p->degre_y = 0.6;
	p->t_x = 0;
	p->t_y = 0;
	if (p->nbr_lines * p->size_line < 300)
		p->space = 25;
	else
		p->space = 4;
	p->list = list_coord_store(p);
	return (p);
}

int				main(int argc, char **argv)
{
	t_param *p;

	if (argc != 2)
		ft_error(1);
	p = init_main_struct(argv[1]);
	mlx_setup(p);
	apply_matrices(p);
	draw_line_h(p);
	draw_line_v(p);
	mlx_put_image_to_window(p->mlx.init, p->mlx.win, p->mlx.ptr_img, 0, 0);
	mlx_hook(p->mlx.win, 2, 1, key_hook, p);
	mlx_loop(p->mlx.init);
	return (0);
}
