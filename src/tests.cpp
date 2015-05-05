/*
 * tests
 *
 *  Created on: Apr 1, 2012
 *      Author: dst
 */

// Let's assume that nobody will see it, including me:
#include "alg.cpp"
#include "bit.cpp"
#include "col.cpp"
#include "graph.h"
#include "limits.cpp"
#include "math.cpp"
#include "sort.cpp"
#include "str.cpp"

#include <iostream>

// tests
int main() {
    std::cout << "Running tests..." << std::endl;
    
    alg();
    bit();
    col();
    graph();
    limits();
    math();
    sort();
    str();
    
    std::cout << "Tests finished" << std::endl;
    return 0;
}
