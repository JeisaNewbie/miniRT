/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:01:47 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/28 16:57:33 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	vaild_bg(int type, int *parsed)
{
	if (type == 1 && parsed[0])
		parse_error_exit("Ambient Can't be two objects.", 1);
	else if (type == 2 && parsed[1])
		parse_error_exit("Camera Can't be two objects.", 1);
}

static t_light	*new_light(char *line)
{
	t_light	*new_light;
	size_t	idx;

	new_light = (t_light *)malloc(sizeof(t_light));
	if (!new_light)
		parse_perror_exit(1);
	ft_memset(new_light, 0, sizeof(t_light));
	idx = 0;
	idx += parse_coordi(line, &(new_light->point));
	idx += parse_ratio(line + idx, &(new_light->light_ratio));
	idx += parse_color(line + idx, &(new_light->color));
	return (new_light);
}

static t_object	*new_object(int type, char *line)
{
	t_object	*new_object;
	size_t		idx;

	new_object = (t_object *)malloc(sizeof(t_object));
	if (!new_object)
		parse_perror_exit(1);
	ft_memset(new_object, 0, sizeof(t_object));
	idx = 0;
	new_object->shape = type;
	idx += parse_coordi(line, &(new_object->point));
	if (type != sphere)
		idx += parse_n_vector(line + idx, &(new_object->n_vector));
	if (type == sphere || type == cylinder || type == cone)
		idx += parse_decimal(line + idx, &(new_object->diameter));
	if (type == cylinder || type == cone)
		idx += parse_decimal(line + idx, &(new_object->height));
	idx += parse_color(line + idx, &(new_object->color));
	return (new_object);
}

void	setting_bg(int type, char *line, t_data *data, int *parsed)
{
	size_t	idx;

	vaild_bg(type, parsed);
	idx = 0;
	if (type == 1)
	{
		idx += parse_ratio(line, &((data->a_light).light_ratio));
		idx += parse_color(line + idx, &((data->a_light).color));
		parsed[0] = 1;
	}
	else if (type == 2)
	{
		idx += parse_coordi(line, &((data->camera).center));
		idx += parse_n_vector(line + idx, &((data->camera).n_vector));
		idx += parse_integer(line + idx, &((data->camera).fov));
		if (!(0 <= (data->camera).fov && (data->camera).fov <= 180))
			parse_error_exit("Invalid FOV.", 1);
		parsed[1] = 1;
	}
	while (line[idx] == ' ')
		idx++;
	if (line[idx] && line[idx] != '\n')
		parse_error_exit("Invalid file.", 1);
}

void	setting_object(int type, char *line, t_data *data)
{
	t_light		*l;
	t_object	*obj;

	if (type == 3)
	{
		l = new_light(line);
		add_llist(l, &(data->lights));
	}
	else
	{
		obj = new_object(type, line);
		add_objlist(obj, &(data->objects));
	}
}
