/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:27:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/03 21:55:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void    burningship_set(t_vars *vars)
{
    int     x = 0;
    int     y = 0;
    double  tmp = 0;
    
    while (y < vars->height)
    {
        x = 0;
        while (x < vars->width)
        {
            vars->cr = (x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min) + vars->move_x;
            vars->ci = (y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min) + vars->move_y;
            vars->zr = 0;
            vars->zi = 0;
            vars->i = 0;
            while (vars->zr * vars->zr + vars->zi * vars->zi <= 4 && vars->i < vars->max_i)
            {
                tmp = vars->zr;
                vars->zr = fabs(vars->zr * vars->zr - vars->zi * vars->zi + vars->cr);
                vars->zi = fabs(2 * vars->zi * tmp + vars->ci);                 
                if (vars->zr * vars->zr + vars->zi * vars->zi >= 4) // ila kan kharej range or the M set => display it
                {
                    vars->color = vars->colors[vars->i % vars->palette];
                    my_mlx_pixel_put(&vars->image, x, y, vars->color);
                }
                else
                    my_mlx_pixel_put(&vars->image, x, y, 0xFFFFFF);
                vars->i++;
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}