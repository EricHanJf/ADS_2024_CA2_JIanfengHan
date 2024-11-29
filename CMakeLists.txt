cmake_minimum_required(VERSION 3.29)
project(ADS_2024_CA2_Jianfeng_Han)

set(CMAKE_CXX_STANDARD 20)

add_executable(ADS_2024_CA2_Jianfeng_Han main.cpp
        Header/BinaryTree.h
        Header/BSTNode.h
        Header/TreeMap.h
        Header/Book.h)


include_directories(lib/googletest/googletest/include)
include_directories(Header)

add_subdirectory(lib/googletest)
#add_executable(${PROJECT_NAME}_run ${SOURCES}
#        Test/Test.cpp)

add_executable(runTests
        Test/Test.cpp
)

#add_executable(runTests
#        Test/Test.cpp
#        main.cpp)

target_link_libraries(runTests gtest gtest_main)