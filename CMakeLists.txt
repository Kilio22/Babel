project(Babel)

cmake_minimum_required(VERSION 2.8.12)

add_definitions("-fPIC")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${CMAKE_CURRENT_LIST_DIR}/server/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/client/include)

file(GLOB SRC_CLIENT ${CMAKE_CURRENT_LIST_DIR}/client/src/*)

file(GLOB SRC_SERVER ${CMAKE_CURRENT_LIST_DIR}/server/src/*)

add_executable(server ${SRC_SERVER})
add_executable(client ${SRC_CLIENT})

target_link_libraries(server ${CONAN_LIBS})
target_link_libraries(client ${CONAN_LIBS} Qt5::Widgets)
