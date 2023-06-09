/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaild_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:33:05 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 12:26:42 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

size_t	count_charnum(char c, char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	vaild_filename(char *filename)
{
	size_t	size;

	size = ft_strlen(filename);
	if (!size || count_charnum('.', filename) != 1)
		return (1);
	if (filename[size - 3] != '.' || \
		filename[size - 2] != 'r' || filename[size - 1] != 't')
		return (1);
	return (0);
}

int	vaild_file(int ac, char **av)
{
	if (ac == 1)
		return (parse_error("No arguments.", 1));
	else if (ac != 2)
		return (parse_error("Too many arguments.", 1));
	if (vaild_filename(av[1]))
		return (parse_error("Invaild filename.", 1));
	return (0);
}
