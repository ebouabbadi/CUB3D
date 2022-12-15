/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:27:06 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/11 21:13:19 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*get_texture_path(char *line)
{
	char	*texture;

	texture = ft_strtrim(line, " \n");
	if (!texture)
		_error("ft_strtrim\n");
	return (texture);
}

void	get_texture_path_(t_cub3d *cub3d, char *line, int *count)
{
	*count += 1;
	if (line[0] == 'N' && line[1] == 'O' && !cub3d->xs.north.path)
		cub3d->xs.north.path = get_texture_path(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && !cub3d->xs.south.path)
		cub3d->xs.south.path = get_texture_path(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && !cub3d->xs.west.path)
		cub3d->xs.west.path = get_texture_path(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && !cub3d->xs.east.path)
		cub3d->xs.east.path = get_texture_path(&line[2]);
}
