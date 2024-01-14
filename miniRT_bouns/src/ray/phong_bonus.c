/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/18 18:24:11 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

uint32_t	get_color(t_data *data, t_rec *rec)
{
	t_color		color;
	t_color		phong_color;
	t_list		*now;

	if (rec->t < 0)
		return (0);
	color = rec->hit_color;
	phong_color = ambient(&(data->a_light));
	now = data->lights;
	while (now)
	{
		if (!is_shadow(data->objects, \
			(t_light *)(now->content), rec->frag_point))
			phong_color = add_color (phong_color, \
			apply_phong ((t_light *)(now->content), rec, &(data->camera.ray)));
		now = now->next;
	}
	return (trans_color_int(ratio_color_col(phong_color, color)));
}

t_color	apply_phong(t_light *light, t_rec *rec, t_ray *ray)
{
	return (add_color(diffuse(light, rec), specular(light, rec, ray)));
}

t_color	ambient(t_light *a_light)
{
	return (ratio_color_val(a_light->color, a_light->light_ratio));
}

t_color	diffuse(t_light *light, t_rec *rec)
{
	t_color	light_color;
	double	diff;

	light_color = ratio_color_val(light->color, light->light_ratio);
	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (light->point,
						rec->frag_point))), 0.0);
	return (ratio_color_val(light_color, diff));
}

t_color	specular(t_light *light, t_rec *rec, t_ray *ray)
{
	t_color	light_color;
	t_ray	reflect_ray;
	t_point	lightdir;
	double	spec;
	int		alpa;

	light_color = ratio_color_val(light->color, light->light_ratio);
	alpa = 32;
	lightdir = v_unit(v_sub_vec(light->point, rec->frag_point));
	reflect_ray.origin_point = rec->frag_point;
	reflect_ray.dir = v_unit(v_sub_vec(lightdir, v_mul_val(\
		v_mul_val(rec->n_vector, v_dot(lightdir, rec->n_vector)), 2)));
	spec = fmax(v_dot(reflect_ray.dir, ray->dir), 0.0);
	return (ratio_color_val(light_color, pow(spec, alpa)));
}
