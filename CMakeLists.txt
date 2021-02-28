cmake_minimum_required(VERSION 3.17)
project(hash)

set(CMAKE_CXX_STANDARD 20)

set(HASH_LIB_HEADERS
        lib/hash/digest.hpp
        lib/hash/md5.hpp
        lib/hash/sha1.hpp
        lib/hash/sha2.hpp
        )

add_library(hash INTERFACE)
target_include_directories(hash INTERFACE ./lib)

add_subdirectory(tests)

