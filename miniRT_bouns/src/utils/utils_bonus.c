/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:36:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:16:04 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}

double	max_ratio(double value)
{
	if (0.0 > value)
		return (0.0);
	else if (value < 1.0)
		return (value);
	return (1.0);
}

int	max_color(int value)
{
	if (0 > value)
		return (0);
	else if (value < 0xFF)
		return (value);
	return (0xFF);
}
