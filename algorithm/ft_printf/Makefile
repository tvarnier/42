# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/18 02:13:52 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2018/11/13 18:02:04 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SRCS =	srcs/ft_printf.c \
		srcs/ft_get_fct.c \
		srcs/ft_get_data.c \
		srcs/ft_struct_format.c \
		srcs/formats/ft_get_form_tab.c \
		srcs/formats/ft_form_d.c \
		srcs/formats/ft_form_o.c \
		srcs/formats/ft_form_p.c \
		srcs/formats/ft_form_u.c \
		srcs/formats/ft_form_x.c \
		srcs/formats/ft_form_c.c \
		srcs/formats/ft_form_s.c \
		srcs/formats/ft_form_percent.c \
		srcs/formats/ft_form_upper.c \
		srcs/formats/ft_form_f.c \
		srcs/formats/ft_form_b.c \
		srcs/formats/ft_form_e.c \
		srcs/formats/ft_form_g.c \
		srcs/formats/ft_form_r.c \
		srcs/formats/ft_form_k.c \
		srcs/formats/ft_form_t.c \
		srcs/formats/ft_size.c \
		srcs/formats/ft_prec.c \
		srcs/formats/ft_flag_default.c \
		srcs/formats/ft_flag_zero.c \
		srcs/formats/ft_flag_plus.c \
		srcs/formats/ft_flag_minus.c \
		srcs/formats/ft_flag_hashtag.c \
		srcs/formats/formats_fct/ft_unicode.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -I includes/ -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re: fclean all
