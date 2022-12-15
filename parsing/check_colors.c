/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/11 21:33:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_if_empty(char *color)
{
	int	i;

	i = 0;
	if (color[0] == '\0')
		return (1);
	while (color[i])
	{
		if (color[i] != ' ' && ft_isdigit(color[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_color(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		if (check_if_empty(colors[i]))
			return (0);
		while (colors[i][j])
		{
			if ((!ft_isdigit(colors[i][j]) && colors[i][j] != 32))
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

static int	callcul_color(char *rgb_color)
{
	char	**colors;
	int		color;

	if (!rgb_color)
		_error("ft_strtrim");
	colors = ft_split(rgb_color, ',');
	free(rgb_color);
	if (!colors)
		_error("ft_split");
	errno = 0;
	if (!parse_color(colors))
		_error("rgb color");
	color = create_trgb(0, \
	ft_atoi(colors[0]), ft_atoi(colors[1]), ft_atoi(colors[2]));
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
	return (color);
}

void	get_color(t_cub3d *cub3d, char *line, int *count)
{
	*count += 1;
	if (line[0] == 'F' && cub3d->floor == NOT_INIT)
		cub3d->floor = callcul_color(ft_strtrim(&line[1], " \n"));
	else if (line[0] == 'C' && cub3d->ceilling == NOT_INIT)
		cub3d->ceilling = callcul_color(ft_strtrim(&line[1], " \n"));
}
