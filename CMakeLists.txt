cmake_minimum_required(VERSION 2.6)
project(techpark)

set(CMAKE_CXX_STANDARD 14)
SET(COVERAGE OFF CACHE BOOL "Coverage")

#add_executable(techpark )

include_directories(include/command_manager)

include_directories(src/command_manager)

# sets GTEST_INCLUDE_DIRS and GTEST_LIBRARIES
find_package(GTest REQUIRED)
# adds the gtest include directory
include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(gtest src/command_manager/command/tests/test_commands.cpp)

add_executable(gtest src/command_manager/db/tests/test_db.cpp src/command_manager/file_system/tests/test_file_system.cpp src/command_manager/command/tests/test_commands.cpp)

# links gtest
target_link_libraries(gtest ${GTEST_LIBRARIES})