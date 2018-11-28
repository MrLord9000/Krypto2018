#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Misc.hpp"

class Block
{
protected:
    uint64_t currentBlock = 0;
    Block(const char *plainText);
    uint64_t nextBlock();

private:
    const char *textPosPointer;

};

#endif //BlockCreator_hpp