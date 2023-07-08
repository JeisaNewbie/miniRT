/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/06 19:27:29 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

u_int32_t	get_color(t_data *data, t_rec *rec)
{
	t_ray		ray_to_light;
	u_int32_t	color;
	int			i;
	int			flag;

	i = -1;
	color = 0;
	flag = 1;
	while (data->lights[++i])
	{
		ray_to_light = get_ray (rec->frag_point,
				v_sub_vec (data->lights[i]->point, rec->frag_point));
		rec->shadow = is_shadow (data->objects, ray_to_light);
		if (rec->shadow == 1)
			continue ;
		color = add_color_col (color, apply_phong (&data->a_light, data->lights[i], rec, flag));
		flag = 0;
	}
	return (color);
}

u_int32_t	apply_phong(t_light *a_light, t_light *light, t_rec *rec, int flag)
{
	u_int32_t	phong_color;

	phong_color = 0;
	if (flag == 1)
		phong_color = ambient (a_light, rec);
	else
		phong_color = rec->hit_obj->color;
	phong_color = diffuse (light, rec, phong_color);
	phong_color &= light->color;
	return (phong_color);
}

u_int32_t	ambient(t_light *a_light, t_rec *rec)
{
	u_int32_t	color;

	color = mul_color(rec->hit_obj->color, a_light->light_ratio);
	color &= a_light->color;
	return (color);
}

u_int32_t	diffuse(t_light *light, t_rec *rec, u_int32_t color)
{
	double	diff;

	if (rec->t < 0)
		return (0);
	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (light->point,
						rec->frag_point))), 0.0);
	return (mul_color(color, diff));
}
