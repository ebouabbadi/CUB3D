/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:03:36 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/12 10:04:50 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_textr(struct s_texture *txtr)
{
	txtr->gm.bpp = NOT_INIT;
	txtr->gm.sl = NOT_INIT;
	txtr->gm.en = NOT_INIT;
	txtr->higth = NOT_INIT;
	txtr->img = NULL;
	txtr->img_addr = NULL;
	txtr->path = NULL;
	txtr->width = NOT_INIT;
	txtr->next_x = NOT_INIT;
	txtr->next_x = NOT_INIT;
}

static	void	init_keys(t_cub3d *cub3d)
{
	cub3d->keys.m_l = false;
	cub3d->keys.m_r = false;
	cub3d->keys._a = false;
	cub3d->keys._d = false;
	cub3d->keys._s = false;
	cub3d->keys._w = false;
	cub3d->keys._esc = false;
	cub3d->floor = NOT_INIT;
	cub3d->ceilling = NOT_INIT;
	cub3d->map.hi_gth = NOT_INIT;
	cub3d->map.wi_dth = NOT_INIT;
}

static void	init_content(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->window = NULL;
	cub3d->img = NULL;
	cub3d->img_addr = NULL;
	cub3d->angle = NOT_INIT;
	cub3d->flag = 0;
	cub3d->map.map = NULL;
	cub3d->p_x = NOT_INIT;
	cub3d->p_y = NOT_INIT;
	init_ray(&cub3d->ray_horizental);
	init_ray(&cub3d->ray_vertical);
	cub3d->rotation = NOT_INIT;
	init_textr(&cub3d->xs.east);
	init_textr(&cub3d->xs.west);
	init_textr(&cub3d->xs.north);
	init_textr(&cub3d->xs.south);
	init_keys(cub3d);
}

t_cub3d	*cub3d_init(void)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		_error("cub3d");
	return (init_content(cub3d), cub3d);
}
