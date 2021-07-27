cmake_minimum_required(VERSION 3.0.0)
project(arena VERSION 0.1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include(CTest)
set(SOURCES src/arena.cpp src/board.cpp src/player.cpp src/creature.cpp)

enable_testing()

add_executable(arena ${SOURCES})
target_link_libraries(arena ${CURSES_LIBRARIES})
target_include_directories(arena PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
