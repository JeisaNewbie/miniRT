/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:20:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 15:51:04 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

static void	print_point(t_point *point)
{
	printf("[ %f, %f, %f ]", point->x, point->y, point->z);
}

static void	print_color(t_color *color)
{
	printf("[ %d, %d, %d ]", color->r, color->g, color->b);
}

static void	print_shape(t_shape shape)
{
	if (shape == amb)
		printf("[ amb ]");
	else if (shape == camera)
		printf("[ camera ]");
	else if (shape == light)
		printf("[ light ]");
	else if (shape == sphere)
		printf("[ sphere ]");
	else if (shape == plane)
		printf("[ plane ]");
	else if (shape == cylinder)
		printf("[ cylinder ]");
	else if (shape == cone)
		printf("[ cone ]");
	else if (shape == circle)
		printf("[ circle ]");
	else
		printf("[ nothing ]");
}

void	print_obj(t_object *obj)
{
	printf(ANSI_YEL "Type: " ANSI_CYA);
	print_shape(obj->shape);
	printf(ANSI_YEL "\nPoint: " ANSI_CYA);
	print_point(&(obj->point));
	printf(ANSI_YEL "\nn_vector: " ANSI_CYA);
	print_point(&(obj->n_vector));
	printf(ANSI_YEL "\ndiameter: " ANSI_CYA);
	printf("[ %lf ]", obj->diameter);
	printf(ANSI_YEL "\nheight: " ANSI_CYA);
	printf("[ %lf ]", obj->height);
	printf(ANSI_YEL "\ncolor: " ANSI_CYA);
	print_color(&(obj->color));
	printf("\n" ANSI_RES);
}
