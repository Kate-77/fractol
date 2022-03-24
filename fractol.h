/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:35:04 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/24 21:09:53 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

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
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		height;
	int		width;
	double	mouse_x;
	double	mouse_y;
	double	zoom;
}				t_vars;

void    initialize(t_vars *vars);
#endif