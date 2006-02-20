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
 * \brief Generic features that are fundamental to all functions in the 
 * library.
 *
 * The features contained in this namespace have influence on all functions 
 * provided in the SNS common libraries. One feature is the use of global 
 * abstraction (Nessi::Vector) for the underlying data container, which in 
 * this case is currently std::vector. The other feature is an empty warning 
 * string that functions return when no warnings are generated.
 */
namespace Nessi
{
  /**
   * \brief Provides wrapper for std::vector
   * 
   * This file contains the abstraction of std::vector to Nessi::Vector which
   * eliminates explicit calls to std::vector. This allows easy swapping of
   * std::vector for another container.
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
