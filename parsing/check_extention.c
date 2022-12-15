/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:30:56 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/11 19:29:48 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_extention(char *file_name)
{
	if (ft_strlen(file_name) < 4)
	{
		write(2, "extention must be .cub\n", 24);
		exit(24);
	}
	if (ft_strcmp(".cub", file_name + (ft_strlen(file_name) - 4)))
	{
		write(2, "extention must be .cub\n", 24);
		exit(24);
	}
}
