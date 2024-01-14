/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:44 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:14:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

void	parse_ratio(t_line *line, double *ratio)
{
	parse_decimal(line, ratio);
	if (!(0.0 <= *ratio && *ratio <= 1.0))
		parse_error_exit("Ratio in range: [0.0, 1.0].", line->line, 1);
}

void	parse_color(t_line *line, t_color *color)
{
	size_t	size;
	size_t	token;

	line->idx = shift_whitespace(line);
	token = get_token(line);
	size = catchs_in_str(line->line + line->idx, ",");
	color->r = max_color(parse_atoi(line->line, line->idx, size));
	line->idx += size;
	if ((line->line)[line->idx++] != ',')
		parse_error_exit("Invalid form.", line->line, 1);
	size = catchs_in_str(line->line + line->idx, ",");
	color->g = max_color(parse_atoi(line->line, line->idx, size));
	line->idx += size;
	if ((line->line)[line->idx++] != ',')
		parse_error_exit("Invalid form.", line->line, 1);
	size = token - line->idx;
	color->b = max_color(parse_atoi(line->line, line->idx, size));
	line->idx += size;
}

void	parse_coordi(t_line *line, t_point *coodi)
{
	size_t	size;
	size_t	token;

	line->idx = shift_whitespace(line);
	token = get_token(line);
	size = catchs_in_str(line->line + line->idx, ",");
	coodi->x = parse_atof(line->line, line->idx, size);
	line->idx += size;
	if ((line->line)[line->idx++] != ',')
		parse_error_exit("Invalid form.", line->line, 1);
	size = catchs_in_str(line->line + line->idx, ",");
	coodi->y = parse_atof(line->line, line->idx, size);
	line->idx += size;
	if ((line->line)[line->idx++] != ',')
		parse_error_exit("Invalid form.", line->line, 1);
	size = token - line->idx;
	coodi->z = parse_atof(line->line, line->idx, size);
	line->idx += size;
}

void	parse_n_vector(t_line *line, t_point *coodi)
{
	parse_coordi(line, coodi);
	if (!(-1.0 <= coodi->x && coodi->x <= 1.0) || \
		!(-1.0 <= coodi->y && coodi->y <= 1.0) || \
		!(-1.0 <= coodi->z && coodi->z <= 1.0))
		parse_error_exit("Normal Vector In range [-1,1].", line->line, 1);
	else if (coodi->x == 0.0 && \
		coodi->y == 0.0 && coodi->z == 0.0)
		parse_error_exit("Normal vector has no direction.", line->line, 1);
	*coodi = v_unit(*coodi);
}
