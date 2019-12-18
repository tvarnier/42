# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2018/10/16 20:33:48 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

C = gcc

NAME = fillit

SRCS =	srcs/ft_func1.c \
		srcs/ft_func2.c \
		srcs/ft_jacquie.c \
		srcs/ft_func3.c \
		srcs/ft_res_fct.c \
		srcs/ft_michel.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -I includes -o $@ $^ libft/libft.a $(FLAGS)

%.o: %.c
	make -C libft/ clean
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft/ fclean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
