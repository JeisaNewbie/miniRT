/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/17 19:44:01 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	check_block(t_ray *ray, t_object *obj)
{
	double	t;
	double	circle_dist;

	t = hit_objs(ray, obj);
	if (obj->shape == cylinder)
	{
		circle_dist = hit_circle(ray, obj);
		if (0 <= circle_dist && (t < 0 || circle_dist < t))
			return (circle_dist);
	}
	return (t);
}

int	is_shadow(t_list *objs, t_light *light, t_point frag_point)
{
	t_point	l_sub_p;
	t_ray	ray;
	t_list	*now;
	double	max;
	double	t;

	l_sub_p = v_sub_vec(light->point, frag_point);
	max = v_length(l_sub_p);
	ray.dir = v_unit(l_sub_p);
	ray.origin_point = v_add_vec(frag_point, v_mul_val(ray.dir, EPSILON));
	now = objs;
	while (now)
	{
		t = check_block(&ray, (t_object *)(now->content));
		if (0 < t && t <= max)
			return (1);
		now = now->next;
	}
	return (0);
}
