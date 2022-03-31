cmake_minimum_required(VERSION 3.0.0) 

project(sample_sum_project)  
                      
add_subdirectory(googletest)                         # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
include_directories(googlemock/include) # this is so we can #include <gtest/gtest.h>

add_executable(mainExecutable src/unit_test.cpp)  #  executable

target_link_libraries(mainExecutable PRIVATE gtest gmock sqlite3) # link google test to this executable and also linking gmock