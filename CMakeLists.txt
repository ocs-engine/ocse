cmake_minimum_required(VERSION 3.24)
project(ocse C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(FETCHCONTENT_QUIET OFF)

# find_package(Boost REQUIRED)

include(FetchContent)
FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z
    # URL_HASH SHA256=6e689b266b27d4db57f648b1e5c905c8acd6716b46716a12f6fc73fc80af842e
)
if(NOT boost_POPULATED)
    FetchContent_Populate(boost)
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR} EXCLUDE_FROM_ALL SYSTEM)
endif()

add_library(ocse STATIC)
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
