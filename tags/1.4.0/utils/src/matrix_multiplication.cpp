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
 * \file utils/src/matrix_multiplication.cpp
 */
#include "matrix_multiplication.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.37.
   *
   * \ingroup matrix_multiplication
   */
  template std::string
  matrix_multiplication<float>(const Nessi::Vector<float> & input,
                               const Nessi::Vector<float> & input_err2,
                               Nessi::Vector<float> & output,
                               Nessi::Vector<float> & output_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.37.
   *
   * \ingroup matrix_multiplication
   */
  template std::string
  matrix_multiplication<double>(const Nessi::Vector<double> & input,
                                const Nessi::Vector<double> & input_err2,
                                Nessi::Vector<double> & output,
                                Nessi::Vector<double> & output_err2,
                                void *temp);

  /**
   * This is the integer declaration of the function defined in 3.37.
   *
   * \ingroup matrix_multiplication
   */
  template std::string
  matrix_multiplication<int>(const Nessi::Vector<int> & input,
                             const Nessi::Vector<int> & input_err2,
                             Nessi::Vector<int> & output,
                             Nessi::Vector<int> & output_err2,
                             void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.37.
   *
   * \ingroup matrix_multiplication
   */
  template std::string
  matrix_multiplication<unsigned int>(
                                const Nessi::Vector<unsigned int> & input,
                                const Nessi::Vector<unsigned int> & input_err2,
                                Nessi::Vector<unsigned int> & output,
                                Nessi::Vector<unsigned int> & output_err2,
                                void *temp);

} // AxisManip
