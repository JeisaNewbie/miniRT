/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_and_div_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:42:08 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 20:16:39 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

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
