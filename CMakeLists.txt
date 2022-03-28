cmake_minimum_required(VERSION 3.0.0) 

project(CalculatorDb)                  

add_executable(mainExecutable main.cpp)  
include_directories( /usr/local/lib )
target_link_libraries(mainExecutable PUBLIC sqlite3)