# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/07/17 19:41:57 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

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

PARSE		=	parse_file.c valid_file.c parse_gnl.c parse_token.c parse_setting.c parse_number.c parse_trans.c parse_utils.c parse_perror.c
PARSEFIX	=	$(PARSE:%.c=$(PARSEDIR)/%.c)


RAY			=	hit_objects.c hit_cylinder.c hit_circle.c get_rec.c find_closestobj.c ray_utils.c phong.c shadow.c
RAYFIX		=	$(RAY:%.c=$(RAYDIR)/%.c)

UTILS		=	data_free.c add_color.c create_color.c trans_color.c ratio_color.c utils.c select_closestobj.c print_obj.c
UTILSFIX	=	$(UTILS:%.c=$(UTILSDIR)/%.c)

V_UTILS		=	add_and_sub.c dot_and_cross.c length_and_unit.c mul_and_div.c
V_UTILSFIX	=	$(V_UTILS:%.c=$(V_UTILSDIR)/%.c)

HOOK		=	hook.c
HOOKFIX		=	$(HOOK:%.c=$(HOOKDIR)/%.c)

IMG			=	init_img.c print_img.c
IMGFIX		=	$(IMG:%.c=$(IMGDIR)/%.c)

SCENE		=	scene.c
SCENEFIX	=	$(SCENE:%.c=$(SCENEDIR)/%.c)

SRC			=	$(SRCDIR)/main.c $(PARSEFIX) $(UTILSFIX) $(V_UTILSFIX) $(HOOKFIX) $(IMGFIX) $(SCENEFIX) $(RAYFIX)

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
