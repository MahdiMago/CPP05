NAME = bureaucrat
SRC = main.cpp Bureaucrat.cpp
FLAGS = c++ -Werror -Wall -Wextra -std=c++98

$(NAME): $(SRC)
	$(FLAGS) -o $(NAME) $(SRC) 

all: $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

run: re
	./$(NAME)
