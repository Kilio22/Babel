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
include_directories(${PROJECT_SOURCE_DIR}/client/include)
include_directories(${PROJECT_SOURCE_DIR}/server/include)

file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/client/src/*)
file(GLOB_RECURSE SRC_SERVER ${PROJECT_SOURCE_DIR}/server/src/*)

add_executable(server ${SRC_SERVER})
add_executable(client ${SRC_CLIENT})

target_link_libraries(server ${CONAN_LIBS})
target_link_libraries(client ${CONAN_LIBS} Qt5::Widgets)
