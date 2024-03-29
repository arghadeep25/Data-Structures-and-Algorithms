cmake_minimum_required(VERSION 3.5)

project(cpp_practice VERSION 1.0 DESCRIPTION "Data Structure with CPP" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(SRC_DIR src)
set(INC_DIR include)

add_subdirectory("${CMAKE_SOURCE_DIR}/submodules/googletest" "submodules/googletest")

option(ENABLE_EXAMPLES "Enable examples" ${BUILD_EXAMPLE})
set(BUILD_EXAMPLE OFF)

if (ENABLE_EXAMPLES)
    message("Building examples.")
    add_library(cpp_practice INTERFACE)
    target_include_directories(cpp_practice INTERFACE ${INC_DIR})
    target_link_libraries(cpp_practice INTERFACE stdc++fs gtest)
    add_subdirectory(examples)
else ()
    message("Examples will not be built")
    FILE(GLOB SRC_FILES "src/*.cpp")
    FILE(GLOB INC_FILES "include/*.hpp")
    add_executable(cpp_practice ${SRC_FILES} ${INC_FILES})
    target_include_directories(cpp_practice PUBLIC ${INC_DIR})
    target_link_libraries(cpp_practice stdc++fs gtest)
endif ()


