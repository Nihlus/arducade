cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

set(PROJECT_NAME arducade)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "--std=gnu++14 -fno-threadsafe-statics")

set(${CMAKE_PROJECT_NAME}_SKETCH arducade.ino)
set(${CMAKE_PROJECT_NAME}_BOARD micro)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyACM0)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})