/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:38:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/03/28 18:34:52 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int    *colors_palette1()
{
    static int    arr[16];

    arr[0] = 0x0009012f;
    arr[1] = 0x00040449;
    arr[2] = 0x00000764;
    arr[3] = 0x000c2c8a;
    arr[4] = 0x001852b1;
    arr[5] = 0x00397dd1;
    arr[6] = 0x0086b5e5;
    arr[7] = 0x00d3ecf8;
    arr[8] = 0x00f1e9bf;
    arr[9] = 0x00f8c95f;
    arr[10] = 0x00ffaa00;
    arr[11] = 0x00cc8000;
    arr[12] = 0x00995700;
    arr[13] = 0x006a3403;
    arr[14] = 0x00421e0f;
    arr[15] = 0x0019071a;
    return (arr);
}

int    *colors_palette2()
{
    static int    arr[21];

    arr[0] = 0x00990000;
    arr[1] = 0x006a0303;
    arr[2] = 0x00420f0f;
    arr[3] = 0x001a0707;
    arr[4] = 0x00f1bfbf;
    arr[5] = 0x00f85f5f;
    arr[6] = 0x00ff0000;
    arr[7] = 0x00cc0000;
    arr[8] = 0x0009012f;
    arr[9] = 0x00040449;
    arr[10] = 0x00000764;
    arr[11] = 0x000c2c8a;
    arr[12] = 0x001852b1;
    arr[13] = 0x00397dd1;
    arr[14] = 0x0086b5e5;
    arr[15] = 0x00d3ecf8;
    return (arr);
}
