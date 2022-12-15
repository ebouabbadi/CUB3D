/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drew_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:02:36 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:02:37 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_pixel(t_cub3d *cub3d, t_xtr *wall, t_mapp th, int y_win)
{
	long	pixel_y;
	long	pixel_x;
	t_mapp	t;

	t.min_in = 0;
	t.maxin = BLOCK;
	t.min_to = 0;
	t.maxto = wall->width - 1;
	th.min_to = 0;
	th.maxto = wall->higth - 1;
	pixel_y = lround(math_map(y_win, th));
	if (cub3d->flag == HORIZONTAL)
	{
		pixel_x = lround(cub3d->ray_horizental.x) / BLOCK;
		pixel_x = (math_map(cub3d->ray_horizental.x - pixel_x * BLOCK, t));
	}
	else
	{
		pixel_x = lround(cub3d->ray_vertical.y) / BLOCK;
		pixel_x = math_map(cub3d->ray_vertical.y - pixel_x * BLOCK, t);
	}
	if (pixel_x < 0 || pixel_x >= wall->width)
		pixel_x = 10;
	return (wall->img_addr[pixel_x + pixel_y * wall->width]);
}

static int	get_2_pixel(t_cub3d *cub3d, t_mapp th, int y_win)
{
	if (cub3d->rotation < M_PI + M_PI_4 \
	&& cub3d->rotation >= M_PI - M_PI_4)
	{
		if (cub3d->flag == VERTICAL)
			return (get_pixel(cub3d, &cub3d->xs.west, th, y_win));
		if (cub3d->p_y < cub3d->ray_horizental.y)
			return (get_pixel(cub3d, &cub3d->xs.south, th, y_win));
		return (get_pixel(cub3d, &cub3d->xs.north, th, y_win));
	}
	if (cub3d->flag == HORIZONTAL)
		return (get_pixel(cub3d, &cub3d->xs.north, th, y_win));
	if (cub3d->p_x < cub3d->ray_vertical.x)
		return (get_pixel(cub3d, &cub3d->xs.east, th, y_win));
	return (get_pixel(cub3d, &cub3d->xs.west, th, y_win));
}

static int	get_img_pixel(t_cub3d *cub3d, t_mapp th, int y_win)
{
	if (cub3d->rotation < M_PI_4 || cub3d->rotation >= 2 * M_PI - M_PI_4)
	{
		if (cub3d->flag == VERTICAL)
			return (get_pixel(cub3d, &cub3d->xs.east, th, y_win));
		if (cub3d->p_y < cub3d->ray_horizental.y)
			return (get_pixel(cub3d, &cub3d->xs.south, th, y_win));
		return (get_pixel(cub3d, &cub3d->xs.north, th, y_win));
	}
	if (cub3d->rotation < M_PI - M_PI_4 && cub3d->rotation >= M_PI_4)
	{
		if (cub3d->flag == HORIZONTAL)
			return (get_pixel(cub3d, &cub3d->xs.south, th, y_win));
		if (cub3d->p_x < cub3d->ray_vertical.x)
			return (get_pixel(cub3d, &cub3d->xs.east, th, y_win));
		return (get_pixel(cub3d, &cub3d->xs.west, th, y_win));
	}
	return (get_2_pixel(cub3d, th, y_win));
}

static void	draw_2(t_cub3d *cub3d, double *rotation, t_mapp *wh)
{
	wh->min_to = 0;
	wh->maxto = WIDTH - 1;
	wh->min_in = cub3d->angle - (FOV / 2);
	wh->maxin = cub3d->angle + (FOV / 2);
	*rotation = cub3d->rotation;
	if (cub3d->angle <= (FOV / 2) && cub3d->rotation > 2 * M_PI - (FOV / 2))
			*rotation -= 2 * M_PI;
	else if (cub3d->angle >= 2 * M_PI - (FOV / 2)
		&& cub3d->rotation < (FOV / 2))
			*rotation += 2 * M_PI;
}

void	draw_wall(t_cub3d *cub3d, double diset)
{
	long	psh_h;
	int		y;
	int		_x;
	t_mapp	wh;
	double	rotation;

	draw_2(cub3d, &rotation, &wh);
	_x = lround(math_map(rotation, wh));
	diset = fishbowl(cub3d, diset);
	psh_h = lround ((PRJ_PLN / diset) * DBPP);
	y = ((HIGHT - psh_h) / 2);
	wh.min_in = y;
	psh_h += --y;
	wh.maxin = psh_h;
	if (y < 0)
		y = 0;
	if (psh_h > HIGHT - 1)
		psh_h = HIGHT - 1;
	while (++y < psh_h)
		if (_x >= 0 && _x < WIDTH)
			cub3d->img_addr[(_x) + ((y)) * WIDTH] = get_img_pixel(cub3d, wh, y);
}
