/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:25 by jeelee            #+#    #+#             */
/*   Updated: 2023/07/17 20:07:35 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "./types_bonus.h"
# include "./parse_bonus.h"
# include "./v_utils_bonus.h"
# include "./scene_bonus.h"
# include "./ray_bonus.h"
# include "./utils_bonus.h"

# define WINDOW_X 1920;
# define WINDOW_Y 1080;

int	parse_file(int ac, char **av, t_data *data);

#endif
