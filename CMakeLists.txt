cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(AoC_2020)

include_directories(include)

file( GLOB APP_SOURCES src/*.cpp )
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR}/src ${sourcefile})
    string( REPLACE ".cpp" "" file ${filename} )
    add_executable( ${file} ${sourcefile} )
endforeach( sourcefile ${APP_SOURCES} )