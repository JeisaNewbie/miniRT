/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_closestobj_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:09:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 18:00:42 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

static t_point	get_raydir(double i, double j, t_camera *cam)
{
	return (v_unit (v_sub_vec (v_add_vec (v_add_vec (cam->view_port_lb, \
				v_mul_val (cam->horizontal, i)), \
				v_mul_val (cam->vertical, j)), cam->ray.origin_point)));
}

void	select_closestobj(int x, int y, t_data *data)
{
	t_ray	this_ray;
	t_rec	hit_obj;

	this_ray.origin_point = data->camera.center;
	this_ray.dir = get_raydir((double)x / (data->params.width - 1), \
		(double)y / (data->params.height - 1), &(data->camera));
	hit_obj = find_closestobj(&this_ray, data->objects);
	if (hit_obj.t >= 0)
	{
		printf("HIT_DIST: %lf\n", hit_obj.t);
		print_obj(hit_obj.hit_obj);
	}
	else
		printf("[ Nothing obj %lf ]\n", hit_obj.t);
}
