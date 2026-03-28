cmake_minimum_required(VERSION 3.25)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/semver.cmake)

read_semver(DEBUG_INFO FILE_NAME "Version" MV a b c d e)
message("MY_VERSION_MAJOR=${VERSION_MAJOR}, MY_VERSION_MINOR=${VERSION_MINOR}, MY_VERSION_PATCH=${VERSION_PATCH}")
message("VERSION=${VERSION}")

project(zz
        VERSION ${VERSION}
        LANGUAGES C CXX)

function(set_compiler_options lib_name)
        message("${CMAKE_CURRENT_FUNCTION} called with ${lib_name}")
        if(MSVC)
                target_compile_options(${lib_name} PRIVATE /Wall /WX)
        else()
                target_compile_options(${lib_name} PRIVATE -Wall) # -Werror)
        endif()
endfunction()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

# Put the libaries and binaries that get built into directories at the
# top of the build tree rather than in hard-to-find leaf directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# check epoll and add config.h for the macro compilation
include_directories(${PROJECT_SOURCE_DIR})

set(EPOLL_ENABLE "" CACHE INTERNAL "not enable epoll")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
add_subdirectory(lib/)
add_subdirectory(makesocket/)
add_subdirectory(tcpserver/)
add_subdirectory(udpserver/)
add_subdirectory(localsocket/)
add_subdirectory(graceclose/)
add_subdirectory(keepalive/)