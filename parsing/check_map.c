/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:29:57 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/13 17:39:08 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	map_plan(t_cub3d *cub3d, int height)
{
	char	*map_ptr;
	char	*check;
	bool	out;

	out = false;
	while (height--)
	{
		map_ptr = cub3d->map.map[height];
		check = ft_strtrim(map_ptr, " \n");
		if (out || check[0] != '\0')
		{
			out = true;
			cub3d->map.map[height] = ft_memcpy(ft_memset(\
			malloc(cub3d->map.wi_dth), ' ', cub3d->map.wi_dth - 1), \
			map_ptr, ft_strlen(map_ptr) - 1);
			cub3d->map.map[height][cub3d->map.wi_dth - 1] = '\0';
		}
		else
		{
			cub3d->map.hi_gth --;
			cub3d->map.map[height] = NULL;
		}
		free(check);
		free(map_ptr);
	}
}

void	map_list_to_array(t_list *map, t_cub3d *cub3d, int height)
{
	t_list	*ptr;

	cub3d->map.hi_gth = 0;
	cub3d->map.wi_dth = 0;
	cub3d->map.map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!cub3d->map.map)
		_error("array map");
	while (map)
	{
		ptr = map;
		cub3d->map.map[cub3d->map.hi_gth++] = map->content;
		if (map->content && ft_strlen(map->content) > (size_t)cub3d->map.wi_dth)
			cub3d->map.wi_dth = ft_strlen(map->content);
		map = map->next;
		free(ptr);
	}
	cub3d->map.map[cub3d->map.hi_gth] = NULL;
	map_plan(cub3d, height);
}

int	get_map_content(int fd, t_list **map)
{
	char	*line;
	t_list	*new;
	int		map_height;

	map_height = 1;
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			_error("ft_lstnew");
		ft_lstadd_back(map, new);
		map_height++;
		line = get_next_line(fd);
	}
	return (map_height);
}

bool	check_for_empty_space(struct s_map map, int i, int j)
{
	if (map.map[i][j] != '0' && map.map[i][j] != 'S'
		&& map.map[i][j] != 'E' && map.map[i][j] != 'W'
		&& map.map[i][j] != 'N')
		return (false);
	if (i <= 0 || j <= 0 || i > map.hi_gth || j > map.wi_dth
		|| map.map[i - 1][j] == ' ' || map.map[i + 1][j] == ' '
		|| map.map[i][j - 1] == ' ' || map.map[i][j + 1] == ' ')
		exit(write(2, "Error: invalid map[ ]!!!\n", 23));
	return (true);
}
