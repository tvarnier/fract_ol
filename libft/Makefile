# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 12:33:35 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2019/02/14 21:11:05 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

HEADER = ./includes/libft.h

CHECK = ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c \
		ft_islower.c ft_isprint.c \
		ft_isupper.c ft_tolower.c \
		ft_toupper.c

DATE = 	ft_date.c

LIST = 	ft_lstadd.c ft_lstaddback.c \
		ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_lstraddback.c \
		ft_lstrclr.c ft_lstrnew.c

MATH = 	ft_abs.c ft_pow.c \
		ft_round.c ft_sqrt.c

MEMORY = ft_bzero.c ft_memalloc.c \
		 ft_memccpy.c ft_memchr.c \
		 ft_memcmp.c ft_memcpy.c \
		 ft_memdel.c ft_memmove.c \
		 ft_memset.c

NUMBER = ft_atoi.c ft_ftoa.c \
		 ft_intlen.c ft_itoa.c \
		 ft_ttob.c ft_uintlen.c \
		 ft_uitoa.c

PRINT = ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c \
		ft_putunbr.c

STRING = get_next_line.c ft_strchar.c \
		 ft_strclr.c ft_strdel.c \
		 ft_strinit.c ft_striteri.c \
		 ft_strlen.c ft_strncat.c \
		 ft_strncpy.c ft_strnstr.c \
		 ft_strsplit.c ft_strtrim.c \
		 ft_strbase.c ft_strchar_last.c \
		 ft_strcmp.c ft_strdup.c \
		 ft_strins.c ft_stris.c \
		 ft_strjoin.c \
		 ft_strmap.c ft_strnchr.c \
		 ft_strnequ.c ft_strrchr.c \
		 ft_strstr.c ft_strcat.c \
		 ft_strchr.c ft_strcpy.c \
		 ft_strequ.c ft_striter.c \
		 ft_strlcat.c ft_strmapi.c \
		 ft_strncmp.c ft_strnew.c \
		 ft_strrep.c ft_strsub.c

SRCS = $(CHECK:%.c=check/%.c) $(DATE:%.c=date/%.c)
SRCS += $(LIST:%.c=list/%.c) $(MATH:%.c=math/%.c)
SRCS += $(MEMORY:%.c=memory/%.c) $(NUMBER:%.c=number/%.c)
SRCS += $(PRINT:%.c=print/%.c) $(STRING:%.c=string/%.c)

OBJ_DIR = obj
OBJS = $(CHECK:%.c=$(OBJ_DIR)/%.o) $(DATE:%.c=$(OBJ_DIR)/%.o)
OBJS += $(LIST:%.c=$(OBJ_DIR)/%.o) $(MATH:%.c=$(OBJ_DIR)/%.o)
OBJS += $(MEMORY:%.c=$(OBJ_DIR)/%.o) $(NUMBER:%.c=$(OBJ_DIR)/%.o)
OBJS += $(PRINT:%.c=$(OBJ_DIR)/%.o) $(STRING:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ ar rc $(NAME) $(OBJS)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: */%.c $(HEADER)
	@ $(CC) -I ./includes -o $@ -c $< $(FLAGS)

clean:
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all
