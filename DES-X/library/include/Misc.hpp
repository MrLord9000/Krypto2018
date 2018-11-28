#ifndef MISC_HPP
#define MISC_HPP

#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;

void printBits(uint64_t input, short bits, short groups = 8);
int inv(unsigned short input, unsigned short bitsSize = 64);

#endif