LIBS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXX = g++
CXXFLAGS=-I ~/learn_c/SFML-2.5.1/include -I include
SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:.cpp=.o)

all: play

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;


# %.o: %.cpp 
	# $(CXX) -c $<  -I ~/learn_c/SFML-2.5.1/include -I include


play: $(OBJECTS)
	$(CXX) -o play $(OBJECTS) $(LIBS) -L ~/learn_c/SFML-2.5.1/lib


clean:
	@echo "** Removing object files and executable..."
	rm *.o
	rm -f play

install:
	@echo '** Installing...'
#	cp thegame /usr/bin

uninstall:
	@echo '** Uninstalling...'
#	rm play
