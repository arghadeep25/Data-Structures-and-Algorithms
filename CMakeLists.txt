cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project (cpp_practice)

set(SRC_DIR src)
set(INC_DIR include)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

FILE(GLOB SRC_FILES "src/*.cpp")
FILE(GLOB INC_FILES "include/*.hpp")

add_executable(cpp_practice ${SRC_FILES} ${INC_FILES})
target_include_directories(cpp_practice PUBLIC ${INC_DIR})
target_link_libraries(cpp_practice stdc++fs )


