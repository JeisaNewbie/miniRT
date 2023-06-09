/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 23:18:48 by jeelee           ###   ########.fr       */
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

int	parse_decimal(char *line, float *decimal)
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

int	parse_color(char *line, uint32_t *color)
{
	size_t	idx;
	size_t	size;
	size_t	i;
	int		tmp;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	i = 0;
	while (++i < 4)
	{
		size = catchs_in_str(line + idx, ",");
		tmp = parse_atoi(line + idx, size);
		if (!(0 <= tmp && tmp <= 255))
			parse_error_exit("Invalid color.", 1);
		idx++;
		*color |= (tmp << (8 * (3 - i)));
		idx += size;
	}
	return (idx);
}

int	parse_coordi(char *line, t_point *coodi)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	size = catchs_in_str(line + idx, ",");
	coodi->x = parse_atof(line + idx, size);
	idx += size;
	if (line[idx] != ',')
		parse_error_exit("Invalid form.", 1);
	idx++;
	size = catchs_in_str(line + idx, ",");
	coodi->y = parse_atof(line + idx, size);
	idx += size;
	if (line[idx] != ',')
		parse_error_exit("Invalid form.", 1);
	idx++;
	size = catchs_in_str(line + idx, ", ");
	coodi->z = parse_atof(line + idx, size);
	idx += size;
	return (idx);
}
