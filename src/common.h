/*
 * common.h
 *
 *  Created on: Nov 2, 2013
 *      Author: dst
 */

#ifndef COMMON_H_
#define COMMON_H_

#define VECTOR(first,...) \
   ([](){ \
   std::vector<decltype(first)> v = { first,__VA_ARGS__ }; \
   return v;})()

#endif /* COMMON_H_ */
