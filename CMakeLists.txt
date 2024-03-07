cmake_minimum_required(VERSION 3.12)
project(MyContextGrepProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files for your project
set(SOURCES src/main.cpp)
set(GIT_SOURCES src/ContextGrep.cpp)
set(TEST_SOURCES tests/test_contextgrep.cpp)

# Executable targets
add_executable(bin/d-grep ${SOURCES})
add_executable(bin/TestContextGrep ${TEST_SOURCES})

# Link libraries
target_link_libraries(MyTestContextGrepExecutable PRIVATE CppUnit::CppUnit)

# Enable testing
enable_testing()

# Add a test
add_test(NAME TestContextGrep COMMAND TestContextGrep)

# Download and build CppUnit
include(FetchContent)
FetchContent_Declare(
  cppunit
  GIT_REPOSITORY https://github.com/jvan1988/delcui.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(cppunit)

# Link CppUnit with the test executable
target_link_libraries(TestContextGrep PRIVATE CppUnit::CppUnit)


