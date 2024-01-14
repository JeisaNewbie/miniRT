/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:33:05 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:14:50 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

void	print_help(void)
{
	printf(ANSI_BLU "[miniRT]: " ANSI_YEL \
		"./miniRT <filename>.rt" ANSI_RES "\n");
	printf("\n----------------[ file.rt form ]----------------\n");
	printf("| " ANSI_GRE "A\t[ratio_range]\t[color]" ANSI_RES "\n");
	printf("| " ANSI_GRE "C\t[point]\t\t[n_vector]\t[FOV]" ANSI_RES "\n");
	printf("| " ANSI_GRE "L\t[point]\t\t[ratio_range]\t[color]" ANSI_RES "\n");
	printf("| " ANSI_GRE "sp\t[point]\t\t[diameter]\t[color]" ANSI_RES "\n");
	printf("| " ANSI_GRE "pl\t[point]\t\t[n_vector]\t[color]" ANSI_RES "\n");
	printf("| " ANSI_GRE \
		"cy\t[point]\t\t[n_vector]\t[diameter]\t[height]\t[color]" ANSI_RES "\n");
	printf("| " ANSI_GRE \
		"co\t[point]\t\t[n_vector]\t[diameter]\t[height]\t[color]" ANSI_RES "\n");
	printf("------------------------------------------------\n");
	exit(0);
}

int	valid_filename(char *filename)
{
	size_t	size;

	size = ft_strlen(filename);
	if (size < 4)
	{
		if (!ft_strncmp(filename, "help", size))
			print_help();
		return (1);
	}
	if (filename[size - 3] != '.' || \
		filename[size - 2] != 'r' || filename[size - 1] != 't')
		return (1);
	return (0);
}

int	valid_file(int ac, char **av)
{
	if (ac == 1)
		return (parse_error("No arguments.", 1));
	else if (ac != 2)
		return (parse_error("Too many arguments.", 1));
	if (valid_filename(av[1]))
		return (parse_error("Invalid filename.", 1));
	return (0);
}
