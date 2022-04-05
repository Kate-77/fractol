/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:25:28 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/05 04:05:46 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_start(t_vars *vars)
{
	initialize(vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FRACTOL");
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel, &vars->image.line_length,
			&vars->image.endian);
	return ;
}

void	initialize(t_vars *vars)
{
	vars->x_min = -2.0;
	vars->x_max = 2.0;
	vars->y_min = -2.0;
	vars->y_max = 2.0;
	vars->height = 1000;
	vars->width = 1000;
	vars->zoom = 1.0;
	vars->max_i = 100;
	vars->i = 0;
	vars->color = 0;
	vars->zr = 0;
	vars->zi = 0;
	vars->palette = 16;
	vars->colors = colors_palette1();
	vars->move_x = 0.0;
	vars->move_y = 0.0;
	vars->msg = "\n\tUnvalid argument!\n\nTo select Mandelbrot Set; enter:\n\t \
		\"mandelbrot\"\n\nTo select Julia Set; enter:\n\t\"julia1\" \
	   	for c = -0.4 + 0.6*i\n\t\"julia2\" for c = -0.8 + 0.156*i\n\t\"julia3\" \
		for c = 0.285 + 0.01*i\n\t\"julia4\" for c = -0.835 - 0.2321*i\n";
}

void	manage_sets(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->set == 1)
		mandelbrot_set(vars);
	else if (vars->set == 2)
		julia_set(vars);
	return ;
}
