/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:14:41 by jeelee            #+#    #+#             */
/*   Updated: 2023/06/09 01:53:43 by jeelee           ###   ########.fr       */
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

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	ssize_t	rd_size;
	size_t	idx;
}	t_buffer;

int		vaild_file(int ac, char **av);

void	setting_bg(int type, char *line, t_data *data);
void	setting_object(int type, char *line, t_data *data);

t_light	**create_llist(int n);
void	add_llist(t_light *l, t_light ***llist);

int		parse_color(char *line, uint32_t *color);
int		parse_coordi(char *line, t_point *coodi);
int		parse_decimal(char *line, float *decimal);
int		parse_integer(char *line, int *integer);

int		parse_atoi(char *str, size_t size);
float	parse_atof(char *str, size_t size);
int		catchs_in_str(char *line, char *catchs);
char	*parse_gnl(int fd, t_buffer *bf);

int		parse_error(char *msg, int _ret);
void	parse_perror_exit(int _exitcode);
void	parse_error_exit(char *msg, int _exitcode);

void	print_data(t_data *data);

#endif
