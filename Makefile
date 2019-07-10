# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:25:30 by darbib            #+#    #+#              #
#    Updated: 2019/07/08 17:10:11 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
EXE := fdf
HDIR := include
LIBFT := libft
HLIBFT := $(LIBFT)/include
MLX := minilibx_macos
LIBS := $(LIBFT)/libft.a 

CFLAGS_MACOS := -I $(HDIR) \
			   	-I $(MLX) \
			   	-I $(HLIBFT) \
				-c -Wall -Werror -Wextra
LFLAGS := -o $(EXE) -Wall -Werror -Wextra
FMW := 	-lmlx -L $(MLX) \
		-framework OpenGL \
		-framework AppKit \

SRC := fdf.c hook.c parsing.c toolbox.c error.c 
OBJ := $(SRC:.c=.o)

# **************************************************************************** #

.PHONY: all clean fclean re

all : makelib $(EXE) 
	@echo 'Linking successful, ready to run'

$(EXE): $(LIBS) $(OBJ)
	@echo '✔'
	@echo 'Compiling successful'
	@$(CC) $(LFLAGS) $(OBJ) $(LIBS) $(FMW)

%.o: %.c
	@$(CC) $(CFLAGS_MACOS) $^
	@echo -n '.'

makelib :
	@make -C libft

clean:
	@rm -f $(OBJ)
	@echo "Fdf objects deleted"

fclean : clean
	@rm -f $(EXE)
	@make -C libft fclean 
	@echo 'Fdf deleted'

re : fclean all

