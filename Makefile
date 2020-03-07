LIBS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXX := g++


all: play


%.o: %.cpp 
	$(CXX) -c $< -o $@ -I ~/learn_c/SFML-2.5.1/include -I include


play: *.o
	$(CXX) -o play *.o $(LIBS) -L ~/learn_c/SFML-2.5.1/lib


clean:
	@echo "** Removing object files and executable..."
	rm -f play

install:
	@echo '** Installing...'
#	cp thegame /usr/bin

uninstall:
	@echo '** Uninstalling...'
#	rm play
