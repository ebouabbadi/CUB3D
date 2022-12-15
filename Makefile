# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 19:07:01 by ebouabba          #+#    #+#              #
#    Updated: 2022/12/13 19:11:56 by ebouabba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INC = -I$(shell pwd)/include 
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

LFLAGS = -lmlx -framework OpenGL -framework Appkit

RED = \033[0;31m
GREEN = \033[0;32m
NO_COLOR = \033[0m

LIBFT = libft/libft.a
SRC =	drew/drew_wall.c drew/fishblow.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		math_help/color.c math_help/formula.c \
		parsing/check_colors.c parsing/check_map.c parsing/check_texture.c parsing/data_init.c parsing/utils.c\
		parsing/check_extention.c parsing/check_map2.c parsing/collect_infos.c parsing/parsing.c \
		raycasting/raycasting.c        raycasting/raycasting_utils1.c \
		cub3d.c hook_m.c
SRC_LIB =	libft/ft_atoi.c libft/ft_itoa.c libft/ft_lstnew.c libft/ft_putendl_fd.c libft/ft_strjoin.c libft/ft_strtrim.c\
			libft/ft_bzero.c  libft/ft_lstadd_back.c  libft/ft_lstsize.c libft/ft_putnbr_fd.c libft/ft_strlcat.c libft/ft_substr.c\
			libft/ft_calloc.c libft/ft_lstadd_front.c libft/ft_memchr.c libft/ft_putstr_fd.c libft/ft_strlcpy.c libft/ft_tolower.c\
			libft/ft_isalnum.c libft/ft_lstclear.c libft/ft_memcmp.c libft/ft_split.c  libft/ft_strlen.c libft/ft_toupper.c\
			libft/ft_isalpha.c libft/ft_lstdelone.c libft/ft_memcpy.c libft/ft_strchr.c libft/ft_strmapi.c\
			libft/ft_isascii.c libft/ft_lstiter.c libft/ft_memmove.c libft/ft_strcmp.c libft/ft_strncmp.c\
			libft/ft_isdigit.c libft/ft_lstlast.c libft/ft_memset.c libft/ft_strdup.c libft/ft_strnstr.c\
			libft/ft_isprint.c libft/ft_lstmap.c libft/ft_putchar_fd.c   libft/ft_striteri.c  libft/ft_strrchr.c				    

OBJ = $(SRC:.c=.o)

INCLUDE = include/cub3d.h  include/data_struct.h  include/get_next_line.h include/libft.h include/treD_hndlr.h

%.o:%.c $(INCLUDE) $(SRC_LIB)
	@$(CC) $(INC)  $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C  libft bonus
	$(CC) -o $(NAME) $(OBJ) $(INC)  $(CFLAGS) $(LFLAGS) $(LIBFT)

clean :
	@make -C  libft clean
	@rm -rf $(OBJ_DIR) $(OBJ)
	@rm -rf ${LIBFT}
	@echo "${RED} • ALL object files are deleted${NO_COLOR}"

fclean : clean
	@rm -rf ${NAME}
	@echo "${RED} • The executed file is removed${NO_COLOR}"

re : fclean all

.PHONY: fclean clean all re