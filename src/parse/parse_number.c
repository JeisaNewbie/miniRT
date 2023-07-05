/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:14:17 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/13 19:49:07 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_integer(char *line, int *integer)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	size = catchs_in_str(line + idx, " ");
	*integer = parse_atoi(line + idx, size);
	idx += size;
	return (idx);
}

int	parse_decimal(char *line, double *decimal)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	size = catchs_in_str(line + idx, " ");
	*decimal = parse_atof(line + idx, size);
	idx += size;
	return (idx);
}
