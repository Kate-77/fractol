/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 02:16:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/02 04:41:33 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	char	*s1_temp;
	char	*s2_temp;
	unsigned int		i;

	s1_temp = s1;
	s2_temp = s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	if ((ft_strlen(s1) == 0) || (ft_strlen(s2) == 0))
		return (s1_temp[i] - s2_temp[i]);
	while (s2_temp[i] && s1_temp[i])
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	char	*s1_temp;
	char	*s2_temp;
	unsigned int		i;

	s1_temp = s1;
	s2_temp = s2;
	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	if ((ft_strlen(s1) == 0) || (ft_strlen(s2) == 0))
		return (s1_temp[i] - s2_temp[i]);
	while (i + 1 < n && s2_temp[i] && s1_temp[i])
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}