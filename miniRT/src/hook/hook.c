/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:45:57 by ahkiler           #+#    #+#             */
/*   Updated: 2023/07/17 14:18:23 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode != 1)
		return (0);
	if (x >= 0 && y >= 0)
		select_closestobj(x, y, data);
	return (0);
}

void	mlx_hooks(t_data *data)
{
	mlx_hook (data->params.win, MOUSEDOWN, 0, &mouse_hook, data);
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
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window (data->params.mlx, data->params.win);
	exit (0);
	return (0);
}
