/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closestobj_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:59:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 15:50:35 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

t_rec	get_intersection(t_ray *ray, t_object *obj)
{
	t_rec	rec;
	double	circle_dist;

	circle_dist = -1;
	ft_memset(&rec, 0, sizeof(t_rec));
	rec.hit_obj = obj;
	rec.hit_shape = obj->shape;
	rec.t = hit_objs(ray, obj);
	if (obj->shape == cylinder || obj->shape == cone)
	{
		circle_dist = hit_circle(ray, obj);
		if (0 <= circle_dist && (rec.t < 0 || circle_dist < rec.t))
		{
			rec.t = circle_dist;
			rec.hit_shape = circle;
		}
	}
	rec.frag_point = v_add_vec(ray->origin_point, v_mul_val(ray->dir, rec.t));
	rec.n_vector = get_n_vector(ray, rec.frag_point, rec.hit_shape, obj);
	rec.hit_color = obj->color;
	return (rec);
}

t_rec	find_closestobj(t_ray *ray, t_list *objs)
{
	t_rec	rec;
	t_rec	tmp;
	t_list	*now;
	double	t;

	rec.t = -1;
	if (!objs)
		return (rec);
	t = MAXFLOAT;
	now = objs;
	while (now)
	{
		tmp = get_intersection(ray, (t_object *)(now->content));
		if (tmp.t >= 0 && t > tmp.t)
		{
			rec = tmp;
			t = tmp.t;
		}
		now = now->next;
	}
	return (rec);
}
