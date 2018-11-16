#ifndef algorithmDES_hpp
#define algorithmDES_hpp

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

#include "BlockCreator.hpp"

using std::bitset;

class DataEncryptionStandard : Block
{
private:
    uint64_t cryptogram;
    uint64_t key;
    bitset<64> temp;
    //bitset<64> permutationInitial_64_64();
    void paritySet();
    void checkForWeakKey();

public:
    DataEncryptionStandard(std::string plainText);
    void keyGen();
    uint64_t getKey(); // Delete this later!
    bitset<64> permutationInitial_64_64(); //Should be private
};


#endif //algorithmDES_hpp