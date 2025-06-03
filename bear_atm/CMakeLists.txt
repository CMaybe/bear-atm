cmake_minimum_required(VERSION 3.27.4)

project(bear_atm VERSION 0.1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

# Build options
option(${PROJECT_NAME}_BUILD_TEST "Build unit test" ${PROJECT_IS_TOP_LEVEL})


add_library(${PROJECT_NAME} SHARED)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_sources(
    ${PROJECT_NAME} PRIVATE
        src/account.cpp
		src/bank.cpp
		src/card.cpp
)

# Testing
if(${PROJECT_NAME}_BUILD_TEST AND ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	message(STATUS "Building tests for ${PROJECT_NAME}")
	add_subdirectory(test)
endif()