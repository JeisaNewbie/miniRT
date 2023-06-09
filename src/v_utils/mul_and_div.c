/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_and_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:42:08 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 13:59:22 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_point	v_mul_vec(t_point vec_origin, t_point vec_value)
{
	vec_origin.x *= vec_value.x;
	vec_origin.y *= vec_value.y;
	vec_origin.z *= vec_value.z;
	return (vec_origin);
}

t_point	v_mul_val(t_point vec_origin, double value)
{
	vec_origin.x *= value;
	vec_origin.y *= value;
	vec_origin.z *= value;
	return (vec_origin);
}

t_point	v_div_vec(t_point vec_origin, t_point vec_value)
{
	vec_origin.x /= vec_value.x;
	vec_origin.y /= vec_value.y;
	vec_origin.z /= vec_value.z;
	return (vec_origin);
}

t_point	v_div_val(t_point vec_origin, double value)
{
	vec_origin.x /= value;
	vec_origin.y /= value;
	vec_origin.z /= value;
	return (vec_origin);
}