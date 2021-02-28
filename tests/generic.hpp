#pragma once

#include "gtest/gtest.h"

#include <chrono>
#include <vector>

#include "hash/digest.hpp"

inline void GeneralVectors(Hash::Digest &&digest, const std::vector<std::string> &expected) {
    const std::vector<std::string> strings{
            {"abc"},
            {""},
            {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"},
            {"abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu"},
    };

    for (std::size_t i = 0; i < strings.size(); i++) {
        digest.Update(strings.at(i));
        ASSERT_EQ(digest.Final(), expected.at(i));
    }
}

inline void BigVectors(Hash::Digest &&digest, const std::vector<std::string> &expected) {
    std::vector<uint8_t> vec(1000, 0x61U);
    for (std::size_t i = 0; i < 1000; i++)
        digest.Update({vec.data(), vec.size()});

    ASSERT_EQ(digest.Final(), expected.at(0));

    std::string message{"abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno"};
    for (std::size_t i = 0; i < 16777216; i++)
        digest.Update(message);

    ASSERT_EQ(digest.Final(), expected.at(1));
}

inline void Speed(Hash::Digest &&digest, const std::string &algo) {
    std::vector<uint8_t> vec;
    (void) std::fill_n(std::back_inserter(vec), 1024 * 1024, 'A'); //1MiB

    auto tp0 = std::chrono::system_clock::now();

    std::size_t processedBlocks = 0;
    for (;; processedBlocks++) {
        digest.Update({vec.data(), vec.size()});

        auto tp1 = std::chrono::system_clock::now();
        auto dur = tp1 - tp0;
        auto passedMs = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        if (passedMs >= 1500)
            break;
    }

    auto tp1 = std::chrono::system_clock::now();
    auto dur = tp1 - tp0;
    auto passedMs = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::size_t MiBsHashed = processedBlocks * vec.size() / (1024 * 1024);
    std::cout << algo << ": Digested " << MiBsHashed << "MiBs in " << passedMs << "ms" << std::endl;
    std::cout << "That makes " << (static_cast<double>(MiBsHashed) / 1024.) / (static_cast<double>(passedMs) / 1000.) << "GiB/s";

}
