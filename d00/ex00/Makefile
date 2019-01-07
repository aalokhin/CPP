NAME = megaphone

SRC = megaphone.cpp

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(OBJ) -o $(NAME)

$(OBJ):%.o:%.cpp
	@clang++ -std=c++98 -Wall -Wextra -Werror -c $(SRC) -o $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all