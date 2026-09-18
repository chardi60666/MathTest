cmake_minimum_required(VERSION 3.30)
project(MathTest)

set(CMAKE_CXX_STANDARD 20)

# Статическая библиотека
add_library(Lib STATIC
        Lib/Task.cpp
        Lib/Task.h
)

# Основное приложение
add_executable(MathTest
        main.cpp
        MathTest.h
        MathTest.cpp
)

target_link_libraries(MathTest PRIVATE Lib)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

# Тесты
add_executable(GoogleTestTests
        tests/test_task.cpp
        tests/test_mathtest.cpp
        MathTest.cpp
)

target_link_libraries(GoogleTestTests
        gtest_main
        Lib
)

include(GoogleTest)

gtest_discover_tests(GoogleTestTests)