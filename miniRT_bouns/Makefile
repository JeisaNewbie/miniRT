# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/07/18 16:01:37 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT_bonus

CC			=	CC
CFLAGS		=	-Wall -Wextra -Werror

LIBDIR		=	./libft
LIBFT		=	$(LIBDIR)/libft.a

MLXDIR		=	./mlx
MLX			=	$(MLXDIR)/libmlx.a
LDFLAGS		=	-L./mlx/ -lmlx -framework OpenGL -framework AppKit

SRCDIR		=	./src
PARSEDIR	=	$(SRCDIR)/parse
RAYDIR		=	$(SRCDIR)/ray
UTILSDIR	=	$(SRCDIR)/utils
V_UTILSDIR	=	$(SRCDIR)/v_utils
HOOKDIR		=	$(SRCDIR)/hook
IMGDIR		=	$(SRCDIR)/img
SCENEDIR	=	$(SRCDIR)/scene

INC			=	$(SRCDIR)/include

PARSE		=	parse_file_bonus.c valid_file_bonus.c parse_gnl_bonus.c parse_token_bonus.c parse_setting_bonus.c parse_number_bonus.c parse_trans_bonus.c parse_utils_bonus.c parse_perror_bonus.c
PARSEFIX	=	$(PARSE:%.c=$(PARSEDIR)/%.c)


RAY			=	hit_objects_bonus.c hit_cylinder_bonus.c hit_cone_bonus.c hit_circle_bonus.c get_rec_bonus.c find_closestobj_bonus.c ray_utils_bonus.c phong_bonus.c shadow_bonus.c
RAYFIX		=	$(RAY:%.c=$(RAYDIR)/%.c)

UTILS		=	data_free_bonus.c add_color_bonus.c create_color_bonus.c trans_color_bonus.c ratio_color_bonus.c utils_bonus.c select_closestobj_bonus.c print_obj_bonus.c
UTILSFIX	=	$(UTILS:%.c=$(UTILSDIR)/%.c)

V_UTILS		=	add_and_sub_bonus.c dot_and_cross_bonus.c length_and_unit_bonus.c mul_and_div_bonus.c
V_UTILSFIX	=	$(V_UTILS:%.c=$(V_UTILSDIR)/%.c)

HOOK		=	hook_bonus.c
HOOKFIX		=	$(HOOK:%.c=$(HOOKDIR)/%.c)

IMG			=	init_img_bonus.c print_img_bonus.c
IMGFIX		=	$(IMG:%.c=$(IMGDIR)/%.c)

SCENE		=	scene_bonus.c
SCENEFIX	=	$(SCENE:%.c=$(SCENEDIR)/%.c)

SRC			=	$(SRCDIR)/main_bonus.c $(PARSEFIX) $(UTILSFIX) $(V_UTILSFIX) $(HOOKFIX) $(IMGFIX) $(SCENEFIX) $(RAYFIX)

OBJ			=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ) $(LIBFT) $(MLX)
	$(CC) $(LIBFT) $(MLX) $(LDFLAGS) $(OBJ) -o $@

%.o			:	%.c
	$(CC) $(CFLAGS) -I$(INC) -c $? -o $@

$(LIBFT)	:
	make bonus -C $(LIBDIR)

$(MLX)		:
	make -C $(MLXDIR)

all			:
	@$(MAKE) -j6 $(NAME)

clean		:
	@make -C $(LIBDIR) clean
	@make -C $(MLXDIR) clean
	@rm -f $(OBJ)

fclean		:	clean
	@rm -f $(NAME) $(LIBFT) $(MLX)

re			:
	@make fclean
	@make all

.PHONY		:	all clean fclean re
