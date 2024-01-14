/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:14:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/12 02:44:00 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "./types.h"

# define BUFFER_SIZE 100

# define ANSI_RES "\e[0m"
# define ANSI_BOL "\e[1m"
# define ANSI_ITA "\e[3m"
# define ANSI_BLC "\e[30m"
# define ANSI_RED "\e[31m"
# define ANSI_GRE "\e[32m"
# define ANSI_YEL "\e[33m"
# define ANSI_BLU "\e[34m"
# define ANSI_MAG "\e[35m"
# define ANSI_CYA "\e[36m"

# define ANSI_DEL "\e[A\e[2K"

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	ssize_t	rd_size;
	size_t	idx;
}	t_buffer;

typedef struct s_line
{
	t_shape	type;
	char	*line;
	size_t	idx;
}	t_line;

int		valid_file(int ac, char **av);

void	setting_bg(t_line *line, t_data *data, int *parsed);
void	setting_object(t_line *line, t_data *data);

void	parse_ratio(t_line *line, double *ratio);
void	parse_color(t_line *line, t_color *color);
void	parse_coordi(t_line *line, t_point *coodi);
void	parse_n_vector(t_line *line, t_point *coodi);
void	parse_decimal(t_line *line, double *decimal);
void	parse_integer(t_line *line, int *integer);

int		parse_atoi(char *str, size_t idx, size_t size);
float	parse_atof(char *str, size_t idx, size_t size);

int		is_type(t_line *line);
int		catchs_in_str(char *line, char *catchs);
size_t	shift_whitespace(t_line *line);
size_t	get_token(t_line *line);
int		is_comment(t_line *line, size_t token_size);

char	*parse_gnl(int fd, t_buffer *bf);

int		parse_error(char *msg, int _ret);
void	parse_perror_exit(int _exitcode);
void	parse_error_exit(char *msg, char *line, int _exitcode);

void	print_data(t_data *data);

#endif
