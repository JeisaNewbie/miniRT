/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:36:02 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 15:49:56 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

int	is_type(t_line *line)
{
	const char	*types[7] = {"A", "C", "l", "sp", "pl", "cy", "co"};
	size_t		type_idx;
	size_t		size;

	line->idx = shift_whitespace(line);
	size = get_token(line) - line->idx;
	if (is_comment(line, size))
		return (10);
	if (size == 0 || size > 2)
		return (0);
	type_idx = -1;
	while (++type_idx < 7)
	{
		if (!ft_strncmp((line->line) + (line->idx), types[type_idx], size))
		{
			line->idx += size;
			line->type = type_idx + 1;
			return (type_idx + 1);
		}
	}
	line->idx += size;
	return (0);
}

int	catchs_in_str(char *line, char *catchs)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr(catchs, line[i]))
			return (i);
		i++;
	}
	return (i);
}

size_t	shift_whitespace(t_line *line)
{
	size_t	idx;

	idx = line->idx;
	while ((line->line)[idx] && (line->line)[idx] != '\n' && \
		((line->line)[idx] == ' '))
		idx++;
	return (idx);
}

size_t	get_token(t_line *line)
{
	size_t	idx;

	idx = line->idx;
	while ((line->line)[idx] && (line->line)[idx] != '\n' && \
		(line->line)[idx] != ' ')
		idx++;
	return (idx);
}

int	is_comment(t_line *line, size_t token_size)
{
	if (token_size > 0 && (line->line)[line->idx] == '#')
		return (1);
	return (0);
}
