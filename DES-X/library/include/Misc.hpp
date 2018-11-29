#ifndef MISC_HPP
#define MISC_HPP

#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;

void printBits(uint64_t input, short bits = 64, short groups = 8);
int inv(unsigned short input, unsigned short bitsSize = 64);

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif //WIN32

void cls();
void wait(unsigned int timeInMs);
void UTF_8();

#endif