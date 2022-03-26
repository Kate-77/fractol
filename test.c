/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:27:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/26 22:03:27 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

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
}

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

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int mouse_hook(int x, int y, t_vars *vars)
{
	if (x <= 999 && y <= 999)
    {
        vars->mouse_x = (double)x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min;
        vars->mouse_y = (double)y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min; 
        printf("mousex: %f mousey: %f\n", vars->mouse_x, vars->mouse_y); 
    }
    return(0);
}

void    mandelbrot_set(t_vars *vars)
{
    int     i = 0;
    double  cx, cy;
    int     x = 0;
    int     y = 0;
    double  zr = 0;
    double  zi = 0;
    double  tmp = 0;
    int     color;
    
    while (y < vars->height)
    {
        x = 0;
        while (x < vars->width)
        {
            cx= (x / (vars->width / (vars->x_max - vars->x_min)) + vars->x_min);
            cy= (y / (vars->height / (vars->y_max - vars->y_min)) + vars->y_min);
            zr = 0;
            zi = 0;
            i = 0;
            while (zr*zr + zi*zi <= 4 && i < vars->max_i)
            {
                tmp = zr;
                zr = zr*zr - zi*zi + cx;
                zi = 2 * zi * tmp + cy;                 
                if (zr*zr + zi*zi >= 4) // ila kan kharej range or the M set => display it
                {
                    color = i * 255 / vars->max_i;
                    //color = 255 - i * 255 / vars->max_i;
                    //printf("color = %d\n", color);
                    //color = ft_color(i);
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
    mlx_put_image_to_window(vars->mlx,  vars->win, vars->image.img, 0, 0);
}

double interpolate(double start, double end, double interpolation)
{
	double	result;

	result = start + ((end - start) * interpolation);
	printf("result = %f\n", result);
    return (result);
}

void applyZoom(t_vars *vars)
{
     //double interpolation = 1.0 / vars->zoom;
	 //printf("inter : %f", interpolation);
     vars->x_min = interpolate(vars->mouse_x, vars->x_min, vars->zoom);
     vars->y_min = interpolate(vars->mouse_y, vars->y_min, vars->zoom);
     vars->x_max = interpolate(vars->mouse_x, vars->x_max, vars->zoom);
     vars->y_max = interpolate(vars->mouse_y, vars->y_max, vars->zoom);
     //printf("xmin: %d\n ymin: %d\n xmax: %d\n", vars->x_min, vars->y_min, vars->x_max);
}

int zooming(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4)
    {
   		printf("4 : %d\n", keycode);
    	vars->zoom = 1.5;
    	applyZoom(vars);
    	mlx_clear_window(vars->mlx, vars->win);
    	mandelbrot_set(vars);
	}
    if (keycode == 5)
    {
        printf("5 : %d\n", keycode);
        vars->zoom = 1.0/1.5;
        applyZoom(vars);
        mlx_clear_window(vars->mlx, vars->win);
        mandelbrot_set(vars);
    }
    return (0);
}

int main()
{
    t_vars  *vars;
    vars = malloc(sizeof(t_vars));
    initialize(vars);
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FRACTOL");
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
    vars->image.addr = mlx_get_data_addr(vars->image.img, &vars->image.bits_per_pixel, &vars->image.line_length,&vars->image.endian);
    mandelbrot_set(vars);

    //mlx_mouse_hook(vars->win, mouse_hook, &vars);
	mlx_hook(vars->win, 6, 0, mouse_hook, vars);
    mlx_hook(vars->win, 4, 0, zooming, vars); 
	mlx_hook(vars->win, 17, 0, destroy, vars);
	mlx_key_hook(vars->win, shutdown, vars);
    mlx_loop(vars->mlx);
    return(0);
}