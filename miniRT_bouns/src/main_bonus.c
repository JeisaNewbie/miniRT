/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:47:26 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:16:09 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_file(ac, av, &data))
		return (1);
	init_img(&data);
	print_img (&data);
	mlx_hooks (&data);
	mlx_loop (data.params.mlx);
	free_data(&data);
	return (0);
}
