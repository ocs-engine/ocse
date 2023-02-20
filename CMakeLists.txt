cmake_minimum_required(VERSION 3.25)
project(ocse C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(FETCHCONTENT_QUIET OFF)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z
    URL_HASH SHA256=86a1961606c433d15c5af55e1270d1d6d9afa770a243981e040f902c4c6ef154
)
if(NOT boost_POPULATED)
    FetchContent_Populate(boost)
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR} EXCLUDE_FROM_ALL SYSTEM)
endif()

add_library(ocse STATIC
    src/actions/actions.cpp
    src/actions/actions.h
    src/entities/Planet.cpp
    src/entities/Planet.h
    src/entities/User.cpp
    src/entities/User.h
)
target_include_directories(ocse PUBLIC src)

add_subdirectory(modules/database)
add_subdirectory(modules/http)
add_subdirectory(tests)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(ocse PUBLIC
        "-Weverything"
        "-Wno-c++98-compat"
        "-Wno-c++98-compat-pedantic"
        "-Wno-c++11-compat"
        "-Wno-c++11-compat-pedantic"
        "-Wno-c++14-compat"
        "-Wno-c++14-compat-pedantic"
        "-Wno-c++17-compat"
        "-Wno-c++17-compat-pedantic"
        "-Wno-c++20-compat"
        "-Wno-c++20-compat-pedantic"
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(ocse PUBLIC
        "-Wall"
        "-Wextra"
        "-Wpedantic"
        "-Wconversion"
    )
endif()

add_executable(ocse-exe src/main.cpp)
target_link_libraries(ocse-exe PRIVATE ocse)
