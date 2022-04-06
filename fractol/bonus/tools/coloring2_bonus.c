/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:58:31 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/06 02:01:22 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	*colors_palette6(void)
{
	static int	arr[5];

	arr[0] = 0x00fdcf58;
	arr[1] = 0x00c94700;
	arr[2] = 0x00f27d0c;
	arr[3] = 0x00800909;
	arr[4] = 0x00f07f13;
	return (arr);
}

int	coloring2(int keycode, t_vars *vars)
{
	if (keycode == 86)
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
	else if (keycode == 88)
	{
		vars->palette = 5;
		vars->colors = colors_palette6();
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
		vars->palette = 22;
		vars->colors = colors_palette2();
		manage_sets(vars);
	}
	else if (keycode == 85)
	{
		vars->palette = 16;
		vars->colors = colors_palette3();
		manage_sets(vars);
	}
	else
		coloring2(keycode, vars);
	move(keycode, vars);
	return (vars->color);
}
