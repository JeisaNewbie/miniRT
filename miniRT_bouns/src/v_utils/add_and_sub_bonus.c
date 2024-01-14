/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_sub_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:40:41 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 20:16:28 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

t_point	set_vec(double x, double y, double z)
{
	t_point	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	v_add_vec(t_point vec_origin, t_point vec_value)
{
	vec_origin.x += vec_value.x;
	vec_origin.y += vec_value.y;
	vec_origin.z += vec_value.z;
	return (vec_origin);
}

t_point	v_add_val(t_point vec_origin, double x, double y, double z)
{
	vec_origin.x += x;
	vec_origin.y += y;
	vec_origin.z += z;
	return (vec_origin);
}

t_point	v_sub_vec(t_point vec_origin, t_point vec_value)
{
	vec_origin.x -= vec_value.x;
	vec_origin.y -= vec_value.y;
	vec_origin.z -= vec_value.z;
	return (vec_origin);
}

t_point	v_sub_val(t_point vec_origin, double x, double y, double z)
{
	vec_origin.x -= x;
	vec_origin.y -= y;
	vec_origin.z -= z;
	return (vec_origin);
}
