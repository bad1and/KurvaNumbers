cmake_minimum_required(VERSION 3.29)
project(KurvaNumbers C)
set(CMAKE_C_STANDARD 17)
add_executable(KurvaNumbers main.c)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(KurvaNumbers ${CURSES_LIBRARIES})