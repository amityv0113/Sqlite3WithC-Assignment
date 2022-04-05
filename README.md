# Calculator Application 
## Description
Calculator Application is used to performs arithmetic operations on numbers  can do addition, subtraction, multiplication, and division also store operation information in sqlite3 database 

## Run Locally

Clone the project

```bash
  git clone https://github.com/amityv0113/Sqlite3WithC-Assignment.git
```
Download sqlite3

```bash
  sudo apt install sqlite3 libsqlite3-dev
```

Go to the project directory

```bash
  cd Sqlite3WithC-Assignment
```

## Run code 
```
Windows

using cmd go/to/source code/folder :
 g++ src\main.cpp -lsqlite3
 .\a.exe
```
TODO: g++ on Windows?

```
Linux

using bash go/to/source code/folder :
 g++ src/main.cpp -lsqlite3
 ./a.out
```
## Run code using CMake
```
 cd build
 conan install ..
 cmake ..
 make 
 cd bin
 inside bin folder there is executable 
 run executable
```
## Package Management

Conan
```
  Inside build run conan install ..
  to install all external dependencies
```

## Usage
```
 need to update variable DirectoryLocation to/where/you/want to/create Db/sample.db
 run main file 
 calculator start runing 
 ask you to enter valid number num1
 ask you to enter valid number num2;
 ask you to enter operation code 
 - 1 mean addition 
 - 2 mean subtraction 
 - 3 mean multiplication
 - 4 mean division
 each time any operation is performed information is save in sqlite DB
 Db store num1,num2,operator,result

```
## Run Test
Go to the Calculator-test directory

```bash
  cd Calculator-test
```
Run Test using CMake
```
 cd build
 conan install .. 
 cmake ..
 cd bin
 inside bin folder there is executable 
 run executable
```
## Database schema 


| Id    | Num1      | Num2     | operator |   Result    |  
|:----- |:--------  |:---------|:-------- |:----------- |
|       |           |          |          |             |


## Database example 


| Id    | Num1      | Num2     | operator |   Result    |  
|:----- |:--------  |:---------|:-------- |:----------- |
|   4   |   25      |  5       |     /    | 5           |
## Tech Stack

**language:** C++

**Database:** Sqlite3

**package manager** conan

## Version

C++
```bash
 gcc version 11.2.0
```

CMake
```bash
  version 3.10.2
```
SQLite
```bash
  version 3.22.0
```

## Support

For support, email amityv0113@gmail.com or join our Slack channel.


## Authors

- [@amityv0113](https://github.com/amityv0113)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/amityv0113/)

## Comments
* Readme instructions are not well organized. Typically we have a prerequisites, building and running. For devs, there maybe a separate testing section.
  * Disjointed instructions in build/howToRunCmake.txt
* Commit messages are still not in "imperative mood"
* Software design is not test friendly
* Do we need to template the sum,sub,div,etc.. functions?
* CMakeLists has compiler and linker flags defined. Ideally we should we should be using the CMake abstractions to enable features without settings the flags manually.
* Clang format file should inherit a base style and then list the deviations
* I don't see the clang-tidy integration 
