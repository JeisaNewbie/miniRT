/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:30:17 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 20:16:19 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_UTILS_BONUS_H
# define V_UTILS_BONUS_H
# include "./types_bonus.h"

t_point	set_vec(double x, double y, double z);
t_point	v_add_vec(t_point vec_origin, t_point vec_value);
t_point	v_add_val(t_point vec_origin, double x, double y, double z);
t_point	v_sub_vec(t_point vec_origin, t_point vec_value);
t_point	v_sub_val(t_point vec_origin, double x, double y, double z);
t_point	v_mul_vec(t_point vec_origin, t_point vec_value);
t_point	v_mul_val(t_point vec_origin, double value);
t_point	v_div_vec(t_point vec_origin, t_point vec_value);
t_point	v_div_val(t_point vec_origin, double value);
double	v_length(t_point vec_origin);
t_point	v_unit(t_point vec_origin);
double	v_dot(t_point vec_origin, t_point vec_value);
t_point	v_cross(t_point vec_origin, t_point vec_value);
int		v_null(t_point vec);
#endif
