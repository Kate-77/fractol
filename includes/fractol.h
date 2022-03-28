/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:35:04 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/28 18:49:06 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
#include <string.h>

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
	t_data	image;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		height;
	int		width;
	double	mouse_x;
	double	mouse_y;
	double	zoom;
	int		max_i;
}				t_vars;

void    initialize(t_vars *vars);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		shutdown(int keycode, t_vars *vars);
int		destroy(t_vars *vars);
int		create_trgb(int t, int r, int g, int b);
void    mandelbrot_set(t_vars *vars);
int		zooming(int keycode, int x, int y, t_vars *vars);
void	applyZoom(t_vars *vars);
double	interpolate(double start, double end, double interpolation);
int		*colors_palette1();
int		*colors_palette2();
void	burningship_set(t_vars *vars);
int		mouse_hook(int x, int y, t_vars *vars);

#endif