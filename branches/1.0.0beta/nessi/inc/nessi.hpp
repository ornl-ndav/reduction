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
   * \defgroup nessivector Nessi::Vector
   * \{
   *
   * \section nessi-vector-required Required Functions
   *
   * To implement a Nessi::Vector one must implement the following
   * functions in addition to those explicitly defined in the class
   * already. They are not enumerated in the interface because they are
   * inherited from std::vector.
   *
   * \code
   * size_t size();
   * \endcode
   * This returns the number of elements currently contained in the
   * Nessi::Vector.
   *
   * \code
   * forward_iterator begin();
   * \endcode
   * Returns a read/write iterator that points to the first element in
   * the Nessi::Vector. Iteration is done in ordinary element order.
   *
   * \code
   * forward_iterator end();
   * \endcode
   * Returns a read/write iterator that points one past the last
   * element in the Nessi::Vector. Iteration is done in ordinary
   * element order.
   *
   * \code
   * reference operator[](size_t i);
   * \endcode
   * Subscript access to the data contained in the Nessi::Vector. The
   * parameter \p i is the index of the element for which data should
   * be accessed. The function returns a read/write reference to data.
   *
   * This operator allows for easy, array-style, data access. Note
   * that data access with this operator is unchecked and \p
   * out_of_range lookups are not defined.
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

    /**
     * \brief Copy Constructor for Vector
     *
     * This provides a copy constructor method for Vector
     *
     * \param a is the Vector to be copied 
     */
    Vector(const Vector<T> &a) : std::vector<T>(a.begin(), a.end()) { }
  };

  /**
   * \}
   */

} // Nessi

#endif // _NESSI_HPP
