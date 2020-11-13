cmake_minimum_required(VERSION 3.17)
project(ft_ssl_my C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)

add_executable(ft_ssl_my
        src/main.c)
