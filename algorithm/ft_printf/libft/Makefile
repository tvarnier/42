# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 12:33:35 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2018/11/13 17:56:40 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCS = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strnchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strchar.c \
		ft_strinit.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_ftoa.c \
		ft_uitoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstaddback.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_sort_int_tab.c \
		ft_pow.c \
		ft_sqrt.c \
		ft_islower.c \
		ft_isupper.c \
		ft_get_next_line.c \
		ft_intlen.c \
		ft_uintlen.c \
		ft_putunbr.c \
		ft_strbase.c \
		ft_ttob.c \
		ft_strrep.c \
		ft_lstrnew.c \
		ft_lstraddback.c \
		ft_lstrclr.c \
		ft_abs.c \
		ft_round.c \
		ft_date.c

FLAGS = -Wall -Wextra -Werror -g

HEADER = ./includes/libft.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ ar rc $(NAME) $(OBJ)
		@ ranlib $(NAME)

%.o: %.c
		@ $(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
		@ rm -rf $(OBJ)

fclean: clean
		@ rm -rf $(NAME)

re: fclean all
