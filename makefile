CXX = g++
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FLAGS = -Wall -pedantic -IHeaders

all: main
	./main
	rm main

main: Objects/main.o Objects/Game.o
	$(CXX) $^ $(SFML_FLAGS) $(FLAGS) -o main

Objects/main.o: main.cpp Headers/Game.hpp
	$(CXX) $(SFML_FLAGS) $(FLAGS) -c main.cpp -o Objects/main.o

Objects/Game.o: Implementations/Game.cpp Headers/Game.hpp
	$(CXX) $(SFML_FLAGS) $(FLAGS) -c Implementations/Game.cpp -o Objects/Game.o

clean:
	rm -f main Objects/*.o