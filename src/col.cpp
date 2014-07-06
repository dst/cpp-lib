/*
 * Collection library
 *
 *  Created on: Apr 13, 2014
 *      Author: dst
 */

#include <cassert>
#include <map>
#include <string>

using std::map;
using std::multimap;
using std::string;

inline void col() {
    // map iterating
    map<string, int> ages;
    ages["John"] = 99;
    for(auto it = ages.begin(); it != ages.end(); it++) {
         string name = it->first;
         int age = it->second;

         assert(name == "John");
         assert(age == 99);
    }
}
