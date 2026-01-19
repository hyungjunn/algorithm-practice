cmake_minimum_required(VERSION 4.1)
project(algorithm_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(algorithm_practice main.cpp)

file(GLOB_RECURSE SOURCES "baekjoon/*.cpp")
foreach (file ${SOURCES})
    # 파일 경로에서 파일 이름(확장자 제외)만 추출
    get_filename_component(target_name ${file} NAME_WE)
    # 해당 이름으로 실행 파일 생성
    add_executable(${target_name} ${file})
endforeach ()
