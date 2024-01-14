/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:50:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/10 17:28:25 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	trans_color_struct(uint32_t col)
{
	t_color	color;

	color.r = col >> 16 & 0xFF;
	color.g = col >> 8 & 0xFF;
	color.b = col & 0xFF;
	return (color);
}

uint32_t	trans_color_int(t_color old_col)
{
	return ((max_color(old_col.r) << 16) + \
		(max_color(old_col.g) << 8) + max_color(old_col.b));
}
