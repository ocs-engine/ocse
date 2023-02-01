cmake_minimum_required(VERSION 3.24)
project(ocse C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(FETCHCONTENT_QUIET OFF)

find_package(Boost REQUIRED)

add_executable(ocse
    src/main.cpp
)

add_subdirectory(modules/database)
add_subdirectory(modules/http)

target_link_libraries(ocse PRIVATE
    Boost::boost
)

target_compile_options(ocse PRIVATE
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
