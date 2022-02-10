/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:58:30 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/02/10 22:45:00 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

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
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	printf("mousecode : %d\n", mousecode);
	// if (mousecode == 5)
	// 	ZOOM_IN
	// else if (mousecode == 4)
	// 	ZOOM_OUT
	return (0);
}

int	main()
{
	t_vars	vars;
	// void	*mlx;
	// void	*mlx_win;
	t_data	img;
	int		i = 0;
	float	c;
	// float	x_min = -2.1;
	// float	x_max = 0.6;
	// float	y_min = -1.2;
	// float	y_max = 1.2;
	int		x = 0;
	int		y = 0;
	double	zr = 0;
	double	zi = 0;
	double 	cr = 0;
	double	ci = 0;
	double	tmp = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "FRACTOL");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);

	while (x < 1000 && y < 1000)
	{
		cr = (x - 1000/2.0)*4.0/1000;
		ci = (y - 1000/2.0)*4.0/1000;
		printf("cr = %f \n",cr);
		printf("ci = %f\n",ci);
		zr = 0;
		zi = 0;
		i = 0;
		while (zr*zr+zi*zi <= 4 && i < 100)
		{
			tmp = zr;
			zr = zr*zr - zi*zi + cr;
			zi = 2 * zi * tmp + ci;
			if (zr*zr+zi*zi <= 4) // ila kan dakhel range or the M set => display it w/ white
			{
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
				printf("zr = %f \n",zr);
				printf("zi = %f\n",zi);
			}
			if (zr*zr+zi*zi > 4) // ila kan kharej range or the M set => display it
			{
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
				printf("zr = %f \n",zr);
				printf("zi = %f\n",zi);
			}
			i++;
		}
		x++;
		y++;
	}

	// while (i < 100 && zr*zr + zi*zi <= 4)
	// {
	// 	tmp = zr;
	// 	zr = zr*zr - zi*zi + cr;
    //     zi = 2 * zi * tmp + ci;
	// 	my_mlx_pixel_put(&img, zr, zi, 0x0000FF00);
	// 	i++;
	// }

// // cercle
// 	int	r = 50;
// 	int	x = 100;
// 	int	y = 50;

// 	while (y)
// 	{
// 		if (y - x == r)
// 			my_mlx_pixel_put(&img, x, y, 0x0000FF00);	
// 		y--;
// 	}

	
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