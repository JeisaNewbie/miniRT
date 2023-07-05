/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/27 15:27:57 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	parse_ratio(char *line, double *ratio)
{
	size_t	idx;

	idx = 0;
	idx = parse_decimal(line, ratio);
	if (!(0.0 <= *ratio && *ratio <= 1.0))
		parse_error_exit("Ratio in range: [0.0, 1.0].", 1);
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
		if (line[idx + size] == ',')
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

int	parse_n_vector(char *line, t_point *coodi)
{
	size_t	idx;

	idx = parse_coordi(line, coodi);
	if (!(-1.0 <= coodi->x && coodi->x <= 1.0) || \
		!(-1.0 <= coodi->y && coodi->y <= 1.0) || \
		!(-1.0 <= coodi->z && coodi->z <= 1.0))
		parse_error_exit("Normal Vector In range [-1,1].", 1);
	else if (coodi->x == 0.0 && \
		coodi->y == 0.0 && coodi->z == 0.0)
		parse_error_exit("Normal vector has no direction.", 1);
	*coodi = v_unit(*coodi);
	return (idx);
}
