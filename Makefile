CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs -pthread

OBJECTS = AnalyticalModel.o Event.o FIFO_Queue.o FileParser.o Heap.o Simulation.o


main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gc* *.dSYM test/test core main