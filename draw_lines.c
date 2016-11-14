/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_segment(t_mlx mlx, t_list2 list, int x2, int y2)
{
	t_coord	d;
	t_coord	s;
	t_coord	err;

	d.x = (list.x - x2 >= 0 ? list.x - x2 : x2 - list.x);
	d.y = (list.y - y2 >= 0 ? list.y - y2 : y2 - list.y);
	s.x = (list.x < x2 ? 1 : -1);
	s.y = (list.y < y2 ? 1 : -1);
	err.x = (d.x > d.y ? d.x : -d.y) / 2;
	draw_pixel(mlx, x2, y2, list.tmp_z);
	while ((list.x != x2 || list.y != y2))
	{
		draw_pixel(mlx, list.x, list.y, list.tmp_z);
		err.y = err.x;
		if (err.y > -d.x)
		{
			err.x -= d.y;
			list.x += s.x;
		}
		if (err.y < d.y)
		{
			err.x += d.x;
			list.y += s.y;
		}
	}
}

static t_list	*find_maillon(t_param *p)
{
	t_list	*list_dest;
	int		i;

	i = 1;
	list_dest = p->list;
	while (list_dest != NULL && i < (p->size_line + 1))
	{
		list_dest = list_dest->next;
		i++;
		if (list_dest == NULL)
			return (p->list);
	}
	i++;
	return (list_dest);
}

void			draw_line_v(t_param *p)
{
	t_list		*list_dest;
	t_list2		list2;
	t_list		*save_pos;

	save_pos = p->list;
	while (p->list->next != NULL)
	{
		list2.x = p->list->x;
		list2.y = p->list->y;
		list2.tmp_z = p->list->tmp_z;
		list_dest = find_maillon(p);
		draw_segment(p->mlx, list2, list_dest->x, list_dest->y);
		p->list = p->list->next;
	}
	p->list = save_pos;
}

void			draw_line_h(t_param *p)
{
	int			i;
	t_list		*save_pos;
	t_list2		list2;

	i = 1;
	save_pos = p->list;
	while (p->list->next != NULL)
	{
		if (i % p->size_line != 0)
		{
			list2.x = p->list->x;
			list2.y = p->list->y;
			list2.tmp_z = p->list->tmp_z;
			draw_segment(p->mlx, list2, p->list->next->x, p->list->next->y);
		}
		p->list = p->list->next;
		i++;
	}
	p->list = save_pos;
}

void			draw_reload(t_param *p)
{
	mlx_destroy_image(p->mlx.init, p->mlx.ptr_img);
	p->mlx.ptr_img = mlx_new_image(p->mlx.init, p->mlx.width, p->mlx.height);
	ft_list_clear(&p->list);
	p->list = list_coord_store(p);
	apply_matrices(p);
	draw_line_h(p);
	draw_line_v(p);
	mlx_put_image_to_window(p->mlx.init, p->mlx.win, p->mlx.ptr_img, 0, 0);
}
