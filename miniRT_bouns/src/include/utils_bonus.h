/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:55:54 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 18:22:38 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "./types_bonus.h"

t_color		trans_color_struct(uint32_t col);
uint32_t	trans_color_int(t_color old_col);

t_color		create_color(double r, double g, double b);

t_color		ratio_color_val(t_color old_col, double value);
t_color		ratio_color_col(t_color old_col, t_color ratio_col);

t_color		add_color(t_color old_col, t_color add_col);

double		max(double a, double b);
double		max_ratio(double value);
int			max_color(int value);

void		print_obj(t_object *obj);

void		select_closestobj(int x, int y, t_data *data);

#endif
