# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:50:28 by bmenant           #+#    #+#              #
#    Updated: 2021/12/17 17:33:38 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			main.cpp \
				parse.cpp \
				Equation.cpp

GREEN =			\033[0;32m
BLUE =			\033[1;34m
YELLOW =		\033[1;33m
WHITE =			\033[1;37m
OK =			$(GREEN)-OK-$(WHITE)

CXX =			clang++
NAME =			computor

SRC_FILE =		./src/
OBJ_FILE =		./obj/

OBJ =			$(SRC:.cpp=.o)

SRCS =			$(addprefix $(SRC_FILE),$(SRC))
OBJS =			$(addprefix $(OBJ_FILE),$(OBJ))

# LFLAGS =		`sdl2-config --libs --cflags`
FLAGS =			-Wall
STDFLAGS =		-std=c++11
# OFLAGS =		-O3
# IFLAGS =		-I ./inc/
# CFLAGS =		-g3 -fsanitize=address
# LIBFLAGS =		-lm -pthread

RM =			/bin/rm -f

.PHONY:			all clean fclean re


all : $(NAME)

$(OBJ_FILE)%.o : $(SRC_FILE)%.cpp
	@mkdir $(OBJ_FILE) 2> /dev/null || true
	@$(CXX) $(FLAGS) $(STDFLAGS) -o $@ -c $<
	@echo "$@\r				$(OK)"

$(NAME) : $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)
	@echo "$(BLUE)-$(NAME)-\r				$(OK)"

clean :
	@rm -Rf $(OBJ_FILE)
	@echo "$(BLUE)-clean-\r				$(OK)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(BLUE)-fclean-\r				$(OK)"

re	: fclean all