project(Babel LANGUAGES CXX)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# QT
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CXX STANDARD
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${PROJECT_SOURCE_DIR}/client/include)
include_directories(${PROJECT_SOURCE_DIR}/client/include/audio)
include_directories(${PROJECT_SOURCE_DIR}/client/include/exceptions)
include_directories(${PROJECT_SOURCE_DIR}/server/include)

file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/client/src/*)
file(GLOB_RECURSE SRC_SERVER ${PROJECT_SOURCE_DIR}/server/src/*)

add_executable(client ${SRC_CLIENT})
add_executable(server ${SRC_SERVER})

target_link_libraries(client ${CONAN_LIBS} Qt5::Widgets)
target_link_libraries(server ${CONAN_LIBS})
