#include "gtest/gtest.h"

#include "hash/md5.hpp"
#include "generic.hpp"

TEST(MD5Tests, generalVectors) {
    GeneralVectors(Hash::Md5(), {
            "900150983cd24fb0d6963f7d28e17f72",
            "d41d8cd98f00b204e9800998ecf8427e",
            "8215ef0796a20bcaaae116d3876c664a",
            "03dd8807a93175fb062dfb55dc7d359c",
    });
}

TEST(MD5Tests, bigVectors) {
    BigVectors(Hash::Md5(), {
            "7707d6ae4e027c70eea2a935c2296f21",
            "d338139169d50f55526194c790ec0448",
    });
}

TEST(MD5Tests, speed) {
    Speed(Hash::Md5(), "MD5");
}
