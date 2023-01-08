cmake_minimum_required(VERSION 3.20)

project(offline-2)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "-fsanitize=address")
endif()


find_package(fmt CONFIG REQUIRED)


add_subdirectory(problem-1)
add_subdirectory(problem-2)
add_subdirectory(problem-3)
