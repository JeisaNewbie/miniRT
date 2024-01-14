/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 17:04:15 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

# include "./types_bonus.h"

t_rec		get_rec(t_data *data);

uint32_t	get_color(t_data *data, t_rec *rec);

t_color		apply_phong(t_light *light, t_rec *rec, t_ray *ray);
t_color		ambient(t_light *a_light);
t_color		diffuse(t_light *light, t_rec *rec);
t_color		specular(t_light *light, t_rec *rec, t_ray *ray);

double		max(double a, double b);

double		hit_objs(t_ray *ray, t_object *obj);

int			r_formula(double a, double b, double c, double value[]);

int			hit_sphere(t_ray *ray, t_object *obj, double value[]);
int			hit_plane(t_ray *ray, t_object *obj, double value[]);
int			hit_cylinder(t_ray *ray, t_object *obj, double value[]);
int			hit_cone(t_ray *ray, t_object *obj, double value[]);
double		hit_circle(t_ray *ray, t_object *obj);

t_point		get_n_vector(t_ray *ray, t_point p, \
							t_shape hit_shape, t_object *obj);

t_rec		get_intersection(t_ray *ray, t_object *obj);
t_rec		find_closestobj(t_ray *ray, t_list *objs);

int			is_shadow(t_list *objs, t_light *light, t_point frag_point);

#endif
