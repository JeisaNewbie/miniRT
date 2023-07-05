/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:30:17 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/28 17:24:16 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_UTILS_H
# define V_UTILS_H
# include "./types.h"

t_point	set_vec(double x, double y, double z);
t_point	v_add_vec(t_point vec_origin, t_point vec_value); //벡터 합
t_point	v_add_val(t_point vec_origin, double x, double y, double z);
t_point	v_sub_vec(t_point vec_origin, t_point vec_value); //벡터 차
t_point	v_sub_val(t_point vec_origin, double x, double y, double z);
t_point	v_mul_vec(t_point vec_origin, t_point vec_value);
t_point	v_mul_val(t_point vec_origin, double value); //벡터의 스칼라 곱
t_point	v_div_vec(t_point vec_origin, t_point vec_value);
t_point	v_div_val(t_point vec_origin, double value); //벡터의 스칼라 나누기
double	v_length(t_point vec_origin); //길이
t_point	v_unit(t_point vec_origin); //단위벡터
double	v_dot(t_point vec_origin, t_point vec_value); //내적
t_point	v_cross(t_point vec_origin, t_point vec_value); //외적
int		v_null(t_point vec);
#endif
