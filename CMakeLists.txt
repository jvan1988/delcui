cmake_minimum_required(VERSION 3.12)
project(MyContextGrepProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files for your project
set(SOURCES src/main.cpp)
set(GIT_SOURCES src/ContextGrep.cpp)
set(TEST_SOURCES tests/TestContextGrep.cpp)

# Executable targets in the bin directory
add_executable(g-d-grep ${SOURCES})
add_executable(g-TestContextGrep ${TEST_SOURCES})

# Set the output directory for executables
set_target_properties(g-d-grep PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(g-TestContextGrep PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Link libraries
target_link_libraries(g-TestContextGrep PRIVATE CppUnit::CppUnit)

# Enable testing
enable_testing()

# Add a test
add_test(NAME g-TestContextGrep COMMAND g-TestContextGrep)

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


