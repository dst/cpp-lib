/*
 * stringlib.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: dst
 */

#include <algorithm>
#include <cassert>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::string;

inline bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == string::npos) {
        return false;
    }
    str.replace(start_pos, from.length(), to);
    return true;
}

inline void replaceAll(string& str, const string& from, const string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        // Move forward to protect against situation when
        // to' contains 'from', like replacing 'x' with 'yx'
        start_pos += to.length();
    }
}

inline bool startsWith(const string& str, const string& prefix) {
    if (str.size() < prefix.size()) {
        return false;
    }
    return str.compare(0, prefix.length(), prefix) == 0;
}

inline bool endsWith(const string& str, const string& sufix) {
    if (str.size() < sufix.size()) {
        return false;
    }
    return str.compare(str.size() - sufix.size(), sufix.size(), sufix) == 0;
}

inline std::vector<string> splitString(const string& str) {
    std::vector<string> tokens;
    std::istringstream iss(str);
    std::copy(std::istream_iterator<string>(iss),
            std::istream_iterator<string>(),
            std::back_inserter<std::vector<string> >(tokens));
    return tokens;
}

inline std::vector<int> string2ints(const string& str) {
    std::vector<int> numbers;
    std::istringstream is(str);
    int n;
    while (is >> n) {
        numbers.push_back(n);
    }
    return numbers;
}

inline bool contains(string str, char c) {
    return str.find_first_of(c) != string::npos;
}

inline int countChar(const string& str, char c) {
    return std::count(str.begin(), str.end(), c);
}

// tests
inline void stringlib() {
    assert(startsWith("a", "a"));
    assert(startsWith("abcd", "abc"));
    assert(!startsWith("abcd", "abe"));
    assert(!startsWith("abcd", "abcde"));

    assert(endsWith("a", "a"));
    assert(endsWith("abcd", "bcd"));
    assert(!endsWith("abcd", "bce"));
    assert(!endsWith("abcd", "abcde"));

    //splitString
    auto tokens = splitString("aaa bbb");
    assert(tokens[0] == "aaa");
    assert(tokens[1] == "bbb");

    //string2ints
    auto numbers = string2ints("1 2");
    assert(numbers[0] == 1);
    assert(numbers[1] == 2);
    
    //contains
    assert(contains("abcde", 'e'));
    assert(!contains("abcde", 'f'));

    //countChar
    assert(countChar("a_b_c", '_') == 2);
    assert(countChar("_abc", '_') == 1);
    assert(countChar("abc_", '_') == 1);
    assert(countChar("abc", '_') == 0);
    assert(countChar("", '_') == 0);
}
