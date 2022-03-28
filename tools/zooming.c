/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:28:26 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/28 18:30:15 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double interpolate(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void applyZoom(t_vars *vars)
{
     vars->x_min = interpolate(vars->mouse_x, vars->x_min, vars->zoom);
     vars->y_min = interpolate(vars->mouse_y, vars->y_min, vars->zoom);
     vars->x_max = interpolate(vars->mouse_x, vars->x_max, vars->zoom);
     vars->y_max = interpolate(vars->mouse_y, vars->y_max, vars->zoom);
}

int zooming(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4)
    {
    	vars->zoom = 1.5;
    	applyZoom(vars);
    	mlx_clear_window(vars->mlx, vars->win);
    	mandelbrot_set(vars);
	}
    if (keycode == 5)
    {
        vars->zoom = 1.0/1.5;
        applyZoom(vars);
        mlx_clear_window(vars->mlx, vars->win);
        mandelbrot_set(vars);
    }
    return (0);
}