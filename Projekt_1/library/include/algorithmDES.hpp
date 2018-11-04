#ifndef algorithmDES_hpp
#define algorithmDES_hpp

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

using std::bitset;

class DataEncryptionStandard
{
private:
    uint64_t block;
    uint64_t cryptogram;
    uint64_t key;
    bitset<64> temp;
    bitset<64> permutationInitial_64_64();
    void paritySet();

public:
    DataEncryptionStandard(int64_t mainBlock);
    void keyGen();
    uint64_t getKey(); // Delete this later!

};


#endif //algorithmDES_hpp