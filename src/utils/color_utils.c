/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 22:34:45 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	max_color(double value)
{
	if (0 > value)
		return (0);
	else if (value < 0xFF)
		return (value);
	else
		return (0xFF);
}

u_int32_t	create_color(double r, double g, double b)
{
	u_int32_t	color;

	color = (int)b;
	color |= (int)g << 8;
	color |= (int)r << 16;
	return (color);
}

u_int32_t	add_color_col(u_int32_t old_color, u_int32_t add_color)
{
	u_int32_t	color;
	double		tmp;

	color = 0;
	tmp = (add_color & 0xFF) + (old_color & 0xFF);
	color |= (int)max_color(tmp);
	tmp = ((add_color >> 8) & 0xFF) + ((old_color >> 8) & 0xFF);
	color |= (int)max_color(tmp) << 8;
	tmp = ((add_color >> 16) & 0xFF) + ((old_color >> 16) & 0xFF);
	color |= (int)max_color(tmp) << 16;
	return (color);
}

u_int32_t	add_color_val(u_int32_t old_color, double r, double g, double b)
{
	u_int32_t	color;
	double		tmp;

	color = 0;
	tmp = b + (old_color & 0xFF);
	color |= (int)max_color(tmp);
	tmp = g + ((old_color >> 8) & 0xFF);
	color |= (int)max_color(tmp) << 8;
	tmp = r + ((old_color >> 16) & 0xFF);
	color |= (int)max_color(tmp) << 16;
	return (color);
}

u_int32_t	mul_color(u_int32_t old_color, double value)
{
	u_int32_t	color;
	double		tmp;

	color = 0;
	tmp = (old_color & 0xFF) * value;
	color |= (int)max_color(tmp);
	tmp = ((old_color >> 8) & 0xFF) * value;
	color |= (int)max_color(tmp) << 8;
	tmp = ((old_color >> 16) & 0xFF) * value;
	color |= (int)max_color(tmp) << 16;
	return (color);
}
