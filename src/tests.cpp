/*
 * tests
 *
 *  Created on: Apr 1, 2012
 *      Author: dst
 */

// Let's assume that nobody will see it, including me:
#include "alglib.cpp"
#include "bitlib.cpp"
#include "graphlib.h"
#include "limitslib.cpp"
#include "mathlib.cpp"
#include "sortlib.cpp"
#include "stringlib.cpp"

#include <iostream>

// tests
int main() {
    std::cout << "Running tests..." << std::endl;
    
    alg();
    bit();
    graph();
    limits();
    math();
    sort();
    stringlib();
    
    std::cout << "Tests finished" << std::endl;
    return 0;
}
