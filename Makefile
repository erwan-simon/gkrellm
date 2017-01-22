all:
	g++ **.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 -lncurses -Wall -w -Wextra
