/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:28 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:29 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef char	*t_path;

struct s_graphical_info
{
	int	en;
	int	bpp;
	int	sl;
};

struct s_keys
{
	bool	_w;
	bool	_a;
	bool	_s;
	bool	_d;
	bool	m_r;
	bool	m_l;
	bool	_esc;
};

typedef struct s_texture
{
	int						width;
	int						higth;
	int						next_x;
	struct s_graphical_info	gm;
	t_path					path;
	void					*img;
	int						*img_addr;
}t_xtr;

struct s_walls
{
	struct s_texture	east;
	struct s_texture	west;
	struct s_texture	north;
	struct s_texture	south;
};

typedef struct s_ray
{
	double	first_x;
	double	first_y;
	double	x;
	double	y;
	int		flag_vertical;
	int		flag_horizental;
}t_ray;

struct s_map
{
	long	wi_dth;
	long	hi_gth;
	char	**map;
	double	stepx;
	double	stepy;
	double	z_h;
	double	z_v;
	double	angle;
};

# define HORIZONTAL 0
# define VERTICAL 1

typedef struct cub3d
{
	void					*mlx;
	void					*window;
	int						p_x;
	int						p_y;
	struct s_keys			keys;
	double					angle;
	double					rotation;
	bool					flag;
	void					*img;
	int						*img_addr;
	struct s_map			map;
	struct s_walls			xs;
	struct s_graphical_info	ginfo;

	int						floor;
	int						ceilling;
	t_ray					ray_vertical;
	t_ray					ray_horizental;
}t_cub3d;

typedef enum map_token
{
	EMPTY_LINE,
	INVALIDE_LINE,
	DIRECTION,
	RGB_COLOR,
	MAP,
}t_map_token;

typedef struct s_mmap
{
	double	min_in;
	double	maxin;
	double	min_to;
	double	maxto;
}t_mapp;

#endif
