/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:58:30 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/29 23:30:09 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_vars  *vars;
    vars = malloc(sizeof(t_vars));
    initialize(vars);
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FRACTOL");
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
    vars->image.addr = mlx_get_data_addr(vars->image.img, &vars->image.bits_per_pixel, &vars->image.line_length,&vars->image.endian);
    
    if (strcmp(argv[1], "mandelbrot") == 0)
        mandelbrot_set(vars);
    else if (strcmp(argv[1], "julia") == 0)
        julia1_set(vars);
    //mlx_key_hook(vars->win, ft_color, vars);
    //mlx_mouse_hook(vars->win, mouse_hook, &vars);
	mlx_hook(vars->win, 6, 0, mouse_hook, vars);
    mlx_hook(vars->win, 4, 0, zooming, vars); 
	mlx_hook(vars->win, 17, 0, destroy, vars);
    //mlx_key_hook(vars->win, ft_color, vars);
	mlx_key_hook(vars->win, shutdown, vars);
    mlx_loop(vars->mlx);
    return(0);
}