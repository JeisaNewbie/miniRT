/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:56:04 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/12 03:08:15 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->lights)
			ft_lstclear(&(data->lights), free);
		if (data->objects)
			ft_lstclear(&(data->objects), free);
	}
}
