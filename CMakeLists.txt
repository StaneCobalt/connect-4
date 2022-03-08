# version 3.11 or later of CMake needed for installing GoogleTest
cmake_minimum_required(VERSION 3.11)

# look in subdirectory for CMakeLists.txt to process
add_subdirectory(connect4)

add_executable(main main.cpp)

target_link_libraries (
    main
    PRIVATE connect4
)

target_compile_features(main PUBLIC cxx_std_11)
