NAME = convert

CXX = c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	= -MMD

SRCS		=	main.cpp\
				TypeGuesser.cpp


OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(@)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

test:	$(NAME)
		./$(NAME) 42.42f

vtest:	$(NAME)
		valgrind --leak-check=full ./$(NAME) 42.42f

-include $(DEPS)

.PHONY: all clean fclean re test vtest
