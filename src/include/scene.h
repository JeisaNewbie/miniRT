/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:19:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/06/28 23:47:12 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "./types.h"

void		init_origin_point(t_ray *ray, t_point center);
void		init_dir(t_camera *cam, double u, double v);
void		set_cposition(t_data *data, double ratio);
void		init_screen(t_camera *camera, t_point u, t_point v, t_point w);

#endif
