/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:58:30 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/02/17 22:38:39 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

double zoom(double x, double x0, double zoom)
{
	return (x + ((x0 - x) * zoom));
}

double	applyZoom(double mouse_x, double mouse_y, double zoom, double *x_min, double *x_max, double *y_min, double *y_max)
{
	double zooming = 1.0 / zoom;

    *x_min = zoom(mouse_x, x_min, zooming);
    *y_min = zoom(mouse_y, y_min, zooming);
    *x_max = zoom(mouse_x, x_max, zooming);
    *y_max = zoom(mouse_y, y_max, zooming);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars, double *x_min, double *x_max, double *y_min, double *y_max)
{
	//printf("mousecode : %d\n", mousecode);
	//printf ("x = %d\n y = %d\n", x, y);
	if (mousecode == 5) // zoom in
	{
		applyZoom(x, y, 0.9, x_min, x_max, y_min, y_max);
	}
	else if (mousecode == 4) // zoom out
	{
		applyZoom(x, y, -0.1, x_min, x_max, y_min, y_max);
	}
	else
		applyZoom(x, y, 1, x_min, x_max, y_min, y_max);

	return (0);
}

double	ft_color(int number)
{
	int	color;

	return (color);
}

int	main()
{
	t_vars	vars;
	t_data	img;
	int		i = 0;
	int		max_i = 100;
	double	x_min = -2.0;
	double	x_max = 2.0;
	double	y_min = -2.0;
	double	y_max = 2.0;
	int		height = 1000;
	int		width = 1000;
	double	PixelWidth;
	double	PixelHeight;
	//int		*color;
	// double	PixelWidth=(x_max-x_min)/width /2;
    // double	PixelHeight=(y_max-y_min)/height / 2;
	double	cx, cy;
	int		x = 0;
	int		y = 0;
	double	zr = 0;
	double	zi = 0;
	double 	cr = 0;
	double	ci = 0;
	double	tmp = 0;
	int		color;
	int	ms = mouse_hook(0, 0, 0, &vars, &x_min, &x_max, &y_min, &y_max);



	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "FRACTOL");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	// while (y < height)
	// {
	// 	x = 0;
	// 	while (x < width)
	// 	{
	// 		cr = (x - 1500.0/2.0)*4.0/1500.0;
	// 		ci = (y - 1500.0/2.0)*4.0/1500.0;
	// 		zr = 0;
	// 		zi = 0;
	// 		i = 0;
	// 		while (zr*zr + zi*zi <= 4 && i < 100)
	// 		{
	// 			tmp = zr;
	// 			zr = zr*zr - zi*zi + cr;
	// 			zi = 2 * zi * tmp + ci;		
	// 			i++;
	// 		}
	// 		if (i < 100) // ila kan kharej range or the M set => display it
	// 		{
	// 			color = 255 - i * 255 / 100;
	// 			my_mlx_pixel_put(&img, x, y, color);
	// 		}
	// 		else
	// 		{
	// 			my_mlx_pixel_put(&img, x, y, 0x000000);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
		
	while (y < height)
	{
		//cy = y_min + y * PixelHeight;
		x = 0;
		while (x < width)
		{
			//cx = x_min + x * PixelWidth;
			//cr = (x - 1000.0/2.0)*4.0/1000.0;
			//ci = (y - 900.0/2.0)*4.0/1000.0;
			cx= (x / (width / (x_max-x_min)) + x_min);
    		cy= (y / (height / (y_max-y_min)) + y_min);
			zr = 0;
			zi = 0;
			i = 0;
			while (zr*zr + zi*zi <= 4 && i < max_i)
			{
				tmp = zr;
				zr = zr*zr - zi*zi + cx;
				zi = 2 * zi * tmp + cy;					
				if (zr*zr + zi*zi >= 4) // ila kan kharej range or the M set => display it
				{
					color = i * 255 / max_i;
					//color = 255 - i * 255 / max_i;
					//printf("color = %d\n", color);
					my_mlx_pixel_put(&img, x, y, color);
				}
				else
				{
					my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
				}
				i++;
			}
			
			x++;
		}
		y++;
	}

	// i = 70;
	// j = 20;
	// while (i >= 20)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i--;
	// }
	// while (j <= 70)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j++;
	// }
	// while (i <= 70)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i++;
	// }
	// // A
	// i = 80;
	// while (j >= 20)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j--;
	// }
	// while (i <= 130)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i++;
	// }
	// while (j <= 70)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j++;
	// }
	// j = 40;
	// while (i >= 80)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i--;
	// }
	// // S
	// i = 190;
	// j = 20;
	// while (i >= 140)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i--;
	// }
	// while (j <= 40)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j++;
	// }
	// while (i <= 190)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i++;
	// }
	// while (j <= 70)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j++;
	// }
	// while (i >= 140)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i--;
	// }
	// // A
	// i = 200;
	// while (j >= 20)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j--;
	// }
	// while (i <= 250)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i++;
	// }
	// while (j <= 70)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	j++;
	// }
	// j = 40;
	// while (i >= 200)
	// {
	// 	my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	// 	i--;
	// }
	mlx_put_image_to_window(vars.mlx,  vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
