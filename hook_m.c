/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:21:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/13 17:50:16 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	haswall(t_cub3d *cub)
{
	if (cub->map.stepx <= 0 || cub->map.stepx >= cub->map.wi_dth
		|| cub->map.stepy <= 0 || cub->map.stepy >= cub->map.hi_gth)
		return (false);
	if (cub->map.map[(int)cub->map.stepy / BLOCK] \
	[(int)cub->map.stepx / BLOCK] == '1')
		return (false);
	if (cub->map.map[(int)cub->p_y / BLOCK] \
	[(int)cub->map.stepx / BLOCK] == '1')
		return (false);
	if (cub->map.map[(int)cub->map.stepy / BLOCK] \
	[(int)cub->p_x / BLOCK] == '1')
		return (false);
	return (true);
}

static void	render(t_cub3d *cub3d, bool action)
{	
	if (cub3d->keys._a)
	{
		action = true;
		cub3d->map.stepx = -lround(2 * cos(cub3d->angle + M_PI_2));
		cub3d->map.stepy = -lround(2 * sin(cub3d->angle + M_PI_2));
	}
	if (cub3d->keys._d)
	{
		action = true;
		cub3d->map.stepx = lround(2 * cos(cub3d->angle + M_PI_2));
		cub3d->map.stepy = lround(2 * sin(cub3d->angle + M_PI_2));
	}
	cub3d->map.stepx += cub3d->p_x;
	cub3d->map.stepy += cub3d->p_y;
	if (action && haswall(cub3d))
	{
		cub3d->p_x = cub3d->map.stepx;
		cub3d->p_y = cub3d->map.stepy;
	}
	if (action || cub3d->keys.m_l || cub3d->keys.m_r)
	{
		mlx_clear_window(cub3d->mlx, cub3d->window);
		raycasting(cub3d);
		mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
	}
}

int	render_next_frame(t_cub3d *cub3d)
{
	bool	action;

	action = false;
	if (cub3d->keys.m_l)
		cub3d->angle -= RETAION;
	if (cub3d->keys.m_r)
		cub3d->angle += RETAION;
	if (cub3d->keys._w)
	{
		action = true;
		cub3d->map.stepx = lround(2 * cos(cub3d->angle));
		cub3d->map.stepy = lround(2 * sin(cub3d->angle));
	}
	if (cub3d->keys._s)
	{
		action = true;
		cub3d->map.stepx = -lround(2 * cos(cub3d->angle));
		cub3d->map.stepy = -lround(2 * sin(cub3d->angle));
	}
	if (cub3d->angle > 2 * M_PI)
		cub3d->angle -= 2 * M_PI;
	else if (cub3d->angle < 0)
		cub3d->angle += 2 * M_PI;
	render(cub3d, action);
	return (0);
}

int	keypress(int key, t_cub3d *cub3d)
{
	if (key == M_L)
		cub3d->keys.m_l = true;
	if (key == M_R)
		cub3d->keys.m_r = true;
	if (key == W)
		cub3d->keys._w = true;
	if (key == S)
		cub3d->keys._s = true;
	if (key == A)
		cub3d->keys._a = true;
	if (key == D)
		cub3d->keys._d = true;
	if (key == ESC)
		out(cub3d);
	return (0);
}

int	keyrelease(int key, t_cub3d *cub3d)
{
	if (key == M_L)
		cub3d->keys.m_l = false;
	if (key == M_R)
		cub3d->keys.m_r = false;
	if (key == W)
		cub3d->keys._w = false;
	if (key == S)
		cub3d->keys._s = false;
	if (key == A)
		cub3d->keys._a = false;
	if (key == D)
		cub3d->keys._d = false;
	return (0);
}
