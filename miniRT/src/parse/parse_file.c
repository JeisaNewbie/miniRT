/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:58:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/11 14:58:55 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	valid_line(t_line *line)
{
	line->idx = 0;
	if (!(line->line))
		return (1);
	line->idx = shift_whitespace(line);
	if (!((line->line)[line->idx]))
	{
		free(line->line);
		return (1);
	}
	if ((line->line)[line->idx] == '\n')
	{
		free(line->line);
		line->line = 0;
	}
	return (0);
}

static void	parse_line(t_line *line, t_data *data, int *parsed)
{
	int		type;

	line->idx = shift_whitespace(line);
	type = is_type(line);
	if (type == 0)
		parse_error_exit("Invalid identifier.", line->line, 1);
	else if (type < 3)
		setting_bg(line, data, parsed);
	else if (type < 8)
		setting_object(line, data);
}

static void	_parsing(int fd, t_data *data)
{
	t_line		line;
	int			parsed[2];
	t_buffer	bf;

	parsed[0] = 0;
	parsed[1] = 0;
	ft_memset(&bf, 0, sizeof(t_buffer));
	ft_memset(&line, 0, sizeof(t_line));
	while (1)
	{
		line.line = parse_gnl(fd, &bf);
		if (valid_line(&line))
			break ;
		if (line.line)
		{
			parse_line(&line, data, parsed);
			free(line.line);
		}
	}
}

int	parse_file(int ac, char **av, t_data *data)
{
	int	fd;

	if (valid_file(ac, av))
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		parse_perror_exit(1);
	_parsing(fd, data);
	close(fd);
	return (0);
}
