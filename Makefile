# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 17:50:28 by bmenant           #+#    #+#              #
#    Updated: 2022/01/18 16:33:42 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			main.cpp \
				Equation.cpp \
				Parser.cpp \
				Solver.cpp \
				Parsersimplified.cpp \
				Equationsimplified.cpp

GREEN =			\033[0;32m
BLUE =			\033[1;34m
YELLOW =		\033[1;33m
WHITE =			\033[0;37m
OK =			$(GREEN)-OK-$(WHITE)

CXX =			clang++
NAME =			computor

SRC_FILE =		./src/
OBJ_FILE =		./obj/

OBJ =			$(SRC:.cpp=.o)

SRCS =			$(addprefix $(SRC_FILE),$(SRC))
OBJS =			$(addprefix $(OBJ_FILE),$(OBJ))

FLAGS =			-Wall -Wextra -Werror
STDFLAGS =		-std=c++11

RM =			/bin/rm -f

.PHONY:			all clean fclean re test


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

test : all
	@echo ""
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "START OF THE BASIC TESTS"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo ""
	./$(NAME)
	./$(NAME) test
	./$(NAME) test test
	./$(NAME) test test test
	./$(NAME) "-1 * X^0 - 2 * X^1 = 3.45 * X^2 + 0 * X^1"
	./$(NAME) "5 * X^0 = 5 * X^0"
	./$(NAME) "4 * X^0 = 8 * X^0"
	./$(NAME) "5 * X^0 = 4 * X^0 + 7 * X^1"
	./$(NAME) "5 * X^0 + 13 * X^1 + 3 * X^2 = 1 * X^0 + 1 * X^1"
	./$(NAME) "6 * X^0 + 11 * X^1 + 5 * X^2 = 1 * X^0 + 1 * X^1"
	./$(NAME) "5 * X^0 + 3 * X^1 + 3 * X^2 = 1 * X^0 + 0 * X^1"
	./$(NAME) "2 * X^0 + 7 * X^1 + 3.2 * X^2 = 1 * X^0 + 2 * X^3"
	./$(NAME) "1 * X^0 + 9 * X^1 + 1.3 * X^2 = 1 * X^4 + 5 * X^3"

	@echo ""
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "START OF THE ADVANCED TESTS"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo ""
	./$(NAME) -n test test
	./$(NAME) -n "" 
	./$(NAME) -n " "
	./$(NAME) -n "test"
	./$(NAME) -n "2 = "
	./$(NAME) -n "2= 0"
	./$(NAME) -n " = 0"
	./$(NAME) -n "-2 = 0"
	./$(NAME) -n "0 = 2"
	./$(NAME) -n "2 = 0"
	./$(NAME) -n "5 = 5"
	./$(NAME) -n "4 = 8"
	./$(NAME) -n "5 = 4 + 7 * X"
	./$(NAME) -n "5 + 13 * X + 3 * X^2 = 1 + 1 * X"
	./$(NAME) -n "6 + 11 * X + 5 * X^2 = 1 + 1 * X"
	./$(NAME) -n "5 + 3 * X + 3 * X^2 = 1 + 0 * X"
	./$(NAME) -n "2 + 7 * X + 3.2 * X^2 = 1 + 2 * X^3"
	./$(NAME) -n "1 + 9 * X + 1.3 * X^2 = 1 * X^4 + 5 * X^3"