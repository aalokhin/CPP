NAME = NinjaTrap

SRC = main.cpp FragTrap.cpp  ScavTrap.cpp ClapTrap.cpp NinjaTrap.cpp SuperTrap.cpp

OBJ =  main.o FragTrap.o ScavTrap.o ClapTrap.o NinjaTrap.o SuperTrap.o

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