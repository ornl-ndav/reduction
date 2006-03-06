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
 * \file utils/inc/num_comparison.hpp
 */
#ifndef _NUM_COMPARISON_HPP
#define _NUM_COMPARISON_HPP 1

#include "nessi.hpp"

/**
 * \namespace Utils
 */
namespace Utils
{
  /**
   * \defgroup compare Utils::compare
   * \{
   */

  /**
   * \brief This function compares two numbers and returns 0 (eq), 1 (gt) or
   * -1 (lt).
   *
   * This function takes two numbers on compares them. The function returns
   * 0 is the two numbers are equal, 1 if the first number is larger than the
   * second number, and -1 if the first number is smaller than the second
   * number.
   *
   * \param value1 (INPUT) is the first number to be compared
   * \param value2 (INPUT) is the second number to be compared
   *
   * \return 0 (eq), 1 (gt) or -1 (lt)
   */
  template <typename NumT>
  int
  compare(const NumT & value1,
          const NumT & value2);

  int compare(const float & value1,
              const float & value2);

  int compare(const double & value1,
              const double & value2);
  /**
   * \}
   */ // end of compare group

  /**
   * \defgroup vector_comparison Utils::vector_comparison
   * \{
   */

  /**
   * \brief This function compares to vectors for equality.
   *
   * This function takes two vectors and checks equality on an
   * element-by-element basis. One of the vectors contains the truth values
   * from a given calculation. The function also takes an error parameter that
   * is used to add the provided error code if element-by-element equality is
   * violated.
   *
   * \param value (INPUT) is a calculated vector
   * \param true_value (INPUT) is a truth vector corresponding to the
   * calculated vector
   * \param error (INPUT/OUTPUT) is a holder for adding an error code
   * \param add_error (INPUT) is the provided error code
   */
  template <typename NumT>
  void
  vector_comparison(const Nessi::Vector<NumT> & value,
                    const Nessi::Vector<NumT> & true_value,
                    int & error,
                    const int add_error);
  /**
   * \}
   */ // end of vector_comparison group

  /**
   * \defgroup vector_is_equals Utils::vector_is_equals
   * \{
   */

  /**
   * \brief This function compares to vectors for equality.
   *
   * This function takes two vectors and checks equality on an
   * element-by-element basis. One of the vectors contains the truth values
   * from a given calculation.
   *
   * \param value (INPUT) is a calculated vector
   * \param true_value (INPUT) is a truth vector corresponding to the
   * calculated vector
   *
   * \return A boolean that is true if the vector is equal element-by-element
   */
  template <typename NumT>
  bool
  vector_is_equals(const Nessi::Vector<NumT> & value,
                   const Nessi::Vector<NumT> & true_value);

  /**
   * \}
   */ // end of vector_is_equals group

}

#endif // _NUM_COMPARISON_HPP
