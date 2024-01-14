/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:19:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/05 20:46:59 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "./types.h"

# define FOCAL_LENGTH 2

void		init_origin_point(t_ray *ray, t_point center);
void		init_dir(t_camera *cam, double u, double v);
void		set_cposition(t_data *data, double ratio);
void		init_screen(t_camera *camera, t_point u, t_point v, t_point w);

#endif
