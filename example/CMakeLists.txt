# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.27.4)

# Project name and language
project(atm_example LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Set C++ standard to C++17 or higher
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose build type: Debug, Release, RelWithDebInfo, MinSizeRel" FORCE)
endif()

find_package(bear_atm REQUIRED)

add_executable(${PROJECT_NAME} atm_example.cpp)


target_link_libraries(${PROJECT_NAME}
	bear_atm
)

