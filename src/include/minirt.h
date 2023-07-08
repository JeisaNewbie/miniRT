/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/05 21:56:41 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./types.h"
# include "./parse.h"
# include "./v_utils.h"
# include "./scene.h"
# include "./ray.h"
# include "./utils.h"

# define WINDOW_X 1920;
# define WINDOW_Y 1080;

int	parse_file(int ac, char **av, t_data *data);

#endif
