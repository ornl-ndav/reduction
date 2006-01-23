/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 * 
 * For this software and its associated documentation, permission is granted 
 * to reproduce, prepare derivative works, and distribute copies to the public 
 * for any purpose and without fee.
 *  
 * This material was prepared as an account of work sponsored by an agency of 
 * the United States Government.  Neither the United States Government nor the 
 * United States Department of Energy, nor any of their employees, makes any 
 * warranty, express or implied, or assumes any legal liability or 
 * responsibility for the accuracy, completeness, or usefulness of any 
 * information, apparatus, product, or process disclosed, or represents that 
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file nessi/inc/nessi.hpp
 */

#ifndef _NESSI_HPP
#define _NESSI_HPP 1

#include <vector>

/**
 * \namespace Nessi
 *
 * \brief A generic data object that is fundamental to all functions
 * in the library.
 *
 * This file contains the abstraction of std::vector to Nessi::Vector which
 * eliminates explicit calls to std::vector. This allows easy swapping of
 * std::vector for another container.
 */
namespace Nessi
{
  /**
   * \brief Provides wrapper for std::vector
   *
   * \defgroup nessivector Nessi::Vector
   * \{
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

  /**
   * \}
   */

} // Nessi

#endif // _NESSI_HPP
