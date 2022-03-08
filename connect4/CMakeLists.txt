cmake_minimum_required(VERSION 3.11)

project(connect4)

add_library(connect4 src/connect4.cpp)

# PUBLIC needed to make both .h and .cpp library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(connect4 PUBLIC cxx_std_11)
