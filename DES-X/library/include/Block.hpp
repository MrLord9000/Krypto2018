#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Misc.hpp"

class Block
{
private:
    const char *textPosPointer;

protected:
    uint64_t currentBlock = 0;
    uint64_t initialPermutation();

public:
    Block(const char *plainText = nullptr);
    bool nextBlock();
    string getCurrentBlockStr(uint64_t input = 0);
    uint64_t getCurrentBlockInt();
};

#endif 
