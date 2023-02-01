cmake_minimum_required(VERSION 3.24)
project(ocse C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(FETCHCONTENT_QUIET OFF)

find_package(Boost REQUIRED)

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

target_link_libraries(ocse PRIVATE Boost::boost)

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

add_executable(ocse-exe src/main.cpp)
target_link_libraries(ocse-exe PRIVATE ocse)
