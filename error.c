/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("usage: ./fdf file\n");
	if (i == 2)
		ft_putstr("empty file\n");
	if (i == 3)
		ft_putstr("error fd\n");
	if (i == 4)
		ft_putstr("error in the file\n");
	if (i == 5)
		ft_putstr("the file is to big: maximum number of points 30k\n");
	if (i == 6)
		ft_putstr("too large value of z\n");
	exit(0);
}
