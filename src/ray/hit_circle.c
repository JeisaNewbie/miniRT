/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:58:16 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/29 18:21:47 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	_hit_circle(t_point h, t_ray *ray, t_object *obj)
{
	double	t;
	double	dist_p_h;
	t_point	p;

	t = v_length(v_sub_vec(ray->origin_point, h)) * \
		fabs(v_dot(v_unit(v_sub_vec(ray->origin_point, h)), obj->n_vector)) / \
		fabs(v_dot(ray->dir, obj->n_vector));
	p = v_add_vec(ray->origin_point, v_mul_val(ray->dir, t));
	dist_p_h = fabs(v_length(v_sub_vec(p, h)));
	if (dist_p_h > obj->diameter / 2)
		return (-1);
	return (t);
}

static int	parse_value(double c_value, double value[])
{
	if (c_value < 0)
		return (0);
	else if (value[0] < 0)
	{
		value[0] = c_value;
		return (1);
	}
	else if (value[1] < 0)
		value[0] = c_value;
	else
	{
		value[0] = c_value;
		value[1] = -1;
		return (-1);
	}
	return (0);
}

int	hit_circle(t_ray *ray, t_object *obj, double value[])
{
	double	b_value;
	double	t_value;
	t_point	h;

	if (v_dot(ray->dir, obj->n_vector) == 0)
		return (0);
	h = v_add_vec(obj->point, v_mul_val(obj->n_vector, obj->height / 2));
	b_value = _hit_circle(h, ray, obj);
	if (obj->shape == cylinder)
	{
		h = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
		t_value = _hit_circle(h, ray, obj);
		if (t_value != -1 && t_value < b_value)
			b_value = t_value;
	}
	return (parse_value(b_value, value));
}
