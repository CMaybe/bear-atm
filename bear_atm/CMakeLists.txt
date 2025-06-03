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
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
)
target_sources(
    ${PROJECT_NAME} PRIVATE
        src/account.cpp
		src/bank.cpp
		src/card.cpp
		src/bear_atm.cpp
)

# Testing
if("${PROJECT_NAME}_BUILD_TEST" AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	message(STATUS "Building tests for ${PROJECT_NAME}")
	add_subdirectory(test)
endif()


install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
	TARGETS bear_atm
	EXPORT bear_atm-targets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
	EXPORT bear_atm-targets
	FILE bear_atm-targets.cmake
	NAMESPACE bear_atm::
	DESTINATION ${INSTALL_CONFIGDIR}
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/bear_atm-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/bear_atm_config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/bear_atm-config.cmake
	INSTALL_DESTINATION $${INSTALL_CONFIGDIR}
)

install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/bear_atm-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/bear_atm-config-version.cmake
	DESTINATION ${INSTALL_CONFIGDIR}
)