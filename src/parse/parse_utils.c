/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:36:02 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/07 23:49:54 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static double	_atof_decimal(char *str, size_t size)
{
	double	n;
	size_t	i;

	n = 0;
	i = 0;
	if (str[i] != '.')
		parse_error_exit("Invalid number.", 1);
	i++;
	while (i < size && str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			parse_error_exit("Invalid number.", 1);
		n += (str[i] - '0') * pow(0.1, i);
		i++;
	}
	return (n);
}

float	parse_atof(char *str, size_t size)
{
	size_t	i;
	double	n;
	int		m;

	n = 0;
	m = 1;
	i = 0;
	if (str[i] == '-')
	{
		m *= -1;
		i++;
	}
	while (i < size && ('0' <= str[i] && str[i] <= '9'))
		n = (n * 10) + (str[i++] - '0');
	if (i < size)
		n += _atof_decimal(str + i, size - i);
	return ((float)n * (float)m);
}

int	parse_atoi(char *str, size_t size)
{
	long long	n;
	int			m;
	size_t		i;

	n = 0;
	m = 1;
	i = 0;
	if (str[i] == '-')
	{
		m *= -1;
		i++;
	}
	while (i < size && str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			parse_error_exit("Invalid number.", 1);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (n > 2147483647)
		parse_error_exit("Too big number.", 1);
	if (n < -2147483648)
		parse_error_exit("Too small number.", 1);
	return ((int)n * m);
}

int	catchs_in_str(char *line, char *catchs)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(catchs, line[i]))
			return (i);
		i++;
	}
	return (i);
}
