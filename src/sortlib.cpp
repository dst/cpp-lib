/*
 * sortlib.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: dst
 */

#include <algorithm>

using std::vector;

// sorting objects
class obj {};
inline bool comp(const obj& a, const obj& b) { // returns bool!
    // compare objects, return true if a should be before b, false otherwise
    return true; 
    
    /* Example (sort by name, then by age)
     * if (a.name.compare(b.name) == 0) {
     *     return a.age < b.age;
     * } else {
     *     return a.name.compare(b.name) < 0; // string::compare returns -1, 0 or 1
     * }
    */
}
inline void sortObjs(vector<obj>& objs) {
    sort(objs.begin(), objs.end(), comp);
}

// Sort array in descending order with reverse iterators
inline void reverseSort(vector<int>& v) {
    sort(v.rbegin(), v.rend());
}


inline void sort() {
    
}
