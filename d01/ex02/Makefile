NAME = zombie

SRC = main.cpp Zombie.cpp ZombieEvent.cpp

OBJ = main.o Zombie.o ZombieEvent.o

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(OBJ) -o $(NAME)

$(OBJ):%.o:%.cpp
	@clang++ -std=c++98 $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all