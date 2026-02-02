NAME        = bureaucrat

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

CHILDS_DIR  = childs/

SRCS        = main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
			  Intern.cpp \
              $(CHILDS_DIR)ShrubberyCreationForm.cpp \
              $(CHILDS_DIR)RobotomyRequestForm.cpp \
              $(CHILDS_DIR)PresidentialPardonForm.cpp

OBJS        = $(SRCS:.cpp=.o)

RM          = rm -f

all:        $(NAME)

$(NAME):    $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			$(RM) *_shrubbery

fclean:     clean
			$(RM) $(NAME)

re:         fclean all

run:        re
			./$(NAME)

.PHONY:     all clean fclean re run