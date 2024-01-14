/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_and_unit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:43:17 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 20:16:34 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

double	v_length(t_point vec_origin)
{
	return (sqrt ((vec_origin.x * vec_origin.x) \
		+ (vec_origin.y * vec_origin.y) \
		+ (vec_origin.z * vec_origin.z)));
}

t_point	v_unit(t_point vec_origin)
{
	double	len;

	len = v_length (vec_origin);
	if (len == 0.0)
	{
		perror ("Denominator is zero\n");
		exit (1);
	}
	return (v_div_val (vec_origin, len));
}
