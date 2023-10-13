cmake_minimum_required(VERSION 3.27)
set(CMAKE_TOOLCHAIN_FILE $ENV{CONG_CMAKE_TOOLCHAIN})
set(CMAKE_PREFIX_PATH vcpkg/installed/x64-linux)

project(Cong)

find_package(raylib CONFIG REQUIRED)

add_subdirectory(Cong)
