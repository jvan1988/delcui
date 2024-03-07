cmake_minimum_required(VERSION 3.12)
project(MyContextGrepProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the main source files
set(SOURCES
    src/ContextGrep.cpp
    src/main.cpp
)

# Add an executable for the main application
add_executable(ContextGrep ${SOURCES})

# Add an executable for tests
add_executable(TestContextGrep
    tests/TestContextGrep.cpp
    src/ContextGrep.cpp
)

# Set include directories
target_include_directories(ContextGrep PRIVATE include)
target_include_directories(TestContextGrep PRIVATE include)

# Enable testing
enable_testing()

# Add a test
add_test(NAME TestContextGrep COMMAND TestContextGrep)

# Download and build CppUnit
include(FetchContent)
FetchContent_Declare(
  cppunit
  GIT_REPOSITORY https://github.com/jvan1988/delcui.git
)
FetchContent_MakeAvailable(cppunit)

# Link CppUnit with the test executable
target_link_libraries(TestContextGrep PRIVATE CppUnit::CppUnit)


