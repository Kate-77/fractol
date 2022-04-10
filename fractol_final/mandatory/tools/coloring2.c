/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:13:12 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/05 03:50:32 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	coloring2(int keycode, t_vars *vars)
{
	if (keycode == 85)
	{
		vars->palette = 16;
		vars->colors = colors_palette3();
		manage_sets(vars);
	}
	else if (keycode == 86)
	{
		vars->palette = 29;
		vars->colors = colors_palette4();
		manage_sets(vars);
	}
	else if (keycode == 87)
	{
		vars->palette = 8;
		vars->colors = colors_palette5();
		manage_sets(vars);
	}
	return (vars->color);
}

int	coloring(int keycode, t_vars *vars)
{
	if (keycode == 83)
	{
		vars->palette = 16;
		vars->colors = colors_palette1();
		manage_sets(vars);
	}
	else if (keycode == 84)
	{
		vars->palette = 21;
		vars->colors = colors_palette2();
		manage_sets(vars);
	}
	else
		coloring2(keycode, vars);
	move(keycode, vars);
	return (vars->color);
}
