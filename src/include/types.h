/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/06 16:04:18 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# define ARR_SIZE 5
# define KEY_PRESS 2
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define CLOSE_WIN 17
# define PI 3.1415926535

typedef enum e_shape
{
	sphere = 4,
	plane,
	cylinder,
	cone,
	hyperboloid,
	paraboloid,
	circle
}	t_shape;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_light
{
	struct s_point	point;
	double			light_ratio;
	uint32_t		color;
}	t_light;

typedef struct s_object
{
	t_shape		shape;
	t_point		point;
	t_point		n_vector;
	double		diameter;
	double		height;
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

typedef struct s_ray
{
	t_point	origin_point;
	t_point	dir;
	double	t;
}	t_ray;

typedef struct s_rot
{
	t_point	rotate_x;
	t_point	rotate_y;
	t_point	rotate_z;
	t_point	value;
}	t_rot;

typedef struct s_camera
{
	t_ray	ray;
	t_rot	rotate;
	t_point	n_vector; //카메라가 보는 방향
	t_point	center;
	t_point	view_port_lb; //left bottom
	t_point	horizontal;//수평길이
	t_point	vertical;//수직길이
	double	view_port_w; //fov 증가시 같이 증가
	double	view_port_h; //fov 증가시 같이 증가
	double	ratio; //종횡비, mlx의 width / height; view port의 한 길이를 설정했을때 다른 부분을 비율로 정함
	double	focal_length; //뷰포인트까지의 거리, 1.0으로 고정
	int		fov;
}	t_camera;

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_mlx	params;
	struct s_light	**lights;
	struct s_object	**objects;
}	t_data;

typedef struct s_rec
{
	double		t;
	int			shadow;
	t_point		frag_point;
	t_shape		hit_shape;
	t_point		n_vector;
	t_object	*hit_obj;
}	t_rec;

t_object	**create_objlist(int n);
void		add_objlist(t_object *obj, t_object ***objlist);
//mlx 관련 함수 선언 (추후 분리 필요하면 분리)
int			init_img(t_data *data);
void		print_img(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, u_int32_t color);
void		mlx_hooks(t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_win(t_data *data);
void		free_data(t_data *data);

#endif
