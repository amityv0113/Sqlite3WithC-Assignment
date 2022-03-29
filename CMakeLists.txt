cmake_minimum_required(VERSION 3.0.0) 

project(CalculatorDb)                  
find_package (SQLite3)

add_executable(mainExecutable main.cpp) 

target_link_libraries(mainExecutable LINK_PUBLIC sqlite3)