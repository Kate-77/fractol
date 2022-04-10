/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:58:30 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/07 07:10:24 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	manage_julia2(char **argv, t_vars *vars)
{
	vars->set = 2;
	if (ft_strcmp(argv[1], "julia5") == 0)
	{
		get_c5(vars);
		julia_set(vars);
	}
	else if (ft_strcmp(argv[1], "julia6") == 0)
	{
		get_c6(vars);
		julia_set(vars);
	}
	else
	{
		ft_putstr(vars->msg, 1);
		exit(0);
	}
	return ;
}

void	manage_julia1(char **argv, t_vars *vars)
{
	vars->set = 2;
	if (ft_strcmp(argv[1], "julia1") == 0)
	{
		get_c1(vars);
		julia_set(vars);
	}
	else if (ft_strcmp(argv[1], "julia2") == 0)
	{
		get_c2(vars);
		julia_set(vars);
	}
	else if (ft_strcmp(argv[1], "julia3") == 0)
	{
		get_c3(vars);
		julia_set(vars);
	}
	else if (ft_strcmp(argv[1], "julia4") == 0)
	{
		get_c4(vars);
		julia_set(vars);
	}
	else
		manage_julia2(argv, vars);
	return ;
}

void	manage(char **argv, t_vars *vars)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		vars->set = 1;
		mandelbrot_set(vars);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		manage_julia1(argv, vars);
	else
	{
		ft_putstr(vars->msg, 1);
		exit(0);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	ft_start(vars);
	if (argc >= 2)
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
		ft_putstr(vars->msg, 1);
		exit(0);
	}
	return (0);
}
