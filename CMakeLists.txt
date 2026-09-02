cmake_minimum_required(VERSION 3.20)

project(machc_threaded_raytracer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



find_package(Threads REQUIRED)

set(SOURCES 
    src/main.cpp
    include/ray.hpp
    include/vec3.hpp
    include/sphere.hpp
    include/triangle.hpp
)

add_executable(machc_trace ${SOURCES}) 

target_include_directories(machc_trace PRIVATE include)

target_link_libraries(machc_trace PRIVATE Threads::Threads)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(machc_trace PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
elseif(MSVC)
    target_compile_options(machc_trace PRIVATE /W4 /w14242 /w14254 /w14263)
endif()