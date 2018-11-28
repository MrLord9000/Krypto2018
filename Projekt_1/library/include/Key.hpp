#ifndef KEY_HPP
#define KEY_HPP

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <vector>

#include "Others.hpp"

using std::bitset;
using std::vector;

using namespace std;

unsigned short convBE(unsigned short input, unsigned short bits);

struct SplitKey{ uint32_t left; uint32_t right; };

class Key
{
//private:
public:
    uint64_t baseKey;
    SplitKey keySides; 
    vector<uint64_t> keys;

    Key();
    void generateKeys();
    void split();
    uint64_t permutedChoice_I_64_56();
    uint64_t permutedChoice_II_28_28_48();

    void keyGen();
    void paritySet();
    bool checkForWeakKey();

};

#endif //KEY_HPP