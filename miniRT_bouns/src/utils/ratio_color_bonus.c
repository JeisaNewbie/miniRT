/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 18:22:25 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

t_color	ratio_color_val(t_color old_col, double ratio)
{
	t_color	color;

	color.r = max_color(old_col.r * ratio);
	color.g = max_color(old_col.g * ratio);
	color.b = max_color(old_col.b * ratio);
	return (color);
}

t_color	ratio_color_col(t_color old_col, t_color ratio_col)
{
	t_color	color;

	color.r = max_color(old_col.r * max_ratio((double)ratio_col.r / 0xFF));
	color.g = max_color(old_col.g * max_ratio((double)ratio_col.g / 0xFF));
	color.b = max_color(old_col.b * max_ratio((double)ratio_col.b / 0xFF));
	return (color);
}
