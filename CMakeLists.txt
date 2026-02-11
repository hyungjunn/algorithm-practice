cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER "/opt/homebrew/Cellar/llvm/21.1.8/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm/21.1.8/bin/clang++")

project(algorithm_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(algorithm_practice main.cpp)

set(SOLUTION_DIRS baekjoon programmers)

function(add_solution_targets)
    foreach(source IN LISTS ARGN)
        file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}" "${source}")
        string(REPLACE ".cpp" "" target_name "${rel_path}")
        string(REPLACE "/" "_" target_name "${target_name}")
        add_executable("${target_name}" "${source}")
    endforeach()
endfunction()

set(SOLUTION_SOURCES)
foreach(dir IN LISTS SOLUTION_DIRS)
    if(EXISTS "${CMAKE_SOURCE_DIR}/${dir}")
        file(GLOB_RECURSE dir_sources CONFIGURE_DEPENDS "${dir}/*.cpp")
        list(APPEND SOLUTION_SOURCES ${dir_sources})
    endif()
endforeach()

if(SOLUTION_SOURCES)
    add_solution_targets(${SOLUTION_SOURCES})
endif()
