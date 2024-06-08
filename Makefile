SOURCES = main.c graphics.c board.c snake.c food.c
snake_game: $(SOURCES)
	gcc -Wall -g -o snake_game.exe $(SOURCES) -lcsfml-graphics -lcsfml-window -lcsfml-system
.PHONY: test clean all
