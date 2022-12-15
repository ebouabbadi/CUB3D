/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treD_hndlr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:41 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:42 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRED_HNDLR_H
# define TRED_HNDLR_H

# include <cub3d.h>

# define TO_MILL 0 // [0, 1000000]
# define FROM_MILL 1
# define MILL 1000000

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define UP 65362
# define DOWN 65364
# define M_L 123
# define M_R 124

# define NOT_INIT -1

bool	check_for_empty_space(struct s_map map, int i, int j);
int		get_map_content(int fd, t_list **map);
void	map_list_to_array(t_list *map, t_cub3d *cub3d, int height);

/** diset : distance between player and wall */
void	draw_wall(t_cub3d *cub, double diset);
void	drew_env(t_cub3d *cub3d); /* floor and roof */
double	fishbowl(t_cub3d *cub3d, double distr);

int		create_trgb(int t, int r, int g, int b);

void	get_img_from_files(t_cub3d *cub3d);
double	math_chasles(int x1, int y1, int x2, int y2);
/** TO_MILL or FROM_MILL (standar range (MILL))*/
double	math_map(double val, t_mapp k);
double	max(double a, double b);
double	min(double a, double b);

#endif
