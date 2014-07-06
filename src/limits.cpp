/*
 * limitslib
 *
 *  Created on: Nov 2, 2013
 *      Author: dst
 */

#include <cassert>
#include <limits>

inline int maxInt() {
    return std::numeric_limits<int>::max();
}

inline void limits() {
    assert(maxInt() > 999999999);
}
