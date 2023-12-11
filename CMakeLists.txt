cmake_minimum_required(VERSION 3.20)

project(alg LANGUAGES CXX C ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/release/arc")


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(tree)
add_subdirectory(dp)
add_subdirectory(recrsive)
add_subdirectory(string)
add_subdirectory(RAII)
