NAME = find

CXX = c++

FLAGS = -std=c++98 -Werror -Wextra -Wall -MMD -g

OBJ_DIR = ./bin

SRC = main.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

DEPS = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.d))

vpath %.cpp src

all: makedir $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile
	$(CXX) $(FLAGS) -c $< -o $@

-include $(DEPS)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $@

makedir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re makedir
