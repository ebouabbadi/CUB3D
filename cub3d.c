/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:44:42 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/13 19:10:15 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_graph(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		_error("cub3d->mlx");
	cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "CUB3D");
	if (cub3d->window == NULL)
		_error("cub3d->window");
	cub3d->img = mlx_new_image(cub3d->mlx, WIDTH, HIGHT);
	if (cub3d->img == NULL)
		_error("cub3d->img");
	cub3d->img_addr = (int *)mlx_get_data_addr(cub3d->img, \
	&cub3d->ginfo.bpp, &cub3d->ginfo.sl, &cub3d->ginfo.en);
	if (cub3d->img_addr == NULL)
		_error("cub3d->img_addr");
}

static void	game_main(char *av)
{
	t_cub3d	*cub3d;

	cub3d = cub3d_init();
	parsing(cub3d, av);
	init_graph(cub3d);
	get_img_from_files(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
	mlx_hook(cub3d->window, 2, 1L, keypress, cub3d);
	mlx_hook(cub3d->window, 3, 1L << 1, keyrelease, cub3d);
	mlx_hook(cub3d->window, 17, 1L << 2, out, cub3d);
	mlx_loop_hook(cub3d->mlx, render_next_frame, cub3d);
	mlx_loop(cub3d->mlx);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	mlx_destroy_window(cub3d->mlx, cub3d->window);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		_error("cub3d: error: invalid argument!!\n");
	game_main(av[1]);
	return (0);
}
