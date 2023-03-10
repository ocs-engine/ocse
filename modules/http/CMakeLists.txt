find_package(Threads REQUIRED)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)

include(FetchContent)

FetchContent_Declare(
    lithium
    GIT_REPOSITORY https://github.com/matt-42/lithium.git
    GIT_TAG 9ce90b1f96405bd2aced0d75fc2e9e49ea9a3fdd
    GIT_SUBMODULES ""
)
FetchContent_Populate(lithium)
FetchContent_GetProperties(lithium SOURCE_DIR lithium_source_dir)
add_library(lithium-lithium INTERFACE IMPORTED GLOBAL)
add_library(lithium::lithium ALIAS lithium-lithium)
target_include_directories(lithium-lithium SYSTEM INTERFACE
    ${lithium_source_dir}/single_headers
)

target_link_libraries(lithium-lithium INTERFACE
    Boost::context
    Boost::lexical_cast
    CURL::libcurl
    OpenSSL::SSL
    Threads::Threads
)

add_executable(ocse-http)
target_sources(ocse-http PRIVATE
    kernel.h
    kernel.cpp
    main.cpp
    controllers/Home.h
    controllers/Home.cpp
    routes/entrypoint.h
    routes/entrypoint.cpp
)

target_include_directories(ocse-http PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ocse-http PRIVATE
    Boost::json
    lithium::lithium
    ocse
)
