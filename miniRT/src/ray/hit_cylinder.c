/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:31:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 20:11:33 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	get_tmin(double value[])
{
	if (value[0] == -1 && value[1] >= 0)
	{
		value[0] = value[1];
		value[1] = -1;
	}
	if (value[0] == -1)
		return (-2);
	else if (value[1] == -1)
		return (-1);
	return (0);
}

static int	cylinder_height(t_ray *ray, t_object *obj, double value[])
{
	int		i;
	t_point	p;
	t_point	c;
	double	p_height;

	i = -1;
	while (++i < 2)
	{
		p = v_add_vec(ray->origin_point, v_mul_val(ray->dir, value[i]));
		c = v_add_vec(obj->point, v_mul_val(obj->n_vector, -(obj->height / 2)));
		p_height = v_dot(v_sub_vec(p, c), obj->n_vector);
		if (0 > p_height || obj->height < p_height)
			value[i] = -1;
	}
	return (get_tmin(value));
}

int	cylinder_inf(t_ray *ray, t_object *obj, double *value)
{
	t_point	c_sub_o;

	c_sub_o = v_sub_vec(obj->point, ray->origin_point);
	*value = v_dot(c_sub_o, ray->dir);
	return (1);
}

int	hit_cylinder(t_ray *ray, t_object *obj, double value[])
{
	t_point	o_sub_c;
	double	a;
	double	b;
	double	c;
	int		value_num;

	o_sub_c = v_sub_vec(ray->origin_point, obj->point);
	a = pow(v_length(v_cross(ray->dir, obj->n_vector)), 2);
	b = 2 * v_dot(v_cross(ray->dir, obj->n_vector), \
		v_cross(o_sub_c, obj->n_vector));
	c = pow(v_length(v_cross(o_sub_c, obj->n_vector)), 2) - \
		pow(obj->diameter / 2, 2);
	if ((b * b - 4 * a * c) == 0 && fabs(v_dot(ray->dir, obj->n_vector)) == 1)
		return (cylinder_inf(ray, obj, &value[0]));
	value_num = r_formula(a, b, c, value);
	value_num += cylinder_height(ray, obj, value);
	return (value_num);
}
