/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fishblow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:02:43 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:02:44 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <treD_hndlr.h>

/*Fishbowl effect problem fixe . get correct distance*/
/* distorted distance  * cos(angle betwen
	viewing direction and relative view angle)*/
/* psh : projection slice higth */
double	fishbowl(t_cub3d *cub3d, double psh)
{
	return ((cos(cub3d->rotation - cub3d->angle) * (double)psh));
}

void	drew_env(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	color;

	color = cub3d->ceilling ;
	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cub3d->img_addr[x++ + y * WIDTH] = color;
		}
		if (y++ > HIGHT / 2)
			color = cub3d->floor;
	}
}

int	out(t_cub3d *cub3d)
{
	if (cub3d->mlx)
	{
		mlx_clear_window(cub3d->mlx, cub3d->window);
		mlx_destroy_window(cub3d->mlx, cub3d->window);
	}
	cub3d->map.hi_gth /= BLOCK;
	while (cub3d->map.hi_gth--)
		free(cub3d->map.map[cub3d->map.hi_gth]);
	free(cub3d->map.map);
	free(cub3d->xs.east.path);
	free(cub3d->xs.west.path);
	free(cub3d->xs.north.path);
	free(cub3d->xs.south.path);
	free(cub3d);
	exit(0);
	return (0);
}
