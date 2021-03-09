# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2019/03/11 04:00:55 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

CC = gcc

MINILIB = minilibx_macos/libmlx.a
MINILIBX = -L minilibx_macos/ -lpthread -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

HEADER = ./includes/fractol.h

SRC =	main.c \
		launch.c \
		key.c \
		mouse.c \
		leave.c \
		line.c \
		compute.c \
		julia.c \
		mandelbrot.c \
		burningship.c \
		pythagoras.c \
		barnsley.c

SRC_DIR = srcs
SRCS = $(SRC:%.c=$(SRC_DIR)/%.c)

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MINILIB) $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -I includes -o $@ $(OBJ) $(LIB) $(MINILIBX) $(FLAGS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MINILIB):
	make -C minilibx_macos

$(LIB):
	make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C minilibx_macos clean
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(MINILIB)
	rm -rf $(NAME)

re: fclean all
