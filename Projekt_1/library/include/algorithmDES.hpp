#ifndef algorithmDES_hpp
#define algorithmDES_hpp

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

#include "BlockCreator.hpp"

using std::bitset;

enum Sides {leftSide, rightSide};

class DataEncryptionStandard : Block
{
private:
    uint64_t cryptogram;
    uint64_t key;
    bitset<64> temp;
    //bitset<64> permutationInitial_64_64();
    void paritySet();
    bool checkForWeakKey();

public:
    uint32_t split(Sides lr);
    DataEncryptionStandard(std::string plainText);
    void keyGen();
    uint64_t getKey(); // Delete this later!
    bitset<64> permutationInitial_64_64(); //Should be private
};


#endif //algorithmDES_hpp