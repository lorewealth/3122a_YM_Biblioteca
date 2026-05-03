cmake_minimum_required(VERSION 3.15)
project(Biblioteca_YM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TARGET_NAME "3122a_YM_Biblioteca")

file(GLOB_RECURSE SOURCES "src/*.cpp" "lib/*.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/SQLite/sqlite3.c")

file(GLOB_RECURSE ALL_HEADERS "src/*.hpp" "src/*.h" "lib/*.hpp" "lib/*.h")
foreach(header_file ${ALL_HEADERS})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${header_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(${TARGET_NAME} ${SOURCES})

target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)

target_include_directories(${TARGET_NAME} PRIVATE
    ${INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
)

find_package(OpenSSL REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE pthread dl OpenSSL::Crypto argon2)

add_custom_target(run
    DEPENDS ${TARGET_NAME}
    COMMAND "$<TARGET_FILE:${TARGET_NAME}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Se incepe lucru..."
    VERBATIM
)
