/*
 * alglib.cpp
 *
 *  Created on: Feb 25, 2012
 *      Author: dst
 */

#include "common.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;


/* next_permutation
 * Don’t forget to ensure that the elements in a container are sorted before
 * your first call to next_permutation(...). Their initial state should form
 * the very first permutation; otherwise, some permutations will not be checked
 * 
 * Example:
 * do {
 * 
 * } while (next_permutation(v.begin(), v.end()));
 */

// add some elements to set
// vector<int> v; 
// set<int> s; 
// copy(v.begin(), v.end(), inserter(s, s.begin()));

// search first not equal adjacent elements, return iter to first of them
// 1 1 1 1 2 2 2 3
//       *
// vector<int> v;
// vector<int>::iterator eltIter = adjacent_find(v.begin(), v.end(), not_equal_to<int>());


inline void replaceElts(vector<int>& v, int oldVale, int newValue) {
    replace(v.begin(), v.end(), oldVale, newValue);
}

inline long long sum(const vector<int>& v) { 
    return accumulate(v.begin(), v.end(), 0LL);
}

inline long long product(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 1LL, multiplies<int>()); 
}

// Get rid of duplicates in vector and sort it
inline vector<int> removeDuplicates(const vector<int>& v) { 
    set<int> s(v.begin(), v.end()); 
    vector<int> sorted(s.begin(), s.end());
    return sorted;
}

// TODO: remove one/all elts from vector

// tests
inline void alg() {
    // replaceElts
    auto v = VECTOR(1, 2, 3);
    replaceElts(v, 1, 2);
    assert(count(v.begin(), v.end(), 1) == 0);
    assert(count(v.begin(), v.end(), 2) == 2);
    assert(count(v.begin(), v.end(), 3) == 1);

    //sum
    assert(sum(VECTOR(1, 2, 3, 4)) == 10);
    
    //product
    assert(product(VECTOR(1, 2, 3, 4)) == 24);

    // removeDuplicates
    auto duplicated = VECTOR(1, 1);
    auto uniq = removeDuplicates(duplicated);
    assert(count(uniq.begin(), uniq.end(), 1) == 1);
}
