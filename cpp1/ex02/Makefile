NAME = ex02
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CC = c++

OBJ_DIR = obj

SRC = main.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "\e[32mCompilation \tcompleted.\e[0m\n\n"

$(OBJ_DIR)/%.o:%.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[33m$(OBJ_DIR)/ \t\tdeleted.\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[33m$(NAME) \tdeleted.\e[0m\n"

re: fclean all

run: re
	@./$(NAME)

vrun: re
	@valgrind ./$(NAME)
