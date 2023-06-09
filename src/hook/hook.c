/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:45:57 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/09 12:58:58 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	mlx_hooks(t_data *data)
{
	mlx_key_hook (data->params.win, &key_hook, data);
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