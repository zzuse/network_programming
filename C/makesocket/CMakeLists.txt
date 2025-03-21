# For now standalone executable maybe change later to a lib
# add_executable(make_socket make_socket.c)
# target_link_libraries(make_socket anexe)

cmake_minimum_required(VERSION 3.25)
project(make_socket)

message("CC version = ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_executable(make_socket make_socket.c)