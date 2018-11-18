#ifndef BlockCreator_hpp
#define BlockCreator_hpp

#include <stdint.h>

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