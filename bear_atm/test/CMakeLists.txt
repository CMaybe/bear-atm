cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

# Add test executables
add_executable(test_account test_account.cpp)
add_executable(test_card test_card.cpp)
add_executable(test_bank test_bank.cpp)
add_executable(test_atm test_atm.cpp)

# Link GoogleTest and the bear_atm library to each test executable
target_link_libraries(test_account GTest::gtest_main bear_atm)
target_link_libraries(test_card GTest::gtest_main bear_atm)
target_link_libraries(test_bank GTest::gtest_main bear_atm)
target_link_libraries(test_atm GTest::gtest_main bear_atm)

# Discover tests
include(GoogleTest)
gtest_discover_tests(test_account)
gtest_discover_tests(test_card)
gtest_discover_tests(test_bank)
gtest_discover_tests(test_atm)