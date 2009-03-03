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
 * \file utils/src/check_histo_sizes.cpp
 */
#include "check_histo_sizes.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<float>(const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const Nessi::Vector<float> & axis);

  /**
   * This is the float declaration of te check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<float>(std::string str,
                           const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const Nessi::Vector<float> & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<double>(const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const Nessi::Vector<double> & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<double>(std::string str,
                            const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const Nessi::Vector<double> & axis);  

  /**
   * This is the integer declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<int>(const Nessi::Vector<int> & input,
                         const Nessi::Vector<int> & input_err2,
                         const Nessi::Vector<int> & axis);

  /**
   * This is the integer declaration of the check_histo_sizes function
   *
   *\ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<int>(std::string str,
                         const Nessi::Vector<int> & input,
                         const Nessi::Vector<int> & input_err2,
                         const Nessi::Vector<int> & axis);

  /**
   * This is the unsigned integer declaration of the check_histo_sizes
   * function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<unsigned int>(
                                const Nessi::Vector<unsigned int> & input,
                                const Nessi::Vector<unsigned int> & input_err2,
                                const Nessi::Vector<unsigned int> & axis);

  /**
   * This is the unsigend integer declaration of the check_histo_sizes
   * function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<unsigned int>(
                                std::string str,
                                const Nessi::Vector<unsigned int> & input,
                                const Nessi::Vector<unsigned int> & input_err2,
                                const Nessi::Vector<unsigned int> & axis);

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<float>(const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const Nessi::Vector<float> & axis_1,
                           const Nessi::Vector<float> & axis_2);

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<float>(std::string str,
                           const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const Nessi::Vector<float> & axis_1,
                           const Nessi::Vector<float> & axis_2);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<double>(const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const Nessi::Vector<double> & axis_1,
                            const Nessi::Vector<double> & axis_2);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<double>(std::string str,
                            const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const Nessi::Vector<double> & axis_1,
                            const Nessi::Vector<double> & axis_2);

  /**
   * This is the integer declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<int>(const Nessi::Vector<int> & input,
                         const Nessi::Vector<int> & input_err2,
                         const Nessi::Vector<int> & axis_1,
                         const Nessi::Vector<int> & axis_2);

  /**
   * This is the integer declaration of the check_histo_sizes function
   *
   *\ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<int>(std::string str,
                         const Nessi::Vector<int> & input,
                         const Nessi::Vector<int> & input_err2,
                         const Nessi::Vector<int> & axis_1,
                         const Nessi::Vector<int> & axis_2);

  /**
   * This is the unsigned integer declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void
  check_histo_sizes<unsigned int>(
                                const Nessi::Vector<unsigned int> & input,
                                const Nessi::Vector<unsigned int> & input_err2,
                                const Nessi::Vector<unsigned int> & axis_1,
                                const Nessi::Vector<unsigned int> & axis_2);

  /**
   * This is the unsigned integer declaration of the check_histo_sizes function
   *
   * \ingroup check_hist_sizes
   */
  template void
  check_histo_sizes<unsigned int>(
                                std::string str,
                                const Nessi::Vector<unsigned int> & input,
                                const Nessi::Vector<unsigned int> & input_err2,
                                const Nessi::Vector<unsigned int> & axis_1,
                                const Nessi::Vector<unsigned int> & axis_2);
  
} // Utils
