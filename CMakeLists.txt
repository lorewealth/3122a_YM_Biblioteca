cmake_minimum_required(VERSION 3.15)
project(Biblioteca_YM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES "src/*.cpp" "lib/*.cpp")

file(GLOB_RECURSE ALL_HEADERS "src/*.hpp" "src/*.h" "lib/*.hpp" "lib/*.h")
foreach(header_file ${ALL_HEADERS})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${header_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

if(WIN32)
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/bin-windows")
    set(TARGET_NAME "3122a_YM_Biblioteca")
    set(EXTRA_LIBS opengl32)

    set(ENV{PATH} "${SFML_LIB_DIR};$ENV{PATH}")
else()
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/bin-linux")
    set(TARGET_NAME "3122a_YM_Biblioteca")
    set(EXTRA_LIBS GL)

    set(CMAKE_BUILD_RPATH ${SFML_LIB_DIR})
    set(CMAKE_INSTALL_RPATH ${SFML_LIB_DIR})
endif()

add_executable(${TARGET_NAME} ${SOURCES})

target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)

target_include_directories(${TARGET_NAME} PRIVATE
    ${INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/include"
)

target_link_directories(${TARGET_NAME} PRIVATE ${SFML_LIB_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    ${EXTRA_LIBS}
)

add_custom_target(run
    DEPENDS ${TARGET_NAME}

    COMMAND ${CMAKE_COMMAND} -E env
            "LD_LIBRARY_PATH=${SFML_LIB_DIR}:$ENV{LD_LIBRARY_PATH}"
            "$<TARGET_FILE:${TARGET_NAME}>"

    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}

    COMMENT "Se incepe lucru..."
    VERBATIM
)
