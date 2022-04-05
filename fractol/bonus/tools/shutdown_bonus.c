/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:38:37 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/03 21:54:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int shutdown(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        //free(vars);
        exit(0);
    }
    return (0);
}

int destroy(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    //free(vars);
    exit(0);
    return (0);
}