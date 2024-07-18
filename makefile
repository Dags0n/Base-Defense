CXX = g++
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FLAGS = -Wall -pedantic -IHeaders

# Target: all (default target)
all: main
	./main
	rm main

# Target: main (executable)
main: Objects/main.o Objects/Game.o
	$(CXX) $^ $(SFML_FLAGS) $(FLAGS) -o main

# Target: main.o (object file for main.cpp)
Objects/main.o: main.cpp Headers/Game.hpp
	$(CXX) $(SFML_FLAGS) $(FLAGS) -c main.cpp -o Objects/main.o

# Target: Game.o (object file for Game.cpp)
Objects/Game.o: Implementations/Game.cpp Headers/Game.hpp
	$(CXX) $(SFML_FLAGS) $(FLAGS) -c Implementations/Game.cpp -o Objects/Game.o

# Clean target to remove executable and object files
clean:
	rm -f main Objects/*.o