/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:06 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 20:50:14 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	init_rec(t_rec *rec, t_rec rec_src)
{
	if (rec_src.t >= 0)
	{
		rec->hit_obj = rec_src.hit_obj;
		rec->hit_shape = rec_src.hit_shape;
		rec->t = rec_src.t;
		rec->frag_point = rec_src.frag_point;
		rec->n_vector = rec_src.n_vector;
	}
	else
		rec->t = -1;
}

u_int32_t	create_trgb(t_data *data, t_rec *rec)
{
	const double	t_min = FOCAL_LENGTH / \
					v_dot((data->camera).n_vector, ((data->camera).ray).dir);
	u_int32_t		color;
	t_ray			viewport_ray;

	color = 0;
	init_rec(rec, find_closestobj(&(data->camera.ray), data->objects));
	if (rec->t < t_min)
	{
		viewport_ray.dir = ((data->camera).ray).dir;
		viewport_ray.origin_point = v_add_vec((data->camera).ray.origin_point, \
			v_mul_val(((data->camera).ray).dir, t_min));
		init_rec(rec, find_closestobj(&viewport_ray, data->objects));
	}
	if (rec->t >= 0)
		color = (rec->hit_obj)->color;
	return (color);
}
