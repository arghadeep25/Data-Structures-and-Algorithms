set(examples_cpp
        singly_linked_list
        )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

message(STATUS "CMake Source Dir: ${CMAKE_SOURCE_DIR}")
foreach (example IN LISTS examples_cpp)
    add_executable(${example} ${CMAKE_SOURCE_DIR}/examples/${example}.cpp)
    target_link_libraries(${example} PUBLIC cpp_practice gtest)
endforeach ()
