NAME = eval_expr

SRC = main.cpp Fixed.class.cpp to_postfix.cpp stack.cpp

OBJ =  main.o Fixed.class.o to_postfix.o  stack.o

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