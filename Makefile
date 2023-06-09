# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:47:17 by jeelee            #+#    #+#              #
#    Updated: 2023/06/09 01:29:17 by jeelee           ###   ########.fr        #
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
UTILSDIR	=	$(SRCDIR)/utils

INC			=	$(SRCDIR)/include

PARSE		=	parse_file.c vaild_file.c parse_gnl.c parse_token.c parse_setting.c light_utils.c parse_utils.c parse_perror.c parse_print.c
PARSEFIX	=	$(PARSE:%.c=$(PARSEDIR)/%.c)

UTILS		=	object_utils.c
UTILSFIX	=	$(UTILS:%.c=$(UTILSDIR)/%.c)

SRC			=	$(SRCDIR)/main.c $(PARSEFIX) $(UTILSFIX)

OBJ			=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ) $(LIBFT) $(MLX)
	$(CC) $(LIBFT) $(MLX) $(LDFLAGS) $(OBJ) -o $@

%.o			:	%.c
	$(CC) $(CFLAGS) -I$(INC) -c $? -o $@

$(LIBFT)	:
	make -C $(LIBDIR)

$(MLX)		:
	make -C $(MLXDIR)

all			:	$(NAME)

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
