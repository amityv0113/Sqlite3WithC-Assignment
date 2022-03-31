cmake_minimum_required(VERSION 3.0.0) 
# pro
project(sqliteWithC++Assignment)  
# enable Address Sanitizer in cmake 
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")              
add_executable(mainExecutable src/main.cpp) 
target_link_libraries(mainExecutable LINK_PRIVATE sqlite3)