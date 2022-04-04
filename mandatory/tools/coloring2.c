/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:13:12 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/04 03:13:43 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int    *colors_palette6(void)
{
	static int    arr[5];

	arr[0] = 0x00f2120d;
	arr[1] = 0x00ef7626;
	arr[2] = 0x00faed03;
	arr[3] = 0x000af508;
	arr[4] = 0x00051ac3;
	return (arr);
}

int coloring(int keycode, t_vars *vars)
{
	if (keycode == 83)
	{
		vars->palette = 16; 
		vars->colors = colors_palette1();
		mlx_clear_window(vars->mlx, vars->win);
		manage_sets(vars); 
	}
	else if (keycode == 84)
	{
		vars->palette = 21;
		vars->colors = colors_palette2();
		mlx_clear_window(vars->mlx, vars->win);
		manage_sets(vars); 
	}
	else if (keycode == 85)
	{
		vars->palette = 16; 
		vars->colors = colors_palette3();
		mlx_clear_window(vars->mlx, vars->win);
		manage_sets(vars); 
	}
	else if (keycode == 86)
	{
		vars->palette = 29; 
		vars->colors = colors_palette4();
		mlx_clear_window(vars->mlx, vars->win);
		manage_sets(vars); 
	}
	else if (keycode == 87)
	{
		vars->palette = 8; 
		vars->colors = colors_palette5();
		mlx_clear_window(vars->mlx, vars->win);
		manage_sets(vars); 
	}
	move(keycode, vars);
	return (vars->color);
}
