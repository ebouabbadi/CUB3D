/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:38 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/13 17:40:03 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static double	get_view_angle(char token)
{
	if (token == 'E')
		return (false);
	if (token == 'W')
		return (M_PI);
	if (token == 'S')
		return (M_PI_2);
	return (M_PI_2 + M_PI);
}

static void	check_compo(t_cub3d *cub3d, int	*i, int *j, int *count)
{	
	if (check_for_empty_space(cub3d->map, *i, *j))
	{
		if (cub3d->map.map[*i][*j] != '0')
		{
			cub3d->angle = get_view_angle(cub3d->map.map[*i][*j]);
			cub3d->p_x = (*j * BLOCK) + (BLOCK / 2);
			cub3d->p_y = (*i * BLOCK) + (BLOCK / 2);
			(*count)++;
		}
	}
	else if (cub3d->map.map[*i][*j] != '1' && cub3d->map.map[*i][*j] != ' '
	&& cub3d->map.map[*i][*j] != '\n')
		exit(write(2, "Error: invalid map!!\n", 23));
	if (*count > 1)
		exit(write(2, "Error: invalid map!! multiple player!!!\n", 41));
}

static void	check_component(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (cub3d->map.map[++i])
	{
		j = -1;
		while (cub3d->map.map[i][++j])
			check_compo(cub3d, &i, &j, &count);
	}
	if (count == 0)
		exit(write(2, "Error: invalid map!! need player's position!!\n", 47));
}

void	get_map(int fd, t_cub3d *cub3d, char *first_line)
{
	t_list	*map;
	int		map_height;

	if (!first_line)
		exit(write(2, "Error: map not found!\n", 23));
	map = ft_lstnew(first_line);
	if (!map)
		_error("ft_lstnew");
	map_height = get_map_content(fd, &map);
	close(fd);
	map_list_to_array(map, cub3d, map_height);
	check_component(cub3d);
	cub3d->map.hi_gth *= BLOCK;
	cub3d->map.wi_dth *= BLOCK;
}
