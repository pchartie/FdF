/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*ft_create_elem(int x, int y, int z)
{
	t_list *list;

	if (z >= 10000000 || z <= -10000000)
		ft_error(6);
	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		list->x = x;
		list->y = y;
		list->z = z;
		list->un = 0;
		list->tmp_z = z;
	}
	return (list);
}

static void		ft_list_push_front(t_list **begin_list, int x, int y, int z)
{
	t_list *list;

	if (!begin_list)
		*begin_list = ft_create_elem(x, y, z);
	else
	{
		list = ft_create_elem(x, y, z);
		list->next = *begin_list;
		*begin_list = list;
	}
}

void			ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*temp;

	if (*begin_list == NULL)
		return ;
	list = *begin_list;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*begin_list = NULL;
}

static void		init_struct_store(t_store *s, t_param *p)
{
	p->list = NULL;
	s->win_x = WIDTH / 2;
	s->win_y = HEIGHT / 2;
	s->fdf_x = ((p->size_line - 1) * p->space) / 2;
	s->fdf_y = ((p->nbr_lines - 1) * p->space) / 2;
	s->begin_x = s->win_x - s->fdf_x;
	s->begin_y = s->win_y - s->fdf_y;
}

t_list			*list_coord_store(t_param *p)
{
	int		i;
	int		k;
	t_store	s;

	i = 0;
	k = 0;
	init_struct_store(&s, p);
	while (i < p->nbr_lines)
	{
		while (k < p->size_line)
		{
			ft_list_push_front(&p->list, (s.begin_x + p->t_x),
				(s.begin_y + p->t_y), p->tab[i][k]);
			s.begin_x += p->space;
			k++;
		}
		s.begin_x = s.win_x - s.fdf_x;
		s.begin_y += p->space;
		k = 0;
		i++;
	}
	return (p->list);
}
