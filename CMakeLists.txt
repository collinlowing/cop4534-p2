cmake_minimum_required(VERSION 3.24)
project(cop4534_p2)

set(CMAKE_CXX_STANDARD 11)

add_executable(cop4534_p2 main.cpp Simulation.cpp Simulation.hpp FileParser.cpp FileParser.hpp AnalyticalModel.cpp AnalyticalModel.hpp PriorityQueue.cpp PriorityQueue.hpp FIFO_Queue.cpp FIFO_Queue.hpp Event.cpp Event.hpp)

add_subdirectory(Google_Tests)
