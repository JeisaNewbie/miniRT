# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/07/05 16:43:32 by jhwang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	CC
#CFLAGS		=	-Wall -Wextra -Werror

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

PARSE		=	parse_file.c valid_file.c parse_gnl.c parse_token.c parse_setting.c light_utils.c parse_number.c parse_utils.c parse_perror.c parse_print.c
PARSEFIX	=	$(PARSE:%.c=$(PARSEDIR)/%.c)

RAY			=	hit_objects.c hit_cylinder.c hit_cone.c hit_circle.c create_trgb.c ray_utils.c
RAYFIX		=	$(RAY:%.c=$(RAYDIR)/%.c)

UTILS		=	object_utils.c data_free.c
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
	make -C $(LIBDIR)

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
