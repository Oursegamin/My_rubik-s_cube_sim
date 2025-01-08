##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN		=	main.cpp

SRC_DIR 	=	src/

TEST_DIR	=	tests/

SRC_LIB		=	$(wildcard lib/my/*.cpp)

SRC_FILES	=	window.cpp									\
				rubiks_cube.cpp								\
				settings.cpp								\
				help.cpp									\
				rubiks_moves.cpp							\
				gl_cube.cpp									\

TEST_FILES	=	vector3_tests.cpp							\
				vector4_tests.cpp							\
				matrix3_tests.cpp							\
				matrix4_tests.cpp							\

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_TEST	=	$(addprefix $(TEST_DIR), $(TEST_FILES))

OBJ			=	$(MAIN:.cpp=.o)								\
				$(SRC:.cpp=.o)								\

OBJTEST		=	$(SRC_TEST:.cpp=.o)

NAME		=	rubiks_cube

NAMETEST	=	unit_tests

CXXFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-I./include

CPPFLAGSLIB	=	-I./lib/include

LDLIBS		=	-L./lib -lmy # -lglad

GRAPHICS	=	-lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window

GLXFLAGS	=	-lGL -lGLU -lglut

MATHS		=	-lm

LIBS		=	$(LDLIBS) $(GRAPHICS) $(GLXFLAGS) $(MATHS)

WINLIBS		=	-LC:/SFML/lib $(GRAPHICS) -lopengl32 -lgdi32

CC			=	g++

all: $(NAME)

$(NAME):	buildlib	$(OBJ)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(LIBS)

build_windows: buildlib $(OBJ)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $(NAME).exe $(OBJ) $(WINLIBS)

run_windows: build_windows
	./$(NAME).exe

buildlib:
	make -C ./lib

buildlibtest:
	make -C ./lib CXXFLAGS='$(CXXFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest:	fclean_silent	buildlibtest	$(OBJTEST)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(CPPFLAGSLIB) -o $(NAMETEST) \
	$(OBJTEST) $(SRC) $(SRC_LIB) --coverage -lcriterion	$(LIBS)

clean:
	make -C ./lib clean
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "*.cor" -delete

fclean: clean cleantest
	make -C ./lib fclean
	rm -f $(NAME)

fclean_silent:
	@$(MAKE) fclean

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
		buildlibtest buildtest buildlib build_windows run_windows
