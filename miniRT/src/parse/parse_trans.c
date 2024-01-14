/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_trans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:07:48 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/10 16:33:10 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	_atof_decimal(char *str, size_t idx, size_t size, double *n)
{
	size_t	i;

	i = 0;
	if (str[idx + i] != '.')
		parse_error_exit("Invalid number.", str, 1);
	i++;
	while (i < size && str[idx + i])
	{
		if (!('0' <= str[idx + i] && str[idx + i] <= '9'))
			parse_error_exit("Invalid number.", str, 1);
		*n += (str[idx + i] - '0') * pow(0.1, i);
		if (*n > MAXFLOAT)
			parse_error_exit("Too big number.", str, 1);
		else if (*n < -MAXFLOAT)
			parse_error_exit("Too small number.", str, 1);
		i++;
	}
}

float	parse_atof(char *str, size_t idx, size_t size)
{
	size_t	i;
	double	n;
	int		m;

	n = 0;
	m = 1;
	i = 0;
	if (str[idx + i] == '-')
	{
		m *= -1;
		i++;
	}
	while (i < size && ('0' <= str[idx + i] && str[idx + i] <= '9'))
		n = (n * 10) + (str[idx + i++] - '0');
	if (i < size)
		_atof_decimal(str, idx + i, size - i, &n);
	return ((float)n * (float)m);
}

int	parse_atoi(char *str, size_t idx, size_t size)
{
	long long	n;
	int			m;
	size_t		i;

	n = 0;
	m = 1;
	i = 0;
	if (str[idx + i] == '-')
	{
		m *= -1;
		i++;
	}
	while (i < size && str[idx + i])
	{
		if (!('0' <= str[idx + i] && str[idx + i] <= '9'))
			parse_error_exit("Invalid number.", str, 1);
		n = (n * 10) + (str[idx + i] - '0');
		if (n > 2147483647)
			parse_error_exit("Too big number.", str, 1);
		else if (n < -2147483648)
			parse_error_exit("Too small number.", str, 1);
		i++;
	}
	return ((int)n * m);
}
