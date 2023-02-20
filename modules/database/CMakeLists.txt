include(FetchContent)

FetchContent_Declare(
    sql-builder
    GIT_REPOSITORY https://github.com/six-ddc/sql-builder.git
    GIT_TAG efd9bea42162a0e0ab06e7d45c537ac6a02cc10d
)
FetchContent_Populate(sql-builder)
FetchContent_GetProperties(sql-builder SOURCE_DIR sql_builder_source_dir)
add_library(sql_builder INTERFACE IMPORTED GLOBAL)
add_library(sql_builder::sql_builder ALIAS sql_builder)
target_include_directories(sql_builder INTERFACE ${sql_builder_source_dir})

FetchContent_Declare(
    libpqxx
    GIT_REPOSITORY https://github.com/jtv/libpqxx.git
    GIT_TAG 197b61d16784d2c3e28cdd064d4f23b97e0af59f
)
if (NOT libpqxx_POPULATED)
    FetchContent_Populate(libpqxx)
    block()
        set(SKIP_BUILD_TEST ON)
        add_subdirectory(${libpqxx_SOURCE_DIR} ${libpqxx_BINARY_DIR} SYSTEM)
    endblock()
    add_library(libpqxx::pqxx ALIAS pqxx)
endif()

target_link_libraries(ocse PRIVATE
    libpqxx::pqxx
    sql_builder::sql_builder
)
