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
 * \file utils/inc/utils_enums.hpp
 */

#ifndef _UTILS_ENUMS_HPP
#define _UTILS_ENUMS_HPP 1

namespace Utils
{
  /** \enum Utils::eEdgeIn
   * Enumeration for handling edge positions
   */
  enum eEdgeIn { 
    UNKNOWN,        /**< Which edge is inside the other is not known */
    A_IS_INSIDE,    /**< Edge A is inside of edge B */
    B_IS_INSIDE     /**< Edge B is inside of edge A */
  };

  /** \enum Utils::eEdgeClass
   * Enumeration for handling point to edge classifications
   */
  enum eEdgeClass {
    LEFT,         /**< Point is to left of edge */
    RIGHT,        /**< Point is to right of edge */
    BEYOND,       /**< Point is right of edge destination */
    BEHIND,       /**< Point is left of edge origin */
    BETWEEN,      /**< Point is between edge origin and destination */
    ORIGIN,       /**< Point equals edge origin */
    DESTINATION   /**< Point equals edge destination */
  };

  /** \enum Utils::eEdgeOrient
   * Enumeration for handling edge orientations
   */
  enum eEdgeOrient {
    COLLINEAR,      /**< Edges lie on the same line */
    PARALLEL,       /**< Edges point in the same direction */
    SKEW,           /**< Edges are at an angle to each other */
    SKEW_CROSS,     /**< Edges are at an angle and intersect */
    SKEW_NO_CROSS   /**< Edges are at an angle and do not intersect */
  };
} // Utils

#endif // _UTILS_ENUMS_HPP 1
