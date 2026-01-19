cmake_minimum_required(VERSION 4.1)
project(algorithm_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(algorithm_practice main.cpp)

file(GLOB_RECURSE SOURCES "baekjoon/*.cpp" "programmers/*.cpp")
foreach(file ${SOURCES})
    # 파일의 상대 경로를 구합니다 (예: baekjoon/4179.cpp)
    file(RELATIVE_PATH rel_path ${CMAKE_SOURCE_DIR} ${file})
    # 확장자(.cpp)를 제거합니다 (예: baekjoon/4179)
    string(REPLACE ".cpp" "" target_name ${rel_path})
    # 슬래시(/)를 언더바(_)로 바꿉니다 (예: baekjoon_4179)
    string(REPLACE "/" "_" target_name ${target_name})
    # 해당 이름으로 실행 파일 생성
    add_executable(${target_name} ${file})
endforeach()
