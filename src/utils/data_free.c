/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:56:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 02:04:02 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	free_lights(t_light **lights)
{
	size_t	idx;

	idx = 0;
	while (lights[idx])
	{
		free(lights[idx]);
		idx++;
	}
	free(lights);
}

static void	free_objects(t_object **objects)
{
	size_t	idx;

	idx = 0;
	while (objects[idx])
	{
		free(objects[idx]);
		idx++;
	}
	free(objects);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->lights)
			free_lights(data->lights);
		if (data->objects)
			free_objects(data->objects);
	}
}
