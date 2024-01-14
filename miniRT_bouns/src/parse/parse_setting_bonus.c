/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:01:47 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 15:49:30 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

static void	vaild_bg(t_line *line, int *parsed)
{
	if (line->type == 1 && parsed[0])
		parse_error_exit("Ambient Can't be two objects.", line->line, 1);
	else if (line->type == 2 && parsed[1])
		parse_error_exit("Camera Can't be two objects.", line->line, 1);
}

static t_light	*new_light(t_line *line)
{
	t_light	*new_light;

	new_light = (t_light *)malloc(sizeof(t_light));
	if (!new_light)
		parse_perror_exit(1);
	ft_memset(new_light, 0, sizeof(t_light));
	parse_coordi(line, &(new_light->point));
	parse_ratio(line, &(new_light->light_ratio));
	parse_color(line, &(new_light->color));
	line->idx = shift_whitespace(line);
	if (!is_comment(line, get_token(line) - line->idx))
	{
		if ((line->line)[line->idx] && (line->line)[line->idx] != '\n')
			parse_error_exit("Invalid file.", line->line, 1);
	}
	return (new_light);
}

static t_object	*new_object(t_line *line)
{
	t_object	*new_object;

	new_object = (t_object *)malloc(sizeof(t_object));
	if (!new_object)
		parse_perror_exit(1);
	ft_memset(new_object, 0, sizeof(t_object));
	new_object->shape = line->type;
	parse_coordi(line, &(new_object->point));
	if (line->type != sphere)
		parse_n_vector(line, &(new_object->n_vector));
	if (line->type == sphere || line->type == cylinder || line->type == cone)
		parse_decimal(line, &(new_object->diameter));
	if (line->type == cylinder || line->type == cone)
		parse_decimal(line, &(new_object->height));
	parse_color(line, &(new_object->color));
	line->idx = shift_whitespace(line);
	if (!is_comment(line, get_token(line) - line->idx))
	{
		if ((line->line)[line->idx] && (line->line)[line->idx] != '\n')
			parse_error_exit("Invalid file.", line->line, 1);
	}
	return (new_object);
}

void	setting_bg(t_line *line, t_data *data, int *parsed)
{
	vaild_bg(line, parsed);
	if (line->type == amb)
	{
		parse_ratio(line, &((data->a_light).light_ratio));
		parse_color(line, &((data->a_light).color));
		parsed[0] = 1;
	}
	else if (line->type == camera)
	{
		parse_coordi(line, &((data->camera).center));
		parse_n_vector(line, &((data->camera).n_vector));
		parse_integer(line, &((data->camera).fov));
		if (!(0 <= (data->camera).fov && (data->camera).fov <= 180))
			parse_error_exit("Invalid FOV.", line->line, 1);
		parsed[1] = 1;
	}
	line->idx = shift_whitespace(line);
	if (!is_comment(line, get_token(line) - line->idx))
	{
		if ((line->line)[line->idx] && (line->line)[line->idx] != '\n')
			parse_error_exit("Invalid file.", line->line, 1);
	}
}

void	setting_object(t_line *line, t_data *data)
{
	t_light		*l;
	t_object	*obj;
	t_list		*new;

	if (line->type == light)
	{
		l = new_light(line);
		new = ft_lstnew(l);
		ft_lstadd_back(&(data->lights), new);
	}
	else
	{
		obj = new_object(line);
		new = ft_lstnew(obj);
		ft_lstadd_back(&(data->objects), new);
	}
}
