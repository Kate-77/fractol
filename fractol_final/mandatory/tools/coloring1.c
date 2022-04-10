/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:38:36 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/06 00:57:55 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	*colors_palette1(void)
{
	static int	arr[16];

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

int	*colors_palette2(void)
{
	static int	arr[16];

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

int	*colors_palette3(void)
{
	static int	arr[16];

	arr[0] = 0x00ddcf99;
	arr[1] = 0x00cca87b;
	arr[2] = 0x00b97a60;
	arr[3] = 0x009c524e;
	arr[4] = 0x00774251;
	arr[5] = 0x004b3d44;
	arr[6] = 0x004e5463;
	arr[7] = 0x005b7d73;
	arr[8] = 0x008e9f7d;
	arr[9] = 0x00645355;
	arr[10] = 0x008c7c79;
	arr[11] = 0x00a99c8d;
	arr[12] = 0x007d7b62;
	arr[13] = 0x00aaa25d;
	arr[14] = 0x00846d59;
	arr[15] = 0x00a88a5e;
	return (arr);
}

int	*colors_palette4(void)
{
	static int	arr[22];

	arr[0] = 0x00636663;
	arr[1] = 0x0087857c;
	arr[2] = 0x00bcad9f;
	arr[3] = 0x00f2b888;
	arr[4] = 0x00eb9661;
	arr[5] = 0x00b55945;
	arr[6] = 0x00734c44;
	arr[7] = 0x003d3333;
	arr[8] = 0x007a5859;
	arr[9] = 0x00a57855;
	arr[10] = 0x00de9f47;
	arr[11] = 0x00fdd179;
	arr[12] = 0x00fee1b8;
	arr[13] = 0x00d4c692;
	arr[14] = 0x00a6b04f;
	arr[15] = 0x00819447;
	arr[16] = 0x0044702d;
	arr[17] = 0x002f4d2f;
	arr[18] = 0x00546756;
	arr[19] = 0x0089a477;
	arr[20] = 0x00a4c5af;
	arr[21] = 0x00cae6d9;
	return (arr);
}

int	*colors_palette5(void)
{
	static int	arr[8];

	arr[0] = 0x009fb9cc;
	arr[1] = 0x00679e9c;
	arr[2] = 0x002e868c;
	arr[3] = 0x00006e42;
	arr[4] = 0x00173957;
	arr[5] = 0x00072927;
	arr[6] = 0x0008102e;
	arr[7] = 0x00060f0d;
	return (arr);
}
