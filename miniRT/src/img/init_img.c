/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:27:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 14:16:26 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	init_img(t_data *data)
{
	data->params.mlx = mlx_init ();
	data->params.width = WINDOW_X;
	data->params.height = WINDOW_Y;
	data->params.img = mlx_new_image (data->params.mlx, \
		data->params.width, data->params.height);
	if (data->params.img == NULL)
		return (0);
	data->params.addr = mlx_get_data_addr (data->params.img, \
		&data->params.bits_per_pixel,
			&data->params.line_length, &data->params.endian);
	if (!data->params.addr)
		return (0);
	data->params.win = mlx_new_window (data->params.mlx, \
		data->params.width, data->params.height, "miniRT");
	if (data->params.win == NULL)
		return (0);
	return (1);
}
