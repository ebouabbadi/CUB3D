/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:01:32 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:01:34 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	_error(char *error_name)
{
	perror(error_name);
	exit(1);
}

void	free_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
}

void	init_ray(t_ray *ray)
{
	ray->first_y = NOT_INIT;
	ray->first_x = NOT_INIT;
	ray->flag_horizental = NOT_INIT;
	ray->flag_vertical = NOT_INIT;
	ray->x = NOT_INIT;
	ray->y = NOT_INIT;
}

void	free_map_list(t_list *map, int height)
{
	t_list	*head;

	head = map;
	while (head && height > 0)
	{
		free(head->content);
		head = head->next;
	}
}
