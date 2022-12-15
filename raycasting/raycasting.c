/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:48:33 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 17:59:50 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	raycasting_vertical(t_cub3d *cub)
{
	int	flag_vertical;

	flag_vertical = 0;
	if (cub->rotation >= M_PI_2 && cub->rotation <= M_PI + M_PI_2)
		flag_vertical = vertical_line_left(cub, flag_vertical);
	else
		flag_vertical = vertical_line_right(cub, flag_vertical);
	return (flag_vertical);
}

int	raycasting_horizental(t_cub3d *cub)
{
	int	flag_horizental;

	flag_horizental = 0;
	if (cub->rotation <= 2 * M_PI && cub->rotation >= M_PI)
		flag_horizental = horizental_line_up(cub, flag_horizental);
	else
		flag_horizental = horizental_line_down(cub, flag_horizental);
	return (flag_horizental);
}

void	raycasting_2(t_cub3d *cub)
{
	if (cub->map.z_h > cub->map.z_v)
	{
		if ((cub->ray_vertical.x <= cub->map.wi_dth
				&& cub->ray_vertical.y <= cub->map.hi_gth
				&& cub->ray_vertical.x >= 0 && cub->ray_vertical.y >= 0))
		{
			cub->flag = VERTICAL;
			draw_wall(cub, cub->map.z_v);
		}
	}
	else
	{
		if ((cub->ray_horizental.x <= cub->map.wi_dth
				&& cub->ray_horizental.y <= cub->map.hi_gth
				&& cub->ray_horizental.x >= 0 && cub->ray_horizental.y >= 0))
		{
			cub->flag = HORIZONTAL;
			draw_wall(cub, cub->map.z_h);
		}
	}
}

void	fix_angle(t_cub3d *cub)
{
	if (cub->map.angle < 0)
		cub->map.angle += 2 * M_PI;
	if (cub->map.angle > 2 * M_PI)
		cub->map.angle -= 2 * M_PI;
	cub->map.z_v = __INT_MAX__;
	cub->map.z_h = __INT_MAX__;
}

void	raycasting(t_cub3d *cub)
{
	int	i;

	i = -1;
	init_ray(&cub->ray_horizental);
	init_ray(&cub->ray_vertical);
	drew_env(cub);
	cub->map.angle = cub->angle - (FOV / 2);
	while (++i < WIDTH)
	{
		fix_angle(cub);
		cub->rotation = cub->map.angle;
		if (raycasting_vertical(cub) == 1)
		{
			cub->map.z_v = math_chasles(cub->p_x, cub->p_y,
					cub->ray_vertical.x, cub->ray_vertical.y);
		}
		if (raycasting_horizental(cub) == 1)
		{
			cub->map.z_h = math_chasles(cub->p_x, cub->p_y,
					cub->ray_horizental.x, cub->ray_horizental.y);
		}
		raycasting_2(cub);
		cub->map.angle += FOV / WIDTH;
	}
}
