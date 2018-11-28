#include <boost/test/unit_test.hpp>

#include "Key.hpp"

BOOST_AUTO_TEST_SUITE(KeyTest)

    BOOST_AUTO_TEST_CASE(KeyGenTest)
    {
        Key testKey;
        BOOST_REQUIRE_EQUAL(testKey.baseKey, 0x133457799BBCDFF1);
        uint64_t tempKey = testKey.permutedChoiceI();
        BOOST_REQUIRE_EQUAL(tempKey, 0xF0CCAAF556678F);
        uint32_t rightKey = static_cast<uint32_t>(tempKey) & 0xfffffff;
        uint32_t leftKey = static_cast<uint32_t>(tempKey >> 28) & 0xfffffff;
        BOOST_REQUIRE_EQUAL(rightKey, 0x556678F);
        BOOST_REQUIRE_EQUAL(leftKey, 0xF0CCAAF);
        
        const uint32_t shiftedKeys[] = {0xE19955F, 0xAACCF1E, 0xC332ABF, 0x5599E3D,
                                         0xCCAAFF, 0x56678F5, 0x332ABFC, 0x599E3D5, 0xCCAAFF0, 0x6678F55,
                                        0x32ABFC3, 0x99E3D55, 0xCAAFF0C, 0x678F556, 0x2ABFC33, 0x9E3D559,
                                        0x557F866, 0x3C7AAB3, 0x55FE199, 0xF1EAACC, 0x57F8665, 0xC7AAB33,
                                        0x5FE1995, 0x1EAACCF, 0x7F86655, 0x7AAB33C, 0xFE19955, 0xEAACCF1,
                                        0xF866557, 0xAAB33C7, 0xF0CCAAF, 0x556678F};
        uint32_t tempLeft = testKey.leftCircularShift(leftKey, 0), tempRight = testKey.leftCircularShift(rightKey, 0);
        for(int i = 1, j = 0; i < 16; i++, j += 2)
        {
            BOOST_REQUIRE_EQUAL(tempLeft, shiftedKeys[j]);
            BOOST_REQUIRE_EQUAL(tempRight, shiftedKeys[j + 1]);
            tempLeft = testKey.leftCircularShift(tempLeft, i);
            tempRight = testKey.leftCircularShift(tempRight, i);
        }
    }

BOOST_AUTO_TEST_SUITE_END()