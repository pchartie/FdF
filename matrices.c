/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_matrice	matrice_y(t_param *p)
{
	t_matrice m;

	m.a1 = cos(p->degre_y);
	m.a2 = 0;
	m.a3 = sin(p->degre_y);
	m.a4 = 0;
	m.b1 = 0;
	m.b2 = 1;
	m.b3 = 0;
	m.b4 = 0;
	m.c1 = -sin(p->degre_y);
	m.c2 = 0;
	m.c3 = cos(p->degre_y);
	m.c4 = 0;
	m.d1 = 0;
	m.d2 = 0;
	m.d3 = 0;
	m.d4 = 1;
	return (m);
}

static t_matrice	matrice_x(t_param *p)
{
	t_matrice m;

	m.a1 = 1;
	m.a2 = 0;
	m.a3 = 0;
	m.a4 = 0;
	m.b1 = 0;
	m.b2 = cos(p->degre_x);
	m.b3 = -sin(p->degre_x);
	m.b4 = 0;
	m.c1 = 0;
	m.c2 = sin(p->degre_x);
	m.c3 = cos(p->degre_x);
	m.c4 = 0;
	m.d1 = 0;
	m.d2 = 0;
	m.d3 = 0;
	m.d4 = 1;
	return (m);
}

static t_list		*rotate(t_list *l, t_matrice m)
{
	double x;
	double y;
	double z;
	double un;

	x = l->x * m.a1 + l->y * m.a2 + l->z * m.a3 + l->un * m.a4;
	y = l->x * m.b1 + l->y * m.b2 + l->z * m.b3 + l->un * m.b4;
	z = l->x * m.c1 + l->y * m.c2 + l->z * m.c3 + l->un * m.c4;
	un = l->x * m.d1 + l->y * m.d2 + l->z * m.d3 + l->un * m.d4;
	l->x = x;
	l->y = y;
	l->z = z;
	l->un = un;
	return (l);
}

t_list				*convert_coord(t_param *p)
{
	t_list *list_x;
	t_list *list_y;

	list_x = rotate(p->list, matrice_x(p));
	list_y = rotate(p->list, matrice_y(p));
	return (list_y);
}
