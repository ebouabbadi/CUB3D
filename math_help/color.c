/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:06:13 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:06:14 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <treD_hndlr.h>

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	errno = 0;
	if (t > 255 || r > 255 || g > 255 || b > 255)
		_error("rgb color > 255");
	if (t < 0 || r < 0 || g < 0 || b < 0)
		_error("rgb color < 0");
	return (t << 24 | r << 16 | g << 8 | b);
}
