/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 12:57:45 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# define ARR_SIZE 5

typedef enum e_shape
{
	sphere = 4,
	plane,
	cylinder,
	con,
	hyperboloid,
	paraboloid
}	t_shape;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_light
{
	struct s_point	point;
	float			light_ratio;
	uint32_t		color;
}	t_light;

typedef struct s_camera
{
	t_point	point;
	t_point	n_vector;
	int		fov;
}	t_camera;

typedef struct s_object
{
	t_shape		shape;
	t_point		point;
	t_point		n_vector;
	float		diameter;
	float		height;
	uint32_t	color;
}	t_object;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_mlx	params;
	struct s_light	**lights;
	struct s_object	**objects;
}	t_data;

t_object	**create_objlist(int n);
void		add_objlist(t_object *obj, t_object ***objlist);
//mlx 관련 함수 선언 (추후 분리 필요하면 분리)
int		init_img (t_data *data);
void	print_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_hooks(t_data *data);
int		key_hook(int keycode, t_data *data);

#endif
