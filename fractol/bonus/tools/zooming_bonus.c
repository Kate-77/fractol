/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooming_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:28:26 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/04 03:06:45 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

double interpolate(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void apply_zoom(t_vars *vars)
{
     vars->x_min = interpolate(vars->mouse_x, vars->x_min, vars->zoom);
     vars->y_min = interpolate(vars->mouse_y, vars->y_min, vars->zoom);
     vars->x_max = interpolate(vars->mouse_x, vars->x_max, vars->zoom);
     vars->y_max = interpolate(vars->mouse_y, vars->y_max, vars->zoom);
}

int zooming(int keycode, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
	if (keycode == 4)
    {
    	vars->zoom = 1.5;
    	apply_zoom(vars);
    	mlx_clear_window(vars->mlx, vars->win);
    	manage_sets(vars);
	}
    if (keycode == 5)
    {
        vars->zoom = 1.0/1.5;
        apply_zoom(vars);
        mlx_clear_window(vars->mlx, vars->win);
        manage_sets(vars);
    }
    return (0);
}