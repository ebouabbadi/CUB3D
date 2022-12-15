/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:09:54 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/11 21:24:25 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_token(char *line)
{
	int	size;

	size = ft_strlen(line);
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (RGB_COLOR);
	else if (line[0] == '1')
		return (MAP);
	else if (line[0] == '\0')
		return (EMPTY_LINE);
	else if (size > 3 && (ft_strncmp(line, "NO ", 3)
			|| ft_strncmp(line, "SO ", 3)
			|| ft_strncmp(line, "EA ", 3) || ft_strncmp(line, "WE ", 3)))
		return (DIRECTION);
	return (INVALIDE_LINE);
}

void	parsing(t_cub3d *cub3d, char *file_name)
{
	int		fd;

	check_extention(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		_error(file_name);
	get_infos(cub3d, fd);
}
