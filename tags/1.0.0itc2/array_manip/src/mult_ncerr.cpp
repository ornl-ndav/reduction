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
 * \file array_manip/src/mult_ncerr.cpp
 */
#include "mult_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.3.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<float>(const Nessi::Vector<float> & array_in,
                    const Nessi::Vector<float> & array_in_err2,
                    const float scalar,
                    const float scalar_err2,
                    Nessi::Vector<float> & array_out,
                    Nessi::Vector<float> & array_out_err2,
                    void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.3.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<double>(const Nessi::Vector<double> & array_in,
                     const Nessi::Vector<double> & array_in_err2,
                     const double scalar,
                     const double scalar_err2,
                     Nessi::Vector<double> & array_out,
                     Nessi::Vector<double> & array_out_err2,
                     void *temp);

  /**
   * This is the integer declaration of the function defined in 3.3.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<int>(const Nessi::Vector<int> & array_in,
                  const Nessi::Vector<int> & array_in_err2,
                  const int scalar,
                  const int scalar_err2,
                  Nessi::Vector<int> & array_out,
                  Nessi::Vector<int> & array_out_err2,
                  void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.3.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<unsigned int>(const Nessi::Vector<unsigned int> & array_in,
                           const Nessi::Vector<unsigned int> & array_in_err2,
                           const unsigned int scalar,
                           const unsigned int scalar_err2,
                           Nessi::Vector<unsigned int> & array_out,
                           Nessi::Vector<unsigned int> & array_out_err2,
                           void *temp);

  /**
   * This is the float declaration of the function defined in 3.8.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<float>(const Nessi::Vector<float> & input1,
                    const Nessi::Vector<float> & input1_err2,
                    const Nessi::Vector<float> & input2,
                    const Nessi::Vector<float> & input2_err2,
                    Nessi::Vector<float> & output,
                    Nessi::Vector<float> & output_err2,
                    void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.8.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<double>(const Nessi::Vector<double> & input1,
                     const Nessi::Vector<double> & input1_err2,
                     const Nessi::Vector<double> & input2,
                     const Nessi::Vector<double> & input2_err2,
                     Nessi::Vector<double> & output,
                     Nessi::Vector<double> & output_err2,
                     void *temp);

  /**
   * This is the integer declaration of the function defined in 3.8.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<int>(const Nessi::Vector<int> & input1,
                  const Nessi::Vector<int> & input1_err2,
                  const Nessi::Vector<int> & input2,
                  const Nessi::Vector<int> & input2_err2,
                  Nessi::Vector<int> & output,
                  Nessi::Vector<int> & output_err2,
                  void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.8.
   *
   * \ingroup mult_ncerr
   */
  template std::string
  mult_ncerr<unsigned int>(const Nessi::Vector<unsigned int> & input1,
                           const Nessi::Vector<unsigned int> & input1_err2,
                           const Nessi::Vector<unsigned int> & input2,
                           const Nessi::Vector<unsigned int> & input2_err2,
                           Nessi::Vector<unsigned int> & output,
                           Nessi::Vector<unsigned int> & output_err2,
                           void *temp);

} // ArrayManip
