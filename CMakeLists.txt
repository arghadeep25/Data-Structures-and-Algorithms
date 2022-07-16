cmake_minimum_required(VERSION 3.15)

project(cpp_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(SRC_DIR src)
set(INC_DIR include)

add_subdirectory("${CMAKE_SOURCE_DIR}/submodules/googletest" "submodules/googletest")

set(BUILD_EXAMPLE OFF)

option(ENABLE_EXAMPLES "Enable examples" ${BUILD_EXAMPLE})

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


