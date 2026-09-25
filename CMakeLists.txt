cmake_minimum_required(VERSION 3.20)

project(Data-Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Data-Engine
     src/main.cpp 
     src/Event.cpp
     src/Filter.cpp
     src/Statistics.cpp
     src/Validate.cpp

)

#looks insides include folder
target_include_directories(Data-Engine PRIVATE include)


#setting up google test


# fetch google test from github automatically
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(DataEngineTests
    tests/FilterTest.cpp
    tests/StatisticsTest.cpp
    tests/ValidateTest.cpp
    src/Filter.cpp
    src/Statistics.cpp
    src/Validate.cpp

)

target_include_directories(DataEngineTests PRIVATE include)

target_link_libraries(DataEngineTests
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(DataEngineTests)


#Benchmarks

FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.9.4.zip
)

FetchContent_MakeAvailable(googlebenchmark)

add_executable(DataEngineBenchmarks
    benchmarks/DataEngineBenchmark.cpp
    src/Validate.cpp
    src/Event.cpp
    src/Filter.cpp
    src/Statistics.cpp

)

target_include_directories(DataEngineBenchmarks PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(DataEngineBenchmarks
    PRIVATE
    benchmark::benchmark
)


# AddressSanitizer

target_compile_options(Data-Engine PRIVATE
    -fsanitize=address
    -fno-omit-frame-pointer
)

target_link_options(Data-Engine PRIVATE
    -fsanitize=address

)