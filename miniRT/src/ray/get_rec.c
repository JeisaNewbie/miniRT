/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:06 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/12 00:54:41 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_rec	get_rec(t_data *data)
{
	const double	t_min = FOCAL_LENGTH / \
					v_dot((data->camera).n_vector, ((data->camera).ray).dir);
	t_rec			rec;
	t_ray			viewport_ray;

	rec = find_closestobj(&(data->camera.ray), data->objects);
	if (0 <= rec.t && rec.t < t_min)
	{
		viewport_ray.dir = ((data->camera).ray).dir;
		viewport_ray.origin_point = v_add_vec((data->camera).ray.origin_point, \
			v_mul_val(((data->camera).ray).dir, t_min));
		rec = find_closestobj(&viewport_ray, data->objects);
	}
	return (rec);
}
