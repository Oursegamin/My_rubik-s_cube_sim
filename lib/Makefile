##
## EPITECH PROJECT, 2024
## lib
## File description:
## Makefile
##

MY_DIR		=	my/

OTHER_DIR	=	other/

MY_FILES	=	vector3.cpp								\
				vector4.cpp								\
				matrix3.cpp								\
				matrix4.cpp								\
				sfml_globals.cpp						\

OTHER_FILES	=	other.c

MY_SRC		=	$(addprefix $(MY_DIR), $(MY_FILES))										\

OTHER_SRC	=	$(addprefix $(OTHER_DIR), $(OTHER_FILES))

MY_OBJ     	=	$(MY_SRC:.cpp=.o)

OTHER_OBJ	=	$(OTHER_SRC:.c=.o)

OBJ			=	$(MY_OBJ) # $(OTHER_OBJ) ...

MY			=	libmy.a

OTHER		=	libother.a

CPPFLAGS	=	-I./include

CXXFLAGS	=	-W -Wall -Wextra

CC			=	gcc

all: $(MY)

$(MY):	$(MY_OBJ)
	ar rc $(MY) $(MY_OBJ)

$(OTHER):	$(OTHER_OBJ)
	ar rc $(OTHER) $(OTHER_OBJ)

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcor*" -delete

fclean:		clean
	rm -f $(MY)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY:-all clean fclean re
