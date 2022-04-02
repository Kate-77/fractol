/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:43:45 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/02 00:53:20 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    julia_set(t_vars *vars)
{
    int     x = 0;
    int     y = 0;
    double  tmp = 0;

    while (y < vars->height)
    {
        x = 0;
        while (x < vars->width)
        {
            vars->zr= (x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min);
            vars->zi= (y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min);
            vars->i = 0;
            while (vars->zr * vars->zr + vars->zi * vars->zi <= 4 && vars->i < vars->max_i)
            {
                tmp = vars->zr;
                vars->zr = vars->zr * vars->zr - vars->zi * vars->zi + vars->cr;
                vars->zi = 2 * vars->zi * tmp + vars->ci;                 
                if (vars->zr * vars->zr + vars->zi * vars->zi >= 4) // ila kan kharej range or the M set => display it
                {
                    vars->color = vars->colors[vars->i % vars->palette];
                    my_mlx_pixel_put(&vars->image, x, y, vars->color);
                }
                else
                {
                    my_mlx_pixel_put(&vars->image, x, y, 0x00000000);
                }
                vars->i++;
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}