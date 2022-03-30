# Calculator Application 
## Description
Calculator Application is used to performs arithmetic operations on numbers  can do addition, subtraction, multiplication, and division also store operation information in sqlite3 database 

## Run code 
```
Windows

using cmd go/to/source code/folder :
- g++ main.cpp -lsqlite3
- .\a.exe
```

```
Linux

uding bash go/to/source code/folder :
- g++ main.cpp -lsqlite3
- ./a.out
```
## Run code using CMake
```
: go inside build folder using cd build 
: cmake ..
: make 
: inside build folder there is executable 
: run executable
```
## Usage
```
: need to update variable DirectoryLocation to/where/this repo/folder/exit/in/your/pc
: run main file 
: calculator start runing 
: ask you to enter valid number num1
: ask you to enter valid number num2;
: ask you to enter operation code 
-: 1 mean addition 
-: 2 mean subtraction 
-: 3 mean multiplication
-: 4 mean division
: each time any operation is performed information is save in sqlite DB
: Db store num1,num2,operator,result

```