/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:19:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/17 20:07:07 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H
# include "./types_bonus.h"

# define FOCAL_LENGTH 2

void		init_origin_point(t_ray *ray, t_point center);
void		init_dir(t_camera *cam, double u, double v);
void		set_cposition(t_data *data, double ratio);
void		init_screen(t_camera *camera, t_point u, t_point v, t_point w);

#endif
