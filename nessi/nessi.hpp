/**
 * $Id$
 *
 * \file nessi/nessi.hpp
 */

#ifndef _NESSI_HPP
#define _NESSI_HPP 1

#include <vector>

/**
 * This file contains the abstraction of std::vector to Nessi::Vector which 
 * eliminates explicit calls to std::vector. This allows easy swapping of 
 * std::vector for another container. 
 */
namespace Nessi 
{
  /**
   * \brief Provides wrapper for std::vector
   *
   * 
   */
template <typename T>
class Vector : public std::vector<T>
{
public:
  /**
   * \brief Constructor for empty Vector
   *
   * This provides a constructor method for an empty Vector
   */
  Vector() : std::vector<T>() { }
  /**
   * \brief Constructor for Vector of size i
   *
   * This provides a constructor method for Vector of size i
   *
   * \param i is the size of the desired Vector
   */
  Vector(int i) : std::vector<T>(i) { }
};

} // Nessi

#endif // _NESSI_HPP
