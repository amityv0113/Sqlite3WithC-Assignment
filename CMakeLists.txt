cmake_minimum_required(VERSION 3.0.0) 
# pro
project(sqliteWithC++Assignment)  
set(CMAKE_CXX_STANDARD 11)
# adding dependency
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
# enable Address Sanitizer in cmake 
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")              
add_executable(mainExecutable src/main.cpp) 
target_link_libraries(mainExecutable ${CONAN_LIBS})