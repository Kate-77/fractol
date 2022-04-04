/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:55:46 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/03 21:54:20 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	move(int keycode, t_vars *vars)
{
	if (keycode == 126)
	{
        vars->move_y += -0.3;
        mlx_clear_window(vars->mlx, vars->win);
        manage_sets(vars);
    }
	if (keycode == 125)
	{
        vars->move_y += 0.3;
        mlx_clear_window(vars->mlx, vars->win);
        manage_sets(vars);
    }
	if (keycode == 124)
    {
        vars->move_x += 0.3;
        mlx_clear_window(vars->mlx, vars->win);
        manage_sets(vars);
    }
	if (keycode == 123)
	{
        vars->move_x += -0.3;
        mlx_clear_window(vars->mlx, vars->win);
        manage_sets(vars);
    }
	return;
}