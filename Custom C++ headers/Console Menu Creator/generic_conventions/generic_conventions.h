#ifndef GENERIC_CONVENTIONS_H_INCLUDED
#define GENERIC_CONVENTIONS_H_INCLUDED

#include <cstdlib>

/// Types

typedef short              int16_t;
typedef unsigned short     uint16_t;
typedef int                int32_t;
typedef unsigned           uint32_t;
typedef long long          int64_t;
typedef unsigned long long uint64_t;

/// Compares

namespace check{

template <class T>
bool isEqual(T a, T b){
	return a == b;
}

template <class T>
bool isNotEqual(T a, T b){
	return a != b;
}

template <class T>
bool isNull(T a){
	return a == nullptr;
}

template <class T>
bool isNotNull(T a){
	return a != nullptr;
}

template <class T>
bool isLesser(T a, T b){
	return a < b;
}

template <class T>
bool isGreater(T a, T b){
	return a > b;
}

template <class T>
bool isLesserOrEqual(T a, T b){
	return a <= b;
}

template <class T>
bool isGreaterOrEqual(T a, T b){
	return a >= b;
}

}   /// End of namespace


#endif /// GENERIC_CONVENTIONS_H_INCLUDED
