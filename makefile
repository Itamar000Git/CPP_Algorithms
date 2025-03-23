#itamarbabai98@gmail.com
C=g++
HEADERS=Edge.hpp Graph.hpp Queue.hpp Algorithms.hpp
Target=test1
FLAGS=-c -g -Wall
OBJECT=Graph.o Edge.o main.o Queue.o Algorithms.o
#doctest.h 
#Test.o
$(Target):$(OBJECT)
	$(C) -Wall -o $(Target) $(OBJECT)

Edge.o:Edge.cpp $(HEADERS)	
	$(C) $(FLAGS) Edge.cpp
Graph.o:Graph.cpp $(HEADERS)
	$(C) $(FLAGS) Graph.cpp
# Test.o:Test.cpp $(HEADERS)
# 	$(C) $(FLAGS) Test.cpp
Queue.o:Queue.cpp $(HEADERS)
	$(C) $(FLAGS) Queue.cpp
Algorithms.o:Algorithms.cpp $(HEADERS)
	$(C) $(FLAGS) Algorithms.cpp
main.o:main.cpp $(HEADERS)
	$(C) $(FLAGS) main.cpp

valgrind: $(Target)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(Target)

.PHONY:$(Target) clean

clean: 
	rm -f *.o $(Target)