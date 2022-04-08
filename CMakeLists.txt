cmake_minimum_required(VERSION 3.0.0) 
# pro
project(sqliteWithC++Assignment)  
set(CMAKE_CXX_STANDARD 11)
# adding dependency
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -header-filter=.;
  -checks=*;
  )
#   set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy;
#   -header-filter=.;
#   -checks=*;
#   -warnings-as-errors=*;)


add_executable(mainExecutable src/main.cpp) 
target_link_libraries(mainExecutable ${CONAN_LIBS})