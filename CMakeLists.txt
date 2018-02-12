cmake_minimum_required(VERSION 2.8.3)
project(manhattan)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -fPIC")

find_package(Ceres REQUIRED)
find_package(Eigen3  REQUIRED)
include_directories(
  ${CERES_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_executable(manhattan_test
    ./src/test.cpp
    ./src/lib/manhattan.cpp
    )

target_link_libraries(manhattan_test  ${CERES_LIBRARIES})
