/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel_next(t_mlx mlx, int x, int y, int color)
{
	if (color < 80)
	{
		mlx.img[(int)(x * 4 + y * mlx.size)] = 0;
		mlx.img[(int)(x * 4 + y * mlx.size) + 1] = 51;
		mlx.img[(int)(x * 4 + y * mlx.size) + 2] = 102;
	}
	else
	{
		mlx.img[(int)(x * 4 + y * mlx.size)] = 255;
		mlx.img[(int)(x * 4 + y * mlx.size) + 1] = 255;
		mlx.img[(int)(x * 4 + y * mlx.size) + 2] = 255;
	}
}

void			draw_pixel(t_mlx mlx, int x, int y, int color)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	if (color <= 0)
	{
		mlx.img[(int)(x * 4 + y * mlx.size)] = 255;
		mlx.img[(int)(x * 4 + y * mlx.size) + 1] = 0;
		mlx.img[(int)(x * 4 + y * mlx.size) + 2] = 0;
	}
	else if (color < 15)
	{
		mlx.img[(int)(x * 4 + y * mlx.size)] = 102;
		mlx.img[(int)(x * 4 + y * mlx.size) + 1] = 204;
		mlx.img[(int)(x * 4 + y * mlx.size) + 2] = 255;
	}
	else if (color < 60)
	{
		mlx.img[(int)(x * 4 + y * mlx.size)] = 0;
		mlx.img[(int)(x * 4 + y * mlx.size) + 1] = 153;
		mlx.img[(int)(x * 4 + y * mlx.size) + 2] = 0;
	}
	else
		draw_pixel_next(mlx, x, y, color);
}
