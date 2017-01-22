NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./Core.cpp \
	  ./Infos.cpp \
	  ./Network.cpp \
	  ./User.cpp \
	  ./graphDisplay.cpp \
	  ./lineDisplay.cpp \
	  ./main.cpp \
	  ./textDisplay.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I./pp
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
