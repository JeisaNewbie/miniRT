/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:44:45 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 19:41:25 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	hit_objs(t_ray *ray, t_object *obj)
{
	int		value_num;
	double	value[2];

	value_num = 0;
	value[0] = -1;
	value[1] = -1;
	if (obj->shape == sphere)
		value_num = hit_sphere(ray, obj, value);
	else if (obj->shape == plane)
		value_num = hit_plane(ray, obj, value);
	else if (obj->shape == cylinder)
		value_num = hit_cylinder(ray, obj, value);
	if (value[0] < 0)
	{
		if (value_num == 2 && value[1] >= 0)
			return (value[1]);
		return (-1);
	}
	return (value[0]);
}

int	r_formula(double a, double b, double c, double value[])
{
	double	determinant;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (0);
	else if (determinant == 0)
	{
		value[0] = -1.0 * b / (2 * a);
		return (1);
	}
	value[0] = (-1.0 * b - sqrt (determinant)) / (2 * a);
	value[1] = (-1.0 * b + sqrt (determinant)) / (2 * a);
	return (2);
}

int	hit_sphere(t_ray *ray, t_object *obj, double value[])
{
	t_point	o_sub_c;
	double	a;
	double	b;
	double	c;

	o_sub_c = v_sub_vec (ray->origin_point, obj->point);
	a = fabs(v_dot (ray->dir, ray->dir));
	b = v_dot (o_sub_c, v_mul_val(ray->dir, 2.0));
	c = fabs(v_dot (o_sub_c, o_sub_c)) - pow (obj->diameter / 2, 2);
	return (r_formula(a, b, c, value));
}

int	hit_plane(t_ray *ray, t_object *obj, double value[])
{
	double	numer;
	double	denom;

	numer = v_dot (v_sub_vec (obj->point, ray->origin_point), obj->n_vector);
	denom = v_dot (ray->dir, obj->n_vector);
	if (denom == 0)
		return (0);
	else if (numer == 0)
		value[0] = 0;
	else
		value[0] = numer / denom;
	return (1);
}
