NAME		:= ft_retro

# directories
SRC_DIR		:= ./src
OBJ_DIR		:= ./obj

# src / obj files
SRC			:=	main.cpp \
				Player.cpp \
				Creep.cpp \
				Shot.cpp \
				IEntity.cpp \
				NAList.cpp \
				NCurses.cpp

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

# compiler
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c++98
CXXFLAGS	+= -O3 -march=native -pipe -flto

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
