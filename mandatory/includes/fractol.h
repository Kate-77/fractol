/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:35:04 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/04 03:05:03 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
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
	int		i;
	int		color;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	int		palette;
	int		*colors;
	int		set;
	double	move_x;
	double	move_y;
	char	*msg;
}				t_vars;

void	ft_start(t_vars *vars);
void	initialize(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		shutdown(int keycode, t_vars *vars);
int		destroy(t_vars *vars);
void	mandelbrot_set(t_vars *vars);
int		zooming(int keycode, int x, int y, t_vars *vars);
void	apply_zoom(t_vars *vars);
double	interpolate(double start, double end, double interpolation);
int		*colors_palette1(void);
int		*colors_palette2(void);
void	burningship_set(t_vars *vars);
int		mouse_hook(int x, int y, t_vars *vars);
int		*colors_palette3(void);
int		*colors_palette4(void);
int		*colors_palette5(void);
int		coloring(int keycode, t_vars *vars);
void	julia_set(t_vars *vars);
void	get_c1(t_vars *vars);
void	get_c2(t_vars *vars);
void	get_c3(t_vars *vars);
void	get_c4(t_vars *vars);
void	ft_putstr(char *s, int fd);
void	move(int keycode, t_vars *vars);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	manage_sets(t_vars *vars);
void	calcul(t_vars *vars, int x, int y, int tmp);
void	calcul_man(t_vars *vars, int x, int y, int tmp);

#endif
