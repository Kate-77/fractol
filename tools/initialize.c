/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:25:28 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/01 22:14:53 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_start(t_vars *vars)
{
    initialize(vars);
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FRACTOL");
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
    vars->image.addr = mlx_get_data_addr(vars->image.img, &vars->image.bits_per_pixel, &vars->image.line_length,&vars->image.endian);
    return ;
}

void    initialize(t_vars *vars)
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
}

void    get_c1(t_vars *vars)
{
    vars->cr = -0.4;
    vars->ci = 0.6;
    return;
}

void    get_c2(t_vars *vars)
{
    vars->cr = -0.8;
    vars->ci = 0.156;
    return;
}

void    get_c3(t_vars *vars)
{
    vars->cr = 0.285;
    vars->ci = 0.01;
    return;
}

void    get_c4(t_vars *vars)
{
    vars->cr = -0.835 ;
    vars->ci = -0.2321;
    return;
}