/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:31:15 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/06 02:27:05 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

void	get_c1(t_vars *vars)
{
	vars->cr = -0.4;
	vars->ci = 0.6;
	return ;
}

void	get_c2(t_vars *vars)
{
	vars->cr = -0.8;
	vars->ci = 0.156;
	return ;
}

void	get_c3(t_vars *vars)
{
	vars->cr = 0.285;
	vars->ci = 0.01;
	return ;
}

void	get_c4(t_vars *vars)
{
	vars->cr = -0.835 ;
	vars->ci = -0.2321;
	return ;
}
