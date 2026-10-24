cmake_minimum_required(VERSION 3.27)
project(PK1Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()

add_executable(PK1Chess
        main.cpp
        board.cpp
        board.h
        Movement/movement.cpp
        Movement/movement.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add your test source file
add_executable(tests
        Test/tests.cpp
        board.cpp
        board.h
        Movement/movement.cpp
        Movement/movement.h

)

# Link the Google libraries to your test executable
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)