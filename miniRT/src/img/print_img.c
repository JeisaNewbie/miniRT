/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:32:47 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/11 16:26:36 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	print_status(int i, int h)
{
	if (i + 1 != h)
		printf(ANSI_DEL);
	printf("Rendering .. [%.2f%%]\n", ((((h - (float)i) / h) * 100)));
}

void	print_img(t_data *data)
{
	uint32_t	color;
	t_rec		rec;
	int			i;
	int			j;

	set_cposition(data, (double)data->params.width / data->params.height);
	i = data->params.height - 1;
	color = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < data->params.width)
		{
			init_dir(&data->camera, (double)j / (data->params.width - 1),
				(double)i / (data->params.height - 1));
			rec = get_rec(data);
			color = get_color (data, &rec);
			my_mlx_pixel_put (data, j, i, color);
			j++;
		}
		i--;
		print_status(i + 1, data->params.height);
	}
	mlx_put_image_to_window(data->params.mlx,
		data->params.win, data->params.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->params.addr + (y * data->params.line_length + x
			* (data->params.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
