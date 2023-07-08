/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:55:54 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 22:12:14 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./types.h"

u_int32_t	create_color(double r, double g, double b);
u_int32_t	add_color_col(u_int32_t old_color, u_int32_t add_color);
u_int32_t	add_color_val(u_int32_t old_color, double r, double g, double b);
u_int32_t	mul_color(u_int32_t old_color, double value);

double		max(double a, double b);

#endif