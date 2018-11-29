#include <iostream>

#include "Des.hpp"

using namespace std;

int main()
{
    //Key keyTest;
    //keyTest.generateKeys();
    //Block blockTest;
    //cout << "PlainText:\t";
    //printBits(blockTest.currentBlock, 64, 4);
    //cout << "Initial Permutation:\t";
    //printBits(blockTest.initialPermutation(), 64, 4);

    Des testDes;
    testDes.encrypt();

}