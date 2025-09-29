NAME = array
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -Iheaders
CC = c++

OBJ_DIR = obj

SRC = main.cpp

OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "\e[32mCompilation completed\e[0m\n"

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[33m$(OBJ_DIR)/ deleted\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[33m$(NAME) deleted\e[0m\n"

re: fclean all

run: re
	@./$(NAME)

vrun: re
	@valgrind ./$(NAME)
