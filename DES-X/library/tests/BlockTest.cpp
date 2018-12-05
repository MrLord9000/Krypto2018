#include <boost/test/unit_test.hpp>

#include "Block.hpp"

BOOST_AUTO_TEST_SUITE(BlockTest)

    BOOST_AUTO_TEST_CASE(cinBlockTest)
    {
        string testString = "To_jest_moj_tekst_testowy.";
        cout << "Test text: " << testString << "\n";
        Block testBlock(testString.c_str());
        testBlock.nextBlock();
        cout << "get Current block (str): " << testBlock.getCurrentBlockStr() << endl;
        cout << "get Current block (int): " << testBlock.getCurrentBlockInt() << endl;
        Block testBlock2(testString.c_str());
        cout << "LoopZoop:\n ";
        bool temp = true;
        do
        {
            temp = testBlock2.nextBlock();
            cout << testBlock2.getCurrentBlockStr();
        } while(!temp); 
    }

BOOST_AUTO_TEST_SUITE_END()