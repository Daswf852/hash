#include "gtest/gtest.h"

#include "hash/sha1.hpp"
#include "generic.hpp"

TEST(SHA1Tests, generalVectors) {
    GeneralVectors(Hash::Sha1(), {
            "a9993e364706816aba3e25717850c26c9cd0d89d",
            "da39a3ee5e6b4b0d3255bfef95601890afd80709",
            "84983e441c3bd26ebaae4aa1f95129e5e54670f1",
            "a49b2446a02c645bf419f995b67091253a04a259",
    });
}

TEST(SHA1Tests, bigVectors) {
    BigVectors(Hash::Sha1(), {
            "34aa973cd4c4daa4f61eeb2bdbad27316534016f",
            "7789f0c9ef7bfc40d93311143dfbe69e2017f592",
    });
}

TEST(SHA1Tests, speed) {
    Speed(Hash::Sha1(), "Sha1");
}
