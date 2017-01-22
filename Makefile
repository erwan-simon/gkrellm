##
## Makefile for  in /home/pe.merlier/Tek2/PiscineCpp/cpp_gkrellm
## 
## Made by Pierre-Emmanuel Merlier
## Login   <pe.merlier@epitech.net>
## 
## Started on  Sun Jan 22 04:43:15 2017 Pierre-Emmanuel Merlier
## Last update Sun Jan 22 09:31:17 2017 antoine
##

SRC=	Core.cpp\
	graphDisplay.cpp\
	graphDisplay2.cpp\
	Infos.cpp\
	lineDisplay.cpp\
	main.cpp\
	Network.cpp\
	textDisplay.cpp\
	User.cpp\

OBJ=	$(SRC:.cpp=.o)

NAME=	my_gkrellm

CXXFLAGS += -std=c++11 -Wall -W -Wextra -Werror

all:	$(NAME)

$(NAME):$(OBJ)
	@g++ $(OBJ) -o $(NAME) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@rm $(OBJ)

fclean:	clean
	@rm $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
