cmake_minimum_required(VERSION 3.16)

project(game_project LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(game_project
    main.cpp
    repository/dao/AccountDAO.cpp
	repository/dao/GameDAO.cpp
	repository/dao/ReviewDAO.cpp
	repository/dao/DAO.cpp
    lib/sqlite3.c
)

target_include_directories(game_project PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/repository
    ${CMAKE_CURRENT_SOURCE_DIR}/repository/dao
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

if (WIN32)
    target_link_libraries(game_project PRIVATE ws2_32)
endif()

add_custom_command(TARGET game_project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/create.sql
        $<TARGET_FILE_DIR:game_project>/create.sql
)