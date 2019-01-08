NAME = phonebook

SRC = main.cpp AwesomePhonebook.cpp

OBJ = main.o AwesomePhonebook.o


all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(OBJ) -o $(NAME)

$(OBJ):%.o:%.cpp
	@clang++ -std=c++98 -Wall -Wextra -Werror -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
