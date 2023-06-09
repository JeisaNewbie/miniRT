/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:40:41 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 13:55:04 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_point	v_add_vec (t_point vec_origin, t_point vec_value)
{
	vec_origin.x += vec_value.x;
	vec_origin.y += vec_value.y;
	vec_origin.z += vec_value.z;
	return (vec_origin);
}

t_point	v_add_val (t_point vec_origin, double x, double y, double z)
{
	vec_origin.x += x;
	vec_origin.y += y;
	vec_origin.z += z;
	return (vec_origin);
}

t_point	v_sub_vec (t_point vec_origin, t_point vec_value)
{
	vec_origin.x -= vec_value.x;
	vec_origin.y -= vec_value.y;
	vec_origin.z -= vec_value.z;
	return (vec_origin);
}

t_point	v_sub_val (t_point vec_origin, double x, double y, double z)
{
	vec_origin.x -= x;
	vec_origin.y -= y;
	vec_origin.z -= z;
	return (vec_origin);
}