# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 07:11:37 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME_FILLER = tvarnier.filler
SRCS =	srcs/main.c \
		srcs/ft_struct.c \
		srcs/ft_init_tray.c \
		srcs/ft_can_place.c \
		srcs/ft_solver.c \
		srcs/ft_change_tray.c
OBJ = $(SRCS:.c=.o)

NAME_VM = tvarnier.vm
SRCS_VM =	vm/main.c \
		 	vm/ft_struct.c \
			vm/ft_init_tray.c \
			vm/ft_print_players.c \
			vm/ft_print_tab.c \
			vm/ft_print_winner.c \
			vm/ft_print_other.c
OBJ_VM = $(SRCS_VM:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME_FILLER) $(NAME_VM)

$(NAME_FILLER): $(LIB) $(OBJ)
	$(CC) -I includes -o $@ $^ $(LIB) $(FLAGS)

$(LIB):
	make -C libft

$(NAME_VM): $(OBJ_VM)
	$(CC) -I includes -o $@ $^ $(LIB) $(FLAGS)

%.o: %.c
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_VM)

fclean: clean
	rm -rf $(NAME_FILLER)
	rm -rf $(NAME_VM)
	rm -rf $(LIB)

re: fclean all
