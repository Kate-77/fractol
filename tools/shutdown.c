/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:38:37 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/28 18:24:54 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fractol.h"

int shutdown(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        free(vars->mlx);
        exit(0);
    }
    return (0);
}

int destroy(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    free(vars->mlx);
    exit(0);
    return (0);
}