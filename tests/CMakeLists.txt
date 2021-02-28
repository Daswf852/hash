project(hash_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(hash_tests
        generic.hpp
        md.cpp
        sha1.cpp
        sha2.cpp
        )
target_link_libraries(hash_tests gtest gtest_main hash)
