##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN	=					main.cpp

SRC_DIR = 					src/

GLOBALS_DIR	= 				globals/

SRC_FILES	=				rubiks_cube.cpp				\
							cube.cpp					\

GLOBALS_FILES	=			sfml_globals.cpp			\

SRCTEST = 	tests/test_lib.c							\

SRC		=	$(addprefix $(SRC_DIR), $(SRC_FILES)		\
				$(addprefix $(GLOBALS_DIR),				\
					$(GLOBALS_FILES)					\
				)										\
			)											\

OBJ	= 	$(MAIN:.cpp=.o) $(SRC:.cpp=.o)

OBJTEST =	$(SRCTEST:.cpp=.o)

NAME	=	rubiks_cube

NAMETEST = 	unit_tests

CXXFLAGS = -Wall -Wextra -g

CPPFLAGS	=	-I./include

GRAPHICS	=	-lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window

MATHS		=	-lm

CC = g++

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(GRAPHICS) $(MATHS)

buildlib:
	make -C ./lib/my

buildlibtest: buildlib
	make -C ./lib/my CFLAGS='$(CPPFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest: buildlibtest $(OBJTEST)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAMETEST) $(OBJTEST) $(SRC) $(LDLIBS)	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "*.cor" -delete

fclean: clean cleantest
	rm -f $(NAME)

cleantest:
		rm -f $(NAMETEST)
		rm -f $(OBJTEST)

re: fclean all

valgrind: buildlib $(OBJ)
	$(CC) -g3 $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

unit_tests: buildtest

tests_run: unit_tests
		./unit_tests

.PHONY: all clean fclean re valgrind unit_tests tests_run cleantest
		buildlibtest buildtest buildlib
