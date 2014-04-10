/*
 * mathlib.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: dst
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

template<typename T> T gcd(T a, T b) {
    return b > 0 ? gcd(b, a % b) : a; 
}

inline bool isPow2(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

inline vector<int> getDigits(int n) {
    vector<int> digits;
    
    if (n == 0) {
        digits.push_back(0);
        return digits;
    }
    
    // Loop till there's nothing left
    while (n) { 
        int lastDigit = n % 10;
        digits.push_back(lastDigit);
        
        // Shift right the number
        n /= 10; 
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

//TODO n over k, prime numbers

// tests
inline void math() {
    //gcd
    assert(gcd(13, 7) == 1);
    assert(gcd(21, 6) == 3);
    assert(gcd(7, 21) == 7);
    
    // isPow2
    assert(isPow2(1));
    assert(isPow2(2));
    assert(isPow2(4));
    assert(isPow2(8));
    
    assert(!isPow2(-1));
    assert(!isPow2(0));
    assert(!isPow2(3));
    assert(!isPow2(5));
    assert(!isPow2(6));
    
    // getDigits
    vector<int> digits123 = getDigits(123);
    assert(digits123[0] == 1);
    assert(digits123[1] == 2);
    assert(digits123[2] == 3);
    
    vector<int> digits0 = getDigits(0);
    assert(digits0[0] == 0);
    
    // sqrt
    assert(sqrt(9) == 3);
    
    // power
    assert(pow(2, 10) == 1024);
    assert(pow10(3) == 1000);
}

