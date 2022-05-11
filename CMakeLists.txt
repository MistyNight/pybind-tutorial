cmake_minimum_required(VERSION 3.4...3.18)
project(pybind_test)

# fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Set C++ Standard specification.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Find packages
find_package(OpenCV REQUIRED)

# Includes
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

# Set variable
set(INTERFACE_FILES
  interface/pybind_test_interface.cpp
)

set(NATIVE_FILES
  src/image.cpp
)

# Link OpenCV libraries.
LINK_DIRECTORIES(
  ${OpenCV_LIB_DIR}
)

# Make cpp library.
add_library(image ${NATIVE_FILES})
target_link_libraries(image ${OpenCV_LIBS})

# Make python module.
add_subdirectory(pybind11)
pybind11_add_module(${PROJECT_NAME} MODULE ${INTERFACE_FILES}) 
target_link_libraries(${PROJECT_NAME} PRIVATE image)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(${PROJECT_NAME}
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
