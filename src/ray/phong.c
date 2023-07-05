/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:19:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/05 22:23:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}


u_int32_t	get_color(t_data *data, t_rec *rec)
{
	t_point		dir_to_light;
	u_int32_t	color;
	double		t;
	int			i;

	i = -1;
	color = 0;
	while (data->lights[++i])
	{
		dir_to_light = v_sub_vec (data->lights[i]->point, rec->frag_point);
		t = v_length (dir_to_light);
		rec->shadow = 0;
		check_block (rec, data->objects, dir_to_light, t);
		if (rec->shadow == 1)
			continue ;
		color = apply_phong (data->lights[i], rec->hit_obj->color, color);
	}
}

int	check_block(t_rec *rec, t_object **obj, t_point dir_to_light, double t)
{
	t_ray	ray;
	int		i;

	ray = get_ray (rec->frag_point, dir_to_light);
	i = -1;
	while (obj[++i])
	{
		if ()
			break ;
	}
	rec->shadow = 1;
}

u_int32_t	diffuse(t_light *light, t_rec *rec)
{
	double	diff;
	double	r;
	double	g;
	double	b;

	diff = max (v_dot (rec->n_vector,
				v_unit (v_sub_vec (light->point,
						rec->frag_point))), 0.0);
	b = ((rec->hit_obj->color & 255));
	g = (((rec->hit_obj->color >> 8) & 255) % 256);
	r = (((rec->hit_obj->color >> 16) & 255) % 256);
	return (0 | (int)(r * diff) << 16 | (int)(g * diff) << 8 | (int)(b * diff));
}
