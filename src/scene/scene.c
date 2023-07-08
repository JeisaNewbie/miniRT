/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:14:24 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/05 20:43:16 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_origin_point(t_ray *ray, t_point center)
{
	ray->origin_point = set_vec (center.x, center.y, center.z);
}

void	init_dir(t_camera *cam, double u, double v)
{
	cam->ray.dir = v_unit (v_sub_vec (v_add_vec (v_add_vec (cam->view_port_lb,
						v_mul_val (cam->horizontal, u)),
					v_mul_val (cam->vertical, v)), cam->ray.origin_point));
}

void	set_cposition(t_data *data, double ratio)
{
	t_point	vup;
	t_point	u;
	t_point	v;
	t_point	w;

	vup = set_vec (0, 1, 0);
	if (data->camera.n_vector.y > 0.0
		&& data->camera.n_vector.x == 0.0 && data->camera.n_vector.z == 0.0)
		vup = set_vec (0, 1, 0.1);
	w = v_mul_val (data->camera.n_vector, -1);
	u = v_cross (data->camera.n_vector, vup);
	v = v_cross (u, data->camera.n_vector);
	data->camera.ratio = ratio;
	init_screen (&data->camera, u, v, w);
	data->camera.rotate.rotate_x = set_vec (u.x, v.x, data->camera.n_vector.x);
	data->camera.rotate.rotate_y = set_vec (u.y, v.y, data->camera.n_vector.y);
	data->camera.rotate.rotate_z = set_vec (u.z, v.z, data->camera.n_vector.z);
}

void	init_screen(t_camera *camera, t_point u, t_point v, t_point w)
{
	double	h;

	init_origin_point (&camera->ray, camera->center);
	h = tan ((camera->fov / 2) * PI / 180);
	camera->view_port_w = FOCAL_LENGTH * h;
	camera->view_port_h = camera->view_port_w / camera->ratio;
	camera->horizontal = v_mul_val (u, camera->view_port_w);
	camera->vertical = v_mul_val (v, camera->view_port_h);
	camera->view_port_lb = v_sub_vec (v_sub_vec (v_sub_vec (camera->ray.origin_point, w),
		v_div_val (camera->horizontal, 2)), v_div_val (camera->vertical, 2));
}
