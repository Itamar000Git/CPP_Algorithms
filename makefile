#itamarbabai98@gmail.com
# C=g++
# HEADERS=Edge.hpp Graph.hpp Queue.hpp Algorithms.hpp Union.hpp praiority_Q.hpp doctest.h
# Target=main
# TEST_TARGET=Test_prog
# FLAGS=-c -g -Wall
# OBJECT=Graph.o Edge.o main.o Queue.o Algorithms.o Union.o praiority_Q.o
# TEST_OBJ=Graph.o Edge.o Queue.o Algorithms.o Union.o praiority_Q.o Test_prog.o

# $(Target):$(OBJECT)
# 	$(C) -Wall -o $(Target) $(OBJECT)
# $(TEST_TARGET):$(TEST_OBJ)
# 	$(C) -Wall -o $(TEST_TARGET) $(TEST_OBJ)



# Edge.o:Edge.cpp $(HEADERS)	
# 	$(C) $(FLAGS) Edge.cpp
# Graph.o:Graph.cpp $(HEADERS)
# 	$(C) $(FLAGS) Graph.cpp
# Queue.o:Queue.cpp $(HEADERS)
# 	$(C) $(FLAGS) Queue.cpp
# praiority_Q.o:praiority_Q.cpp $(HEADERS)
# 	$(C) $(FLAGS) praiority_Q.cpp
# Algorithms.o:Algorithms.cpp $(HEADERS)
# 	$(C) $(FLAGS) Algorithms.cpp
# Union.o:Union.cpp $(HEADERS)
# 	$(C) $(FLAGS) Union.cpp
# main.o:main.cpp $(HEADERS)
# 	$(C) $(FLAGS) main.cpp

# Test_prog.o:Test_prog.cpp $(HEADERS)
# 	$(C) $(FLAGS) Test_prog.cpp


# run_tests:$(TEST_TARGET)
# 	./$(TEST_TARGET)


# valgrind:$(Target)
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(Target)

# valgrind_tests:$(TEST_TARGET)
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

# .PHONY:$(Target) clean

# clean: 
# 	rm -f *.o $(Target) $(TEST_TARGET)


C = g++
PATH_CPP = CPP_files/
PATH_HPP = HPP_files/

HEADERS = $(addprefix $(PATH_HPP), Edge.hpp Graph.hpp Queue.hpp Algorithms.hpp Union.hpp praiority_Q.hpp doctest.h)
Target = main
TEST_TARGET = Test_prog
FLAGS = -c -g -Wall -I$(PATH_HPP) -std=c++11
OBJECT = $(PATH_CPP)Graph.o $(PATH_CPP)Edge.o $(PATH_CPP)main.o $(PATH_CPP)Queue.o $(PATH_CPP)Algorithms.o $(PATH_CPP)Union.o $(PATH_CPP)praiority_Q.o
TEST_OBJ = $(PATH_CPP)Graph.o $(PATH_CPP)Edge.o $(PATH_CPP)Queue.o $(PATH_CPP)Algorithms.o $(PATH_CPP)Union.o $(PATH_CPP)praiority_Q.o $(PATH_CPP)Test_prog.o

$(Target): $(OBJECT)
	$(C) -Wall -o $(Target) $(OBJECT)

$(TEST_TARGET): $(TEST_OBJ)
	$(C) -Wall -o $(TEST_TARGET) $(TEST_OBJ)

$(PATH_CPP)Edge.o: $(PATH_CPP)Edge.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Edge.cpp -o $(PATH_CPP)Edge.o

$(PATH_CPP)Graph.o: $(PATH_CPP)Graph.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Graph.cpp -o $(PATH_CPP)Graph.o

$(PATH_CPP)Queue.o: $(PATH_CPP)Queue.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Queue.cpp -o $(PATH_CPP)Queue.o

$(PATH_CPP)praiority_Q.o: $(PATH_CPP)praiority_Q.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)praiority_Q.cpp -o $(PATH_CPP)praiority_Q.o

$(PATH_CPP)Algorithms.o: $(PATH_CPP)Algorithms.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Algorithms.cpp -o $(PATH_CPP)Algorithms.o

$(PATH_CPP)Union.o: $(PATH_CPP)Union.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Union.cpp -o $(PATH_CPP)Union.o

$(PATH_CPP)main.o: $(PATH_CPP)main.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)main.cpp -o $(PATH_CPP)main.o

$(PATH_CPP)Test_prog.o: $(PATH_CPP)Test_prog.cpp $(HEADERS)
	$(C) $(FLAGS) $(PATH_CPP)Test_prog.cpp -o $(PATH_CPP)Test_prog.o

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(Target)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(Target)

valgrind_tests: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

.PHONY: $(Target) clean

clean:
	rm -f $(PATH_CPP)*.o $(Target) $(TEST_TARGET)

