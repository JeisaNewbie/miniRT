/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:45:57 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/28 13:23:52 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	mlx_hooks(t_data *data)
{
	mlx_hook (data->params.win, KEY_PRESS, 0, &key_hook, data);
	mlx_hook (data->params.win, CLOSE_WIN, 0, &close_win, data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window (data->params.mlx, data->params.win);
		exit (0);
	}
	if (keycode == UP)
		data->camera.center.y += 5;
	if (keycode == DOWN)
		data->camera.center.y -= 5;
	if (keycode == RIGHT)
		data->camera.center.x += 5;
	if (keycode == LEFT)
		data->camera.center.x -= 5;
	print_img (data);
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window (data->params.mlx, data->params.win);
	exit (0);
	return (0);
}
