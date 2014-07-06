/*
 * bitlib.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: dst
 */

#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

using std::bitset;

inline void bit() {
    // bitset
    bitset<10> empty;
    assert(empty[0] == false);
    assert(empty[9] == false);
    
    // initialize from string
    bitset<10> second("01011");
    // second is 0000001011
    assert(second.to_ulong() == 11);

    // bitset stores bits in reverse order
    bitset<4> bits;         // 0000
    assert(bits.to_ulong() == 0);
    bits[1]= 1;           // 0010
    assert(bits.to_ulong() == 2);
    bits[2]= 1;           // 0110
    assert(bits.to_ulong() == 6);
    
    // bit operations
    assert(1 << 20 == 1024 * 1024);
}
