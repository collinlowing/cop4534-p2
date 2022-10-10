# 'Google_test' is the subproject name
project(Google_Tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run ../Simulation.cpp ../Simulation.hpp testSimulation.cpp ../FileParser.cpp ../FileParser.hpp testFileParser.cpp ../AnalyticalModel.cpp ../AnalyticalModel.hpp testAnalyticalModel.cpp ../PriorityQueue.cpp ../PriorityQueue.hpp testPriorityQueue.cpp ../FIFO_Queue.cpp ../FIFO_Queue.hpp testFIFO_Queue.cpp ../Event.cpp ../Event.hpp testEvent.cpp ../Heap.hpp ../Heap.cpp testHeap.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main gmock gmock_main)