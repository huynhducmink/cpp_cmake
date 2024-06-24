cmake_minimum_required(VERSION 3.10.0)
project(practice_cmake_project)
add_compile_options(-std=c++17 -Wall -Wextra -Wpedantic -O3)

# add program module that have child CMakeLists.txt file, this will call those files and build them first
add_subdirectory(modules)

# list all source file that need to be build
set (SRC_LIST
src/main.cpp
src/program.cpp
)
# list all header folder
set (INCLUDE_FOLDER
include)
# both can use GLOB, but CMake recommend add each file manually
# file(GLOB_RECURSE SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# message(SRC_LIST="${SRC_LIST}")

# precompiled static/dynamic library
set (LIB_LIST
${CMAKE_SOURCE_DIR}/library/library_1/bin/liblib1.a
${CMAKE_SOURCE_DIR}/library/library_2/bin/liblib2.so)
set (LIB_INCLUDE
${CMAKE_SOURCE_DIR}/library/library_1/include
${CMAKE_SOURCE_DIR}/library/library_2/include)

# build executable
add_executable(main ${SRC_LIST})
target_include_directories(main PUBLIC ${INCLUDE_FOLDER} ${LIB_INCLUDE})
target_link_libraries(main 
          module_1 
          module_2
          ${LIB_LIST}
          )