/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:12:30 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 18:07:56 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	vertical_line_left(t_cub3d *cub, int flag_vertical)
{
	int	x0;

	x0 = (int)(cub->p_x / BLOCK) * BLOCK;
	cub->ray_vertical.first_x = (cub->p_x - x0) * -1;
	cub->ray_vertical.first_y = tan(cub->rotation) * cub->ray_vertical.first_x;
	cub->ray_vertical.x = cub->ray_vertical.first_x + cub->p_x;
	cub->ray_vertical.y = cub->ray_vertical.first_y + cub->p_y;
	cub->ray_vertical.x--;
	while ((cub->ray_vertical.x < cub->map.wi_dth
			&& cub->ray_vertical.y < cub->map.hi_gth
			&& cub->ray_vertical.x > 0 && cub->ray_vertical.y > 0))
	{
		if (cub->map.map[(int)(cub->ray_vertical.y / BLOCK)]
			[(int)(cub->ray_vertical.x / BLOCK)] == '1')
		{
			flag_vertical = 1;
			break ;
		}
		cub->ray_vertical.x -= BLOCK;
		cub->ray_vertical.y += -BLOCK * tan(cub->rotation);
	}
	return (flag_vertical);
}

int	vertical_line_right(t_cub3d *cub, int flag_vertical)
{
	int	x0;

	x0 = (int)(cub->p_x / BLOCK) * BLOCK + BLOCK;
	cub->ray_vertical.first_x = x0 - cub->p_x;
	cub->ray_vertical.first_y = tan(cub->rotation) * cub->ray_vertical.first_x;
	cub->ray_vertical.x = cub->ray_vertical.first_x + cub->p_x;
	cub->ray_vertical.y = cub->ray_vertical.first_y + cub->p_y;
	while ((cub->ray_vertical.x < cub->map.wi_dth
			&& cub->ray_vertical.y < cub->map.hi_gth
			&& cub->ray_vertical.x > 0 && cub->ray_vertical.y > 0))
	{
		if (cub->map.map[(int)(cub->ray_vertical.y / BLOCK)]
			[(int)(cub->ray_vertical.x / BLOCK)] == '1')
		{
			flag_vertical = 1;
			break ;
		}
		cub->ray_vertical.x += BLOCK;
		cub->ray_vertical.y += tan(cub->rotation) * BLOCK;
	}
	return (flag_vertical);
}

int	horizental_line_up(t_cub3d *cub, int flag_horizental)
{
	int	y0;

	y0 = (int)(cub->p_y / BLOCK) * BLOCK;
	cub->ray_horizental.first_y = (cub->p_y - y0) * -1;
	cub->ray_horizental.first_x = cub->ray_horizental.first_y
		/ tan(cub->rotation);
	cub->ray_horizental.x = cub->ray_horizental.first_x + cub->p_x;
	cub->ray_horizental.y = cub->ray_horizental.first_y + cub->p_y;
	cub->ray_horizental.y--;
	while ((cub->ray_horizental.x < cub->map.wi_dth
			&& cub->ray_horizental.y < cub->map.hi_gth
			&& cub->ray_horizental.x > 0 && cub->ray_horizental.y > 0))
	{
		if (cub->map.map[(int)(cub->ray_horizental.y / BLOCK)]
			[(int)(cub->ray_horizental.x / BLOCK)] == '1')
		{
			flag_horizental = 1;
			break ;
		}
		cub->ray_horizental.y -= BLOCK;
		cub->ray_horizental.x += -BLOCK / tan(cub->rotation);
	}
	return (flag_horizental);
}

int	horizental_line_down(t_cub3d *cub, int flag_horizental)
{
	int	y0;

	y0 = (int)(cub->p_y / BLOCK) * BLOCK + BLOCK;
	cub->ray_horizental.first_y = y0 - cub->p_y;
	cub->ray_horizental.first_x = cub->ray_horizental.first_y
		/ tan(cub->rotation);
	cub->ray_horizental.x = cub->ray_horizental.first_x + cub->p_x;
	cub->ray_horizental.y = cub->ray_horizental.first_y + cub->p_y;
	while ((cub->ray_horizental.x < cub->map.wi_dth
			&& cub->ray_horizental.y < cub->map.hi_gth
			&& cub->ray_horizental.x > 0 && cub->ray_horizental.y > 0))
	{
		if (cub->map.map[(int)(cub->ray_horizental.y / BLOCK)]
			[(int)(cub->ray_horizental.x / BLOCK)] == '1')
		{
			flag_horizental = 1;
			break ;
		}
		cub->ray_horizental.y += BLOCK;
		cub->ray_horizental.x += BLOCK / tan(cub->rotation);
	}
	return (flag_horizental);
}
