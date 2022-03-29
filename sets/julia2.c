/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:48:57 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/29 23:22:08 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    julia2_set(t_vars *vars)
{
    int     i = 0;
    int     x = 0;
    int     y = 0;
    double  zr = 0;
    double  zi = 0;
    double  tmp = 0;
    double  cx = -0.8;
    double	cy = 0.156;
    int     color;
    // int     r,g,b;
    // int     clr;
    //int     *colors;

    //colors = colors_palette1();
    while (y < vars->height)
    {
        x = 0;
        while (x < vars->width)
        {
            zr= (x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min);
            zi= (y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min);
            i = 0;
            while (zr*zr + zi*zi <= 4 && i < vars->max_i)
            {
                tmp = zr;
                zr = zr*zr - zi*zi + cx;
                zi = 2 * zi * tmp + cy;                 
                if (zr*zr + zi*zi >= 4) // ila kan kharej range or the M set => display it
                {
                    //clr = ft_colors(i);
                    //color = i * clr / vars->max_i;
                    //color = i * 0x0f6b9e / 255;
                    //r = (i % 32) * 7;
                    //g = (i % 16) * 14;
                    //b = (i % 128) * 2;
                    color = create_trgb(1, 255 - i, 255 - i, 255);
                    //color = (i / vars->max_i) * 255;
                    //color = 255 - i * 255 / vars->max_i;
                    //color = i * 255 / vars->max_i;
                    //printf("color = %x\n", color);
                    //color = colors[i / 16];
                    my_mlx_pixel_put(&vars->image, x, y, color);
                }
                else
                {
                    my_mlx_pixel_put(&vars->image, x, y, 0xFFFFFF);
                }
                i++;
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}