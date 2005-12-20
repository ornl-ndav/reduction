/**
 * $Id$
 *
 * \file inc\nessi.hpp
 */

#ifndef _NESSI_H
#define _NESSI_H 1

#include <vector>

/**
 * This file contains the abstraction of std::vector to Nessi::Vector which 
 * eliminates explicit calls to std::vector. This allows easy swapping of 
 * std::vector for another container.
 */
namespace Nessi {

template <typename T>
class Vector : public std::vector<T>
{
public:
  Vector() : std::vector<T>() { }
  Vector(int i) : std::vector<T>(i) { }
};

}

#endif // _NESSI_H
