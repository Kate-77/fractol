/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:26:17 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/06 02:06:31 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	vars->mouse_x = (double)x / (vars->width / (vars->x_max - vars->x_min))
		+ vars->x_min;
	vars->mouse_y = (double)y / (vars->height / (vars->y_max - vars->y_min))
		+ vars->y_min;
	return (0);
}
