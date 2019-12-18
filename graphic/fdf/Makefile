# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2019/01/19 10:33:46 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = fdf
SRCS =	srcs/change.c \
		srcs/compute.c \
		srcs/connect.c \
		srcs/connect_one.c \
		srcs/connect_two.c \
		srcs/filler.c \
		srcs/key.c \
		srcs/launcher.c \
		srcs/main.c \
		srcs/mouse.c \
		srcs/pixel.c \
		srcs/pos.c \
		srcs/print.c \
		srcs/proj_iso.c \
		srcs/proj_oblic.c \
		srcs/read.c \
		srcs/struct.c \
		srcs/zoom.c


OBJ = $(SRCS:.c=.o)

MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) -I includes -o $@ $^ $(LIB) $(MINILIBX) $(FLAGS)

$(LIB):
	make -C libft

%.o: %.c
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re: fclean all
