cmake_minimum_required(VERSION 3.31)
project(Bot-Barista-Cpp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
else()
    message(WARNING "Compilatore non riconosciuto! Usa MSVC, GCC o Clang per una configurazione ottimale.")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3 -g0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-O0 -g)
elseif (MSVC)
    message(WARNING "MSVC non usa build types.")
else()
    # message(WARNING "CMAKE_BUILD_TYPE non impostato su Release o Debug. Usa -DCMAKE_BUILD_TYPE=Release o -DCMAKE_BUILD_TYPE=Debug per ottimizzare.")
endif()

include(ProcessorCount)
ProcessorCount(N)
if(NOT N EQUAL 0)
    set(CMAKE_BUILD_PARALLEL_LEVEL ${N})
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}) # CLion :(
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)
