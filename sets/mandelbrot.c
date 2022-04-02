/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:27:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/02 02:01:26 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandelbrot_set(t_vars *vars)
{
    double  cx, cy;
    int     x = 0;
    int     y = 0;
    double  zr = 0;
    double  zi = 0;
    double  tmp = 0;


    while (y < vars->height)
    {
        x = 0;
        while (x < vars->width)
        {
            cx= (x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min) + vars->move_x;
            cy= (y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min) + vars->move_y;
            zr = 0;
            zi = 0;
            vars->i = 0;
            while (zr*zr + zi*zi <= 4 && vars->i < vars->max_i)
            {
                tmp = zr;
                zr = zr*zr - zi*zi + cx;
                zi = 2 * zi * tmp + cy;                 
                if (zr*zr + zi*zi >= 4)
                {
                    vars->color = vars->colors[vars->i % vars->palette];
                    my_mlx_pixel_put(&vars->image, x, y, vars->color);
                }
                else
                {
                    my_mlx_pixel_put(&vars->image, x, y, 0xFFFFFF);
                }
                vars->i++;
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}