/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:53:29 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 01:32:37 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_object	**create_objlist(int n)
{
	t_object	**objlist;

	objlist = (t_object **)malloc(sizeof(t_object *) * ((ARR_SIZE * n) + 1));
	if (!objlist)
		parse_perror_exit(1);
	ft_memset(objlist, 0, sizeof(t_object *) * ((ARR_SIZE * n) + 1));
	return (objlist);
}

static void	resize_objlist(t_object ***objlist)
{
	t_object	**new_objlist;
	size_t		idx;
	size_t		size;

	size = 0;
	while ((*objlist)[size])
		size++;
	new_objlist = create_objlist(size / ARR_SIZE + 1);
	idx = 0;
	while (idx < size)
	{
		new_objlist[idx] = (*objlist)[idx];
		idx++;
	}
	free(*objlist);
	*objlist = new_objlist;
}

void	add_objlist(t_object *obj, t_object ***objlist)
{
	size_t	idx;

	if (!(*objlist))
		*objlist = create_objlist(1);
	idx = 0;
	while ((*objlist)[idx])
		idx++;
	if (!(idx % ARR_SIZE))
		resize_objlist(objlist);
	(*objlist)[idx] = obj;
}
