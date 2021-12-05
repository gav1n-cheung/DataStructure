cmake_minimum_required(VERSION 3.20)
project(Class1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Class1 main.cpp SortTestHelper.h Student.h SelectionSort.h InsertionSort.h BubbleSort.h)
