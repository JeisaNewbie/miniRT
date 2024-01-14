/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_and_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:42:50 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/14 21:54:23 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	v_dot(t_point vec_origin, t_point vec_value)
{
	return ((vec_origin.x * vec_value.x)
		+ (vec_origin.y * vec_value.y)
		+ (vec_origin.z * vec_value.z));
}

t_point	v_cross(t_point vec_origin, t_point vec_value)
{
	t_point	vec_cross;

	vec_cross.x = vec_origin.y * vec_value.z - vec_origin.z * vec_value.y;
	vec_cross.y = vec_origin.z * vec_value.x - vec_origin.x * vec_value.z;
	vec_cross.z = vec_origin.x * vec_value.y - vec_origin.y * vec_value.x;
	return (vec_cross);
}

int	v_null(t_point vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	return (0);
}
