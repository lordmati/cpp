TARGET = RPN

SRCS = main.cpp \
		RPN.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ -Wall -Wextra -Werror -std=c++98 -o $(TARGET) $(OBJS)

%.o: %.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -rf $(TARGET)

re : fclean all

.PHONY: clean fclean re