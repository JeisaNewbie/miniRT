/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:46:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 17:37:19 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

static t_point	cylinder_n_vector(t_ray *ray, t_point p, t_object *obj)
{
	t_point	c;
	t_point	p_sub_c;
	t_point	q_sub_c;
	t_point	l_sub_c;
	int		isin;

	isin = 1;
	c = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
	p_sub_c = v_sub_vec(p, c);
	q_sub_c = set_vec(0, 0, 0);
	l_sub_c = v_sub_vec(ray->origin_point, c);
	if (sqrt(pow(v_length(l_sub_c), 2) - pow(v_dot(l_sub_c, obj->n_vector), 2)) \
		< obj->diameter / 2)
		isin *= -1;
	if (v_dot(p_sub_c, obj->n_vector) != 0)
		q_sub_c = v_mul_val(obj->n_vector, v_dot(p_sub_c, obj->n_vector));
	else
		return (v_unit(v_mul_val(p_sub_c, isin)));
	return (v_unit(v_mul_val(v_sub_vec(p_sub_c, q_sub_c), isin)));
}

static t_point	cone_n_vector(t_ray *ray, t_point p, t_object *obj)
{
	t_point	c;
	t_point	p_sub_c;
	t_point	q_sub_c;
	double	l_dot_n;
	int		isin;

	isin = 1;
	c = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
	p_sub_c = v_sub_vec(p, c);
	q_sub_c = set_vec(0, 0, 0);
	l_dot_n = v_dot(v_unit(v_sub_vec(ray->origin_point, c)), obj->n_vector);
	if (l_dot_n > obj->height / \
		(sqrt(pow(obj->height, 2) + pow(obj->diameter / 2, 2))))
		isin *= -1;
	if (v_length(p_sub_c) != 0)
		q_sub_c = v_mul_val(obj->n_vector, \
			v_length(p_sub_c) / v_dot(v_unit(p_sub_c), obj->n_vector));
	else
		return (v_unit(v_mul_val(obj->n_vector, -isin)));
	return (v_unit(v_mul_val(v_sub_vec(p_sub_c, q_sub_c), isin)));
}

t_point	get_n_vector(t_ray *ray, t_point p, \
										t_shape hit_shape, t_object *obj)
{
	if (hit_shape == plane || hit_shape == circle)
	{
		if (v_dot(ray->dir, obj->n_vector) > 0)
			return (v_mul_val(obj->n_vector, -1));
		return (obj->n_vector);
	}
	else if (hit_shape == sphere)
	{
		if (v_length(\
			v_sub_vec(ray->origin_point, obj->point)) < obj->diameter / 2)
			return (v_mul_val(v_div_val(v_sub_vec(p, obj->point), \
				obj->diameter / 2), -1));
		return (v_div_val(v_sub_vec(p, obj->point), obj->diameter / 2));
	}
	else if (hit_shape == cylinder)
		return (cylinder_n_vector(ray, p, obj));
	else if (hit_shape == cone)
		return (cone_n_vector(ray, p, obj));
	return (set_vec(0, 0, 0));
}
