cmake_minimum_required(VERSION 3.4...3.18)
project(arithmetic)

add_subdirectory(pybind11)
pybind11_add_module(arithmetic src/arithmetic.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(arithmetic
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
