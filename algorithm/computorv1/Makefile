NAME		= computor

CC			= g++-9
FLAGS		= -g -Wall -Wextra -Werror
LIB			= lib/lib.a

INCLUDES	= ./includes/computorv1.hpp

SRC			= main.cpp \
			  parse.cpp \
			  pr_basic_checks.cpp \
			  pr_authorized.cpp \
			  pr_ignore.cpp \
			  solve.cpp \
			  sv_simple_equation.cpp \
			  sv_quadratic_equation.cpp \
			  sv_division.cpp \
			  error.cpp

OBJ			= Value.cpp \
			  Equation.cpp
OBJ_DIR		= objects/

SRC_PATH	= ./srcs/
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS		+= $(addprefix $(SRC_PATH), $(OBJ_DIR), $(OBJ))

BIN			= $(SRC:%.cpp=%.o)
BIN			+= $(addprefix $(OBJ_DIR), $(OBJ:%.cpp=%.o))
BIN_PATH	= ./bins/
BINS		= $(addprefix $(BIN_PATH), $(BIN))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(BIN_PATH) $(BIN_PATH)$(OBJ_DIR) $(BINS)
	$(CC) $(FLAGS) $(BINS) $(LIB) -o $@

$(BIN_PATH):
	@ mkdir $@

$(BIN_PATH)$(OBJ_DIR):
	@ mkdir $@

$(LIB):
	@ make -C lib

$(BIN_PATH)%.o: $(SRC_PATH)%.cpp $(HEADER)
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	@ make -C lib clean
	@ rm -rf $(BIN_PATH)

fclean: clean
	@ rm -rf $(LIB)
	@ rm -f $(NAME)

re: fclean all
