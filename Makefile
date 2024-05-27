CC = gcc
#FLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 

SRC = src/*.c 
NAME = run
LIBDIR = -LC:\mingw_dev_lib\lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
HEADERS = -IC:\mingw_dev_lib\include\SDL2

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(HEADERS) $(LIBDIR) -o $(NAME) $(SRC) $(LIBS)

clean:
	$(RM)  $(NAME)