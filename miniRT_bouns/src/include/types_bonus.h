/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:28:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 15:48:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "../../mlx/mlx.h"

# define KEY_PRESS 2
# define MOUSEDOWN 4
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define CLOSE_WIN 17

# define EPSILON 1e-6

typedef enum e_shape
{
	amb = 1,
	camera,
	light,
	sphere,
	plane,
	cylinder,
	cone,
	circle
}	t_shape;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_light
{
	struct s_point	point;
	double			light_ratio;
	struct s_color	color;
	struct s_light	*next;
}	t_light;

typedef struct s_object
{
	t_shape			shape;
	struct s_point	point;
	struct s_point	n_vector;
	double			diameter;
	double			height;
	struct s_color	color;
	struct s_object	*next;
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
}	t_ray;

typedef struct s_camera
{
	t_ray	ray;
	t_point	n_vector;
	t_point	center;
	t_point	view_port_lb;
	t_point	horizontal;
	t_point	vertical;
	double	view_port_w;
	double	view_port_h;
	double	ratio;
	int		fov;
}	t_camera;

typedef struct s_data
{
	struct s_light	a_light;
	struct s_camera	camera;
	struct s_mlx	params;
	struct s_list	*lights;
	struct s_list	*objects;
}	t_data;

typedef struct s_rec
{
	double		t;
	t_point		frag_point;
	t_shape		hit_shape;
	t_point		n_vector;
	t_color		hit_color;
	t_object	*hit_obj;
}	t_rec;

int			init_img(t_data *data);
void		print_img(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, uint32_t color);
void		mlx_hooks(t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_win(t_data *data);
void		free_data(t_data *data);

#endif
