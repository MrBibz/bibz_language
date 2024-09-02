cmake_minimum_required(VERSION 3.26)
project(bibz_language)

set(CMAKE_CXX_STANDARD 23)

add_executable(bibz_language header_files/token.h
        classes/lexer.cpp
        test.cpp
        header_files/lexer.h
)
