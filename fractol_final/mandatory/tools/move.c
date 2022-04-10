/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:55:46 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/09 06:49:02 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int keycode, t_vars *vars)
{
	if (keycode == 126)
	{
		vars->move_y += -0.1;
		manage_sets(vars);
	}
	if (keycode == 125)
	{
		vars->move_y += 0.1;
		manage_sets(vars);
	}
	if (keycode == 124)
	{
		vars->move_x += 0.1;
		manage_sets(vars);
	}
	if (keycode == 123)
	{
		vars->move_x += -0.1;
		manage_sets(vars);
	}
	return ;
}
