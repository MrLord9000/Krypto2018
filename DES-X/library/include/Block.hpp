#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Misc.hpp"

class Block
{
public:
//protected:
    uint64_t currentBlock = 0;
    Block(const char *plainText = nullptr);
    uint64_t nextBlock();

//private:
    uint64_t initialPermutation();
    const char *textPosPointer;

};

#endif 