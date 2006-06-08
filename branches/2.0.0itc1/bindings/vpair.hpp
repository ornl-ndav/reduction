/*                     SNS Common Libraries
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
 * \file bindings/vpair.hpp
 */
#ifndef _VPAIR_HPP
#define _VPAIR_HPP 1

/**
 * \brief This structure provides a transfer mechanism between Python and C++
 * for Swig
 *
 * This file contains a simple two element structure that provides a transfer
 * mechanism for references of primitive types to be passed between Python and
 * C++. The need arises due to Swig's handling of those primitive type
 * references. The structure assumes the pairing of a value and its
 * associated uncertainty squared is being passed around. However, the
 * structure can be used to handle single instances of primitive references.
 *
 * \defgroup vpair VPair
 * \{
 */
template<class NumT> struct VPair {
  /**
   * Variable to hold a value
   */
  NumT val;
  /**
   * Variable to hold the square of the uncertainty for a value
   */
  NumT val_err2;
};

/**
 * \}
 */ // end of vpair group

#endif //_VPAIR_HPP
