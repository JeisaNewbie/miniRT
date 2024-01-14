/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:22:57 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/18 16:33:30 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	print_help_type(int type)
{
	if (type == amb)
		printf(ANSI_GRE "A\t[ratio_range]\t[color]" ANSI_RES "\n");
	else if (type == camera)
		printf(ANSI_GRE "C\t[point]\t[n_vector]\t[FOV]" ANSI_RES "\n");
	else if (type == light)
		printf(ANSI_GRE "L\t[point]\t[ratio_range]" ANSI_RES "\n");
	else if (type == sphere)
		printf(ANSI_GRE "sp\t[point]\t[diameter]\t[color]" ANSI_RES "\n");
	else if (type == plane)
		printf(ANSI_GRE "pl\t[point]\t[n_vector]\t[color]" ANSI_RES "\n");
	else if (type == cylinder)
		printf(ANSI_GRE \
			"cy\t[point]\t[n_vector]\t[diameter]\t[height]\t[color]" ANSI_RES "\n");
}

void	parse_perror_exit(int _exitcode)
{
	perror(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES ANSI_RED);
	printf(ANSI_RES);
	exit(_exitcode);
}

void	parse_error_exit(char *msg, char *line, int _exitcode)
{
	t_line	l;

	printf(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES);
	printf(ANSI_RED "%s" ANSI_RES "\n", msg);
	if (line)
	{
		printf(ANSI_BOL ANSI_YEL "LINE: " ANSI_RES);
		printf(ANSI_CYA "%s" ANSI_RES "\n", line);
		l.line = line;
		l.idx = 0;
		l.type = 0;
		is_type(&l);
		print_help_type(l.type);
	}
	exit(_exitcode);
}

int	parse_error(char *msg, int _ret)
{
	printf(ANSI_BOL ANSI_BLU "miniRT: " ANSI_RES);
	printf(ANSI_RED "%s" ANSI_RES "\n", msg);
	return (_ret);
}
