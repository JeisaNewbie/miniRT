/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:14:17 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:14:36 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

void	parse_integer(t_line *line, int *integer)
{
	size_t	size;

	line->idx = shift_whitespace(line);
	size = get_token(line) - line->idx;
	*integer = parse_atoi(line->line, line->idx, size);
	line->idx += size;
}

void	parse_decimal(t_line *line, double *decimal)
{
	size_t	size;

	line->idx = shift_whitespace(line);
	size = get_token(line) - line->idx;
	*decimal = parse_atof(line->line, line->idx, size);
	line->idx += size;
}
