/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:26:17 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/09 06:29:21 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	vars->mouse_x = (double)x / (vars->width / (vars->x_max - vars->x_min))
		+ vars->x_min;
	vars->mouse_y = (double)y / (vars->height / (vars->y_max - vars->y_min))
		+ vars->y_min;
	return (0);
}

void	get_c5(t_vars *vars)
{
	vars->cr = 0.0 ;
	vars->ci = -0.8;
	return ;
}

void	get_c6(t_vars *vars)
{
	vars->cr = -0.70176 ;
	vars->ci = -0.3842;
	return ;
}
