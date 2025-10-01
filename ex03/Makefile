NAME = program

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

SRCS =	main.cpp \
		Point.cpp \
		Fixed.cpp \
		bsp.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re