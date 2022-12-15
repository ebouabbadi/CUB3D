/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:21 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:22 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include <libft.h>
# include <get_next_line.h>

# include <mlx.h>
# include <stdbool.h>
# include <data_struct.h>
# include <treD_hndlr.h>

# define BLOCK 64

# define WIDTH 896
# define HIGHT 512

# define FOV 1.0471975512	   /* field of view 60^ */
# define PRJ_PLN 28			   /* projection plane (full screan | tail size) */
# define ABSRAYS 0.001168747267 /* the angle between subsequent rays */
/*((HIGHT) / 2) / tan(FOV / 2)*/
/* distance between the player and the projection plane */
# define DBPP 452.0652607737

# define RETAION 0.07
//            < - - - - parsing - - - - >
t_cub3d	*cub3d_init(void);
void	init_ray(t_ray *ray);
void	get_texture_path_(t_cub3d *infos, char *line, int *count);
void	get_color(t_cub3d *infos, char *line, int *count);
void	check_extention(char *file_name);
int		get_token(char *line);
void	get_infos(t_cub3d *infos, int fd);
void	parsing(t_cub3d *infos, char *file_name);
void	_error(char *error_name);
void	free_colors(char **colors);
void	free_map_list(t_list *map, int height);
int		check_wals(char *border, int index);
void	get_map(int fd, t_cub3d *infos, char *first_line);

// < - - - - - - - - - - - - - - - - - - >
int		render_next_frame(t_cub3d *cub3d);
int		keypress(int key, t_cub3d *cub3d);
int		keyrelease(int key, t_cub3d *cub3d);
int		out(t_cub3d *cub3d);

int		win_out(int key, t_cub3d *cub3d);
void	init_maps(t_cub3d *cub3d);
void	raycasting(t_cub3d *cub);
int		vertical_line_left(t_cub3d *cub, int flag_horizental);
int		vertical_line_right(t_cub3d *cub, int flag_horizental);
int		horizental_line_up(t_cub3d *cub, int flag_horizental);
int		horizental_line_down(t_cub3d *cub, int flag_horizental);

#endif
