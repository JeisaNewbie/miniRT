/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 17:50:59 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAY_H
# define RAY_H

# include "./types.h"

u_int32_t	create_trgb(t_data *data, t_rec *rec, int flag);
u_int32_t	diffuse(t_light *light, t_rec *rec);
double		max(double a, double b);
int			hit_sphere(t_ray *ray, t_object *obj, double value[]);
int			hit_plane(t_ray *ray, t_object *obj, double value[]);
int			hit_cylinder(t_ray *ray, t_object *obj, double value[]);
int			is_front(t_camera *cam, t_object *obj, double t);
int			hit_cone(t_ray *ray, t_object *obj, double value[]);
int			hit_circle(t_ray *ray, t_object *obj, double value[]);
int			r_formula(double a, double b, double c, double value[]);

t_ray		get_ray(t_point origin, t_point dir);
t_rec		get_intersection(t_ray *ray, t_object *obj);	//ray와 obj의 교점을 가지고 온다.
t_rec		find_closestobj(t_ray *ray, t_object *objs);	//교점 중 가장 가까운 오브젝트

#endif