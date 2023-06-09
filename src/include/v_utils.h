/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:30:17 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 15:23:04 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_UTILS_H
 #define V_UTILS_H

t_point	v_add_vec (t_point vec_origin, t_point vec_value); //벡터 합
t_point	v_add_val (t_point vec_origin, double x, double y, double z);
t_point	v_sub_vec (t_point vec_origin, t_point vec_value); //벡터 차
t_point	v_sub_val (t_point vec_origin, double x, double y, double z);
t_point	v_mul_vec(t_point vec_origin, t_point vec_value);
t_point	v_mul_val(t_point vec_origin, double value); //벡터의 스칼라 곱
t_point	v_div_vec(t_point vec_origin, t_point vec_value);
t_point	v_div_val(t_point vec_origin, double value); //벡터의 스칼라 나누기
double	v_length (t_point vec_origin); //길이
t_point	v_unit (t_point vec_origin); //단위벡터
t_point	v_dot (t_point vec_origin, t_point vec_value); //내적
t_point	v_cross (t_point vec_origin, t_point vec_value); //외적
#endif