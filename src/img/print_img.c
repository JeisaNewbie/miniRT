/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:32:47 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 12:58:47 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	print_img(t_data *data)
{
	u_int32_t	color;
	int			i;
	int			j;

	init_img (data);
	i = 0;
	while (i < data->params.width)
	{
		j = 0;
		while (j < data->params.height)
		{
			color = 0X00112233;
			my_mlx_pixel_put (data, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window (data->params.mlx, data->params.win, data->params.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->params.addr + (y * data->params.line_length + x
			* (data->params.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}