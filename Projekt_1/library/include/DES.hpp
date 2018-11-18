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
    uint8_t roundCount = 0;
    int32_t lText;
    int32_t rText;
    int32_t lKey;
    int32_t rKey;
    //uint64_t cryptogram; //Probably won't be nesessary as the main function will just return the cryptogram.
    uint32_t split(Sides side, Component comp);
    uint32_t leftCircularShift(uint32_t key28bit);
    uint64_t permutationInitial_64_64();
    uint64_t permutedChoice_I_64_56();
    uint64_t permutedChoice_II_28_28_48();
    uint64_t expansionPermutation_32_48();
    uint32_t S_boxes(uint64_t input);
    uint8_t  S_box(bitset<6> input);
    void round();
public:
    DES(std::string plainText);
    void encrypt();
    
};


#endif //DES_hpp