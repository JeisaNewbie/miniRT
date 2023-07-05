/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:21:14 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/11 17:12:39 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static size_t	get_size_line(t_buffer *bf)
{
	size_t	size;

	size = 0;
	while (bf->idx + size < (size_t)bf->rd_size && \
							(bf->buffer)[bf->idx + size] != '\n')
		size++;
	if ((bf->buffer)[bf->idx + size] == '\n')
		size++;
	return (size);
}

static void	_joining(char **line, t_buffer *bf)
{
	char	*new_line;
	size_t	line_size;
	size_t	size;
	size_t	i;

	if (*line)
		line_size = ft_strlen(*line);
	else
		line_size = 0;
	size = get_size_line(bf);
	new_line = (char *)malloc(sizeof(char) * (line_size + size + 1));
	if (!new_line)
		parse_perror_exit(1);
	if (line_size)
		ft_strlcpy(new_line, *line, line_size + 1);
	i = -1;
	while (++i < size)
		new_line[line_size + i] = (bf->buffer)[bf->idx++];
	new_line[line_size + i] = 0;
	if (*line)
		free(*line);
	*line = new_line;
}

char	*parse_gnl(int fd, t_buffer *bf)
{
	char	*line;

	line = 0;
	while (1)
	{
		if (bf->idx == 0 || \
			(!(bf->rd_size < 0) && bf->idx == (size_t)bf->rd_size))
		{
			bf->rd_size = read(fd, bf->buffer, BUFFER_SIZE);
			bf->idx = 0;
			if (bf->rd_size < 0)
				break ;
		}
		_joining(&line, bf);
		if ((bf->buffer)[bf->idx - 1] == '\n' || \
			bf->rd_size < BUFFER_SIZE)
			break ;
	}
	return (line);
}
