#ifndef DES_hpp
#define DES_hpp

#include <stdint.h>
#include <bitset>
#include <iostream>

#include "BlockCreator.hpp"
#include "Key.hpp"

using std::bitset;

enum Sides {leftSide, rightSide};
enum Component {textComp, keyComp};

class DES : Block , Key
{
private:
    bitset<64> temp;
    
    //bitset<64> permutationInitial_64_64();
    //uint64_t cryptogram; //Probably won't be nesessary as the main function will just return the cryptogram.
    uint32_t split(Sides side, Component comp);
    uint64_t permutationInitial_64_64();
    uint64_t permutedChoice_I_64_56();

public:
    DES(std::string plainText);
    
    
};


#endif //DES_hpp