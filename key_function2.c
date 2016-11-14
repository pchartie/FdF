/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_up(t_param *p)
{
	p->space += 2;
	draw_reload(p);
}

void	zoom_down(t_param *p)
{
	p->space -= 2;
	draw_reload(p);
}

void	translate_p_x(t_param *p)
{
	p->t_x += 6;
	draw_reload(p);
}

void	translate_n_x(t_param *p)
{
	p->t_x -= 6;
	draw_reload(p);
}

void	translate_n_y(t_param *p)
{
	p->t_y -= 6;
	draw_reload(p);
}
