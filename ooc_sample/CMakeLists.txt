cmake_minimum_required(VERSION 2.8)

project(ooc_sample)

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
