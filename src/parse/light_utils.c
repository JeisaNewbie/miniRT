/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:18:59 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 01:31:59 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_light	**create_llist(int n)
{
	t_light	**llist;

	llist = (t_light **)malloc(sizeof(t_light *) * ((ARR_SIZE * n) + 1));
	if (!llist)
		parse_perror_exit(1);
	ft_memset(llist, 0, sizeof(t_light *) * ((ARR_SIZE * n) + 1));
	return (llist);
}

static void	resize_llist(t_light ***llist)
{
	t_light	**new_llist;
	size_t	idx;
	size_t	size;

	size = 0;
	while ((*llist)[size])
		size++;
	new_llist = create_llist(size / ARR_SIZE + 1);
	idx = 0;
	while (idx < size)
	{
		new_llist[idx] = (*llist)[idx];
		idx++;
	}
	free(*llist);
	*llist = new_llist;
}

void	add_llist(t_light *l, t_light ***llist)
{
	size_t	idx;

	if (!(*llist))
		*llist = create_llist(1);
	idx = 0;
	while ((*llist)[idx])
		idx++;
	if (!(idx % ARR_SIZE))
		resize_llist(llist);
	(*llist)[idx] = l;
}
