/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:58:30 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/02 04:55:26 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void    manage_julia(char **argv, t_vars *vars)
{
    if (ft_strcmp(argv[1], "julia1") == 0)
    {
        vars->set = 2;
        get_c1(vars);
        julia_set(vars);
    }
    else if (ft_strcmp(argv[1], "julia2") == 0)
    {
        vars->set = 2;
        get_c2(vars);
        julia_set(vars);
    }
    else if (ft_strcmp(argv[1], "julia3") == 0)
    {
        vars->set = 2;
        get_c3(vars);
        julia_set(vars);
    }
    else if (ft_strcmp(argv[1], "julia4") == 0)
    {
        vars->set = 2;
        get_c4(vars);
        julia_set(vars);
    }
    else
    {
        ft_putstr("\n\tUnvalid argument!\n\nTo select Mandelbrot Set; enter:\n\t\"mandelbrot\"\n\nTo select Julia Set; enter:\n\t\"julia1\"\n\t\"julia2\"\n\t\"julia3\"\n\t\"julia4\"\n", 1);
        exit(0);
    }
}

void    manage(char **argv, t_vars *vars)
{
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
        vars->set = 1;
        mandelbrot_set(vars);
    }
    else if (ft_strncmp(argv[1], "julia", 5) == 0)    
    {
        manage_julia(argv, vars);
    }
        // else if (ft_strcmp(argv[1], "julia1") == 0)
        // {
        //     vars->set = 2;
        //     get_c1(vars);
        //     julia_set(vars);
        // }
        // else if (ft_strcmp(argv[1], "julia2") == 0)
        // {
        //     vars->set = 2;
        //     get_c2(vars);
        //     julia_set(vars);
        // }
        // else if (ft_strcmp(argv[1], "julia3") == 0)
        // {
        //     vars->set = 2;
        //     get_c3(vars);
        //     julia_set(vars);
        // }
        // else if (ft_strcmp(argv[1], "julia4") == 0)
        // {
        //     vars->set = 2;
        //     get_c4(vars);
        //     julia_set(vars);
        // }
        // mlx_hook(vars->win, 2, 0, coloring, vars);
	    // mlx_hook(vars->win, 6, 0, mouse_hook, vars);
        // mlx_hook(vars->win, 4, 0, zooming, vars);
	    // mlx_hook(vars->win, 17, 0, destroy, vars);
	    // mlx_key_hook(vars->win, shutdown, vars);
        // mlx_loop(vars->mlx);
    // }
    // else
    // {
    //     ft_putstr("\n\tUnvalid argument!\n\nTo select Mandelbrot Set; enter:\n\t\"mandelbrot\"\n\nTo select Julia Set; enter:\n\t\"julia1\"\n\t\"julia2\"\n\t\"julia3\"\n\t\"julia4\"\n", 1);
    //     exit(0);
    // }
}

int main(int argc, char **argv)
{
    t_vars  *vars;
    vars = (t_vars *)malloc(sizeof(t_vars *));
    initialize(vars);
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FRACTOL");
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
    vars->image.addr = mlx_get_data_addr(vars->image.img, &vars->image.bits_per_pixel, &vars->image.line_length,&vars->image.endian);
    if (argc == 2)
    {
        manage(argv, vars);
        mlx_hook(vars->win, 2, 0, coloring, vars);
	    mlx_hook(vars->win, 6, 0, mouse_hook, vars);
        mlx_hook(vars->win, 4, 0, zooming, vars);
	    mlx_hook(vars->win, 17, 0, destroy, vars);
	    mlx_key_hook(vars->win, shutdown, vars);
        mlx_loop(vars->mlx);
    }
    else
    {
        ft_putstr("\n\tUnvalid argument!\n\nTo select Mandelbrot Set; enter:\n\t\"mandelbrot\"\n\nTo select Julia Set; enter:\n\t\"julia1\"\n\t\"julia2\"\n\t\"julia3\"\n\t\"julia4\"\n", 1);
        exit(0);
    }
    // if (argc == 2)
    // {
        
    //     if (ft_strcmp(argv[1], "mandelbrot") == 0)
    //     {
    //         vars->set = 1;
    //         mandelbrot_set(vars);
    //     }    
    //     else if (ft_strcmp(argv[1], "julia1") == 0)
    //     {
    //         vars->set = 2;
    //         get_c1(vars);
    //         julia_set(vars);
    //     }
    //     else if (ft_strcmp(argv[1], "julia2") == 0)
    //     {
    //         vars->set = 2;
    //         get_c2(vars);
    //         julia_set(vars);
    //     }
    //     else if (ft_strcmp(argv[1], "julia3") == 0)
    //     {
    //         vars->set = 2;
    //         get_c3(vars);
    //         julia_set(vars);
    //     }
    //     else if (ft_strcmp(argv[1], "julia4") == 0)
    //     {
    //         vars->set = 2;
    //         get_c4(vars);
    //         julia_set(vars);
    //     }
    //     mlx_hook(vars->win, 2, 0, coloring, vars);
	//     mlx_hook(vars->win, 6, 0, mouse_hook, vars);
    //     mlx_hook(vars->win, 4, 0, zooming, vars);
	//     mlx_hook(vars->win, 17, 0, destroy, vars);
	//     mlx_key_hook(vars->win, shutdown, vars);
    //     mlx_loop(vars->mlx);
    // }
    // else
    // {
    //     ft_putstr("\n\tUnvalid argument!\n\nTo select Mandelbrot Set; enter:\n\t\"mandelbrot\"\n\nTo select Julia Set; enter:\n\t\"julia1\"\n\t\"julia2\"\n\t\"julia3\"\n\t\"julia4\"\n", 1);
    //     exit(0);
    // }
    return(0);
}