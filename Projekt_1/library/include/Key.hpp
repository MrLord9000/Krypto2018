#ifndef KEY_HPP
#define KEY_HPP

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>

using std::bitset;

class Key
{
protected:
    uint64_t key;
    Key();
private:
    void keyGen();
    void paritySet();
    bool checkForWeakKey();
};

#endif //KEY_HPP