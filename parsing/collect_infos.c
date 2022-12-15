/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:07 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/13 17:34:59 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_img_from_files(t_cub3d *cub)
{
	cub->xs.east.img = mlx_xpm_file_to_image(cub->mlx, \
	cub->xs.east.path, &cub->xs.east.width, &cub->xs.east.higth);
	cub->xs.west.img = mlx_xpm_file_to_image(cub->mlx, \
	cub->xs.west.path, &cub->xs.west.width, &cub->xs.west.higth);
	cub->xs.north.img = mlx_xpm_file_to_image(cub->mlx, \
	cub->xs.north.path, &cub->xs.north.width, &cub->xs.north.higth);
	cub->xs.south.img = mlx_xpm_file_to_image(cub->mlx, \
	cub->xs.south.path, &cub->xs.south.width, &cub->xs.south.higth);
	if (cub->xs.east.img == NULL || cub->xs.west.img == NULL || \
	cub->xs.north.img == NULL || cub->xs.south.img == NULL)
		_error("mlx_xpm_file_to_image");
	cub->xs.east.img_addr = (int *)mlx_get_data_addr(cub->xs.east.img, \
	&cub->xs.east.gm.bpp, &cub->xs.east.gm.sl, &cub->xs.east.gm.en);
	cub->xs.west.img_addr = (int *)mlx_get_data_addr(cub->xs.west.img, \
	&cub->xs.west.gm.bpp, &cub->xs.west.gm.sl, &cub->xs.west.gm.en);
	cub->xs.north.img_addr = (int *)mlx_get_data_addr(cub->xs.north.img, \
	&cub->xs.north.gm.bpp, &cub->xs.north.gm.sl, &cub->xs.north.gm.en);
	cub->xs.south.img_addr = (int *)mlx_get_data_addr(cub->xs.south.img, \
	&cub->xs.south.gm.bpp, &cub->xs.south.gm.sl, &cub->xs.south.gm.en);
	if (cub->xs.east.img_addr == NULL || cub->xs.west.img_addr == NULL \
	|| cub->xs.north.img_addr == NULL || cub->xs.south.img_addr == NULL)
		_error("mlx_get_data_addr");
}

static char	*get_infos_2(t_cub3d *cub3d, char *tmp_line, int fd, int *count)
{
	char	*line;
	int		token;

	while (tmp_line)
	{
		line = ft_strtrim(tmp_line, " \n");
		if (!line)
			_error("ft_strtrim");
		token = get_token(line);
		if (token == MAP)
			break ;
		else if (token == RGB_COLOR)
			get_color(cub3d, line, count);
		else if (token == DIRECTION)
			get_texture_path_(cub3d, line, count);
		else if (token == INVALIDE_LINE)
			exit (write(2, "Error: invalid map's informations!!\n", 37));
		free(line);
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	free(line);
	return (tmp_line);
}

void	get_infos(t_cub3d *cub3d, int fd)
{
	char		*tmp_line;
	int			count;

	count = 0;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		exit (write(2, "Error: empty map's file!!\n", 27));
	tmp_line = get_infos_2(cub3d, tmp_line, fd, &count);
	if (count != 6 || cub3d->ceilling == NOT_INIT || cub3d->floor == NOT_INIT \
		|| !cub3d->xs.east.path || !cub3d->xs.north.path
		|| !cub3d->xs.west.path || !cub3d->xs.south.path)
		exit (write(2, "Error: invalid map's informations!!\n", 37));
	get_map(fd, cub3d, tmp_line);
}
