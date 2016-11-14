/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_up(t_param *p)
{
	p->degre_x += 0.03;
	draw_reload(p);
}

void	rotate_x_down(t_param *p)
{
	p->degre_x -= 0.03;
	draw_reload(p);
}

void	rotate_y_up(t_param *p)
{
	p->degre_y += 0.03;
	draw_reload(p);
}

void	rotate_y_down(t_param *p)
{
	p->degre_y -= 0.03;
	draw_reload(p);
}

void	translate_p_y(t_param *p)
{
	p->t_y += 6;
	draw_reload(p);
}
