TARGET = btc

SRCS = main.cpp \
		BitcoinExchange.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(TARGET) $(OBJS)

%.o: %.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -rf $(TARGET)

re : fclean all

.PHONY: clean fclean re