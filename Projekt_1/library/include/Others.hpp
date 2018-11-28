#ifndef OTHERS_HPP
#define OTHERS_HPP

#include <stdint.h>
#include <iostream>
#include <bitset>

using namespace std;

enum Sides {leftSide, rightSide};
enum Component {textComp, keyComp};

uint32_t split(Sides side, Component comp, uint64_t input);
void bit_cout(uint64_t input, short bits);

#endif