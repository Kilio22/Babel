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

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/client/src/*)
file(GLOB_RECURSE SRC_SERVER ${PROJECT_SOURCE_DIR}/server/src/*)

add_executable(babel_client ${SRC_CLIENT})
add_executable(babel_server ${SRC_SERVER})

include_directories(${CMAKE_INCLUDE_PATH})
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include)
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include/audio)
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include/commands)
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include/exceptions)
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include/gui)
target_include_directories(babel_client BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/client/include/network)
target_include_directories(babel_server BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/server/include)

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Network)
target_link_libraries(babel_server ${CONAN_LIBS})

file(COPY ${PROJECT_SOURCE_DIR}/client/assets/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/)
