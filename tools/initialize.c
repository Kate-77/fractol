/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:25:28 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/29 23:04:04 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
}