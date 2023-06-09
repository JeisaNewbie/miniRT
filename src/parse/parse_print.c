/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:15:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 01:59:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 지울 파일입니다.
#include "../include/minirt.h"

static void	print_point(t_point *point)
{
	printf("[ %f, %f, %f ]", point->x, point->y, point->z);
}

static void	print_lights(t_light **llist)
{
	size_t	idx;

	if (!llist)
	{
		printf("lights: (NULL)\n");
		return ;
	}
	idx = 0;
	while (llist[idx])
	{
		printf("light[%zu]\t| point: ", idx);
		print_point(&(llist[idx]->point));
		printf(", ratio: [ %f ], color: [ %d ]\n", llist[idx]->light_ratio, llist[idx]->color);
		idx++;
	}
}

static void	print_objects(t_object **objlist)
{
	size_t	idx;

	if (!objlist)
	{
		printf("objects: (NULL)\n");
		return ;
	}
	idx = 0;
	while (objlist[idx])
	{
		printf("object[%zu]\t| shape: %d, point: ", idx, objlist[idx]->shape);
		print_point(&(objlist[idx]->point));
		printf(", n_vector: ");
		print_point(&(objlist[idx]->n_vector));
		printf(", diameter: [ %f ], height: [ %f ], color: [ %d ]\n", objlist[idx]->diameter, objlist[idx]->height, objlist[idx]->color);
		idx++;
	}
}

void	print_data(t_data *data)
{
	printf("------------------------------------[data]------------------------------------\n");
	printf("Ambient\t\t| ratio: [ %f ], color: [ %d ]\n", data->a_light.light_ratio, data->a_light.color);
	printf("camera\t\t| point: ");
	print_point(&(data->camera.point));
	printf(", n_vector: ");
	print_point(&(data->camera.n_vector));
	printf(", FOV: %d\n", data->camera.fov);
	print_lights(data->lights);
	print_objects(data->objects);
	printf("------------------------------------------------------------------------------\n");
}
