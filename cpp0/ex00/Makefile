NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CC = c++

OBJ_DIR = obj

SRC = megaphone.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "\e[33mCompilation finished\e[0m\n"

$(OBJ_DIR)/%.o:%.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\e[34m$(OBJ_DIR) deleted.\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[34m$(NAME) deleted.\e[0m\n"

re: fclean all