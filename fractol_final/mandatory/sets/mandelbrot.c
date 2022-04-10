/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:27:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/09 05:20:48 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calcul_man(t_vars *vars, int x, int y, double tmp)
{
	vars->zr = 0;
	vars->zi = 0;
	vars->i = 0;
	while (vars->zr * vars->zr + vars->zi * vars->zi <= 4
		&& vars->i < vars->max_i)
	{
		tmp = vars->zr;
		vars->zr = vars->zr * vars->zr - vars->zi * vars->zi + vars->cr;
		vars->zi = 2 * vars->zi * tmp + vars->ci;
		if (vars->zr * vars->zr + vars->zi * vars->zi >= 4)
		{
			vars->color = vars->colors[vars->i % vars->palette];
			my_mlx_pixel_put(&vars->image, x, y, vars->color);
		}
		else
			my_mlx_pixel_put(&vars->image, x, y, 0x00000000);
		vars->i++;
	}
	return ;
}

void	mandelbrot_set(t_vars *vars)
{
	int		y;
	int		x;
	double	tmp;

	x = 0;
	y = 0;
	tmp = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			vars->cr = (x / (vars->width / (vars->x_max - vars->x_min))
					+ vars->x_min) + vars->move_x;
			vars->ci = (y / (vars->height / (vars->y_max - vars->y_min))
					+ vars->y_min) + vars->move_y;
			calcul_man(vars, x, y, tmp);
			x++;
		}
		calcul_man(vars, x, y, tmp);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}
