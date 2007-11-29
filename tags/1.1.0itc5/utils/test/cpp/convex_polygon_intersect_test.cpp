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
 * \file utils/test/cpp/convex_polygon_intersect_test.cpp
 */

#include "geometry.hpp"
#include "test_common.hpp"

using namespace std;

/**
 * \defgroup convex_polygon_intersect_test convex_polygon_intersect_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>convex_polygon_intersect</i> and described in section 3.60 of 
 * the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software 
 * Requirements and Specifications"</i> with the true output data 
 * (\f$true\_output\f$) manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - vv : vector-vector
 * - VV : "v,v"
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of the coordinate arrays for the 
 * different polygons
 *
 * \param parallelogram_x (OUTPUT) is the x coordinate array for a 
 * parallelogram 
 * \param parallelogram_y (OUTPUT) is the y coordinate array for a 
 * parallelogram 
 * \param square1_x (OUTPUT) is the x coordinate array for a square 
 * \param square1_y (OUTPUT) is the y coordinate array for a square 
 * \param square2_x (OUTPUT) is the x coordinate array for a square 
 * \param square2_y (OUTPUT) is the y coordinate array for a square 
 * \param square3_x (OUTPUT) is the x coordinate array for a square 
 * \param square3_y (OUTPUT) is the y coordinate array for a square 
 * \param square4_x (OUTPUT) is the x coordinate array for a square 
 * \param square4_y (OUTPUT) is the y coordinate array for a square 
 * \param square5_x (OUTPUT) is the x coordinate array for a square 
 * \param square5_y (OUTPUT) is the y coordinate array for a square 
 * \param square6_x (OUTPUT) is the x coordinate array for a square 
 * \param square6_y (OUTPUT) is the y coordinate array for a square 
 * \param square7_x (OUTPUT) is the x coordinate array for a square 
 * \param square7_y (OUTPUT) is the y coordinate array for a square 
 * \param square8_x (OUTPUT) is the x coordinate array for a square 
 * \param square8_y (OUTPUT) is the y coordinate array for a square 
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & parallelogram_x,
                       Nessi::Vector<NumT> & parallelogram_y,
                       Nessi::Vector<NumT> & square1_x,
                       Nessi::Vector<NumT> & square1_y,
                       Nessi::Vector<NumT> & square2_x,
                       Nessi::Vector<NumT> & square2_y,
                       Nessi::Vector<NumT> & square3_x,
                       Nessi::Vector<NumT> & square3_y,
                       Nessi::Vector<NumT> & square4_x,
                       Nessi::Vector<NumT> & square4_y,
                       Nessi::Vector<NumT> & square5_x,
                       Nessi::Vector<NumT> & square5_y,
                       Nessi::Vector<NumT> & square6_x,
                       Nessi::Vector<NumT> & square6_y,
                       Nessi::Vector<NumT> & square7_x,
                       Nessi::Vector<NumT> & square7_y,
                       Nessi::Vector<NumT> & square8_x,
                       Nessi::Vector<NumT> & square8_y)
{
  parallelogram_x.push_back(static_cast<NumT>(-3.0));
  parallelogram_x.push_back(static_cast<NumT>(-2.0));
  parallelogram_x.push_back(static_cast<NumT>(0.5));
  parallelogram_x.push_back(static_cast<NumT>(-0.5));

  parallelogram_y.push_back(static_cast<NumT>(-3.0));
  parallelogram_y.push_back(static_cast<NumT>(-1.0));
  parallelogram_y.push_back(static_cast<NumT>(-1.0));
  parallelogram_y.push_back(static_cast<NumT>(-3.0));

  square1_x.push_back(static_cast<NumT>(1.0));
  square1_x.push_back(static_cast<NumT>(0.0));
  square1_x.push_back(static_cast<NumT>(0.0));
  square1_x.push_back(static_cast<NumT>(1.0));

  square1_y.push_back(static_cast<NumT>(-2.0));
  square1_y.push_back(static_cast<NumT>(-2.0));
  square1_y.push_back(static_cast<NumT>(-1.0));
  square1_y.push_back(static_cast<NumT>(-1.0));

  square2_x.push_back(static_cast<NumT>(0.0));
  square2_x.push_back(static_cast<NumT>(-1.0));
  square2_x.push_back(static_cast<NumT>(-1.0));
  square2_x.push_back(static_cast<NumT>(0.0));

  square2_y.push_back(static_cast<NumT>(-4.0));
  square2_y.push_back(static_cast<NumT>(-4.0));
  square2_y.push_back(static_cast<NumT>(-3.0));
  square2_y.push_back(static_cast<NumT>(-3.0));

  square3_x.push_back(static_cast<NumT>(0.5));
  square3_x.push_back(static_cast<NumT>(-0.5));
  square3_x.push_back(static_cast<NumT>(-0.5));
  square3_x.push_back(static_cast<NumT>(0.5));

  square3_y.push_back(static_cast<NumT>(-1.5));
  square3_y.push_back(static_cast<NumT>(-1.5));
  square3_y.push_back(static_cast<NumT>(-0.5));
  square3_y.push_back(static_cast<NumT>(-0.5));

  square4_x.push_back(static_cast<NumT>(-1.0));
  square4_x.push_back(static_cast<NumT>(-2.0));
  square4_x.push_back(static_cast<NumT>(-2.0));
  square4_x.push_back(static_cast<NumT>(-1.0));

  square4_y.push_back(static_cast<NumT>(-2.0));
  square4_y.push_back(static_cast<NumT>(-2.0));
  square4_y.push_back(static_cast<NumT>(-1.0));
  square4_y.push_back(static_cast<NumT>(-1.0));

  square5_x.push_back(static_cast<NumT>(-0.5));
  square5_x.push_back(static_cast<NumT>(-0.5));
  square5_x.push_back(static_cast<NumT>(-1.5));
  square5_x.push_back(static_cast<NumT>(-1.5));

  square5_y.push_back(static_cast<NumT>(-1.5));
  square5_y.push_back(static_cast<NumT>(-2.5));
  square5_y.push_back(static_cast<NumT>(-2.5));
  square5_y.push_back(static_cast<NumT>(-1.5));

  square6_x.push_back(static_cast<NumT>(2.5));
  square6_x.push_back(static_cast<NumT>(1.5));
  square6_x.push_back(static_cast<NumT>(1.5));
  square6_x.push_back(static_cast<NumT>(2.5));

  square6_y.push_back(static_cast<NumT>(-1.0));
  square6_y.push_back(static_cast<NumT>(-1.0));
  square6_y.push_back(static_cast<NumT>(0.0));
  square6_y.push_back(static_cast<NumT>(0.0));

  square7_x.push_back(static_cast<NumT>(1.0));
  square7_x.push_back(static_cast<NumT>(-4.0));
  square7_x.push_back(static_cast<NumT>(-4.0));
  square7_x.push_back(static_cast<NumT>(1.0));

  square7_y.push_back(static_cast<NumT>(-4.0));
  square7_y.push_back(static_cast<NumT>(-4.0));
  square7_y.push_back(static_cast<NumT>(0.0));
  square7_y.push_back(static_cast<NumT>(0.0));

  square8_x.push_back(static_cast<NumT>(-2.0));
  square8_x.push_back(static_cast<NumT>(-3.0));
  square8_x.push_back(static_cast<NumT>(-3.0));
  square8_x.push_back(static_cast<NumT>(-2.0));

  square8_y.push_back(static_cast<NumT>(-1.0));
  square8_y.push_back(static_cast<NumT>(-1.0));
  square8_y.push_back(static_cast<NumT>(0.0));
  square8_y.push_back(static_cast<NumT>(0.0));
}

/**
 * Function that sets the true outputs based on values contained coordinate 
 * arrays for the triangle, square and parallelogram.
 *
 * \param true_output1_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square1
 * \param true_output1_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square1
 * \param true_output2_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square2
 * \param true_output2_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square2
 * \param true_output3_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square3
 * \param true_output3_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square3
 * \param true_output4_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square4
 * \param true_output4_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square4
 * \param true_output5_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square5
 * \param true_output5_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square5
 * \param true_output6_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square6
 * \param true_output6_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square6
 * \param true_output7_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square7
 * \param true_output7_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square7
 * \param true_output8_x (OUTPUT) is the x-coordinates of the true 
 * intersection polygon of the parallelogram with square8
 * \param true_output8_y (OUTPUT) is the y-coordinates of the true 
 * intersection polygon of the parallelogram with square8
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output1_x,
                             Nessi::Vector<NumT> & true_output1_y,
                             Nessi::Vector<NumT> & true_output2_x,
                             Nessi::Vector<NumT> & true_output2_y,
                             Nessi::Vector<NumT> & true_output3_x,
                             Nessi::Vector<NumT> & true_output3_y,
                             Nessi::Vector<NumT> & true_output4_x,
                             Nessi::Vector<NumT> & true_output4_y,
                             Nessi::Vector<NumT> & true_output5_x,
                             Nessi::Vector<NumT> & true_output5_y,
                             Nessi::Vector<NumT> & true_output6_x,
                             Nessi::Vector<NumT> & true_output6_y,
                             Nessi::Vector<NumT> & true_output7_x,
                             Nessi::Vector<NumT> & true_output7_y,
                             Nessi::Vector<NumT> & true_output8_x,
                             Nessi::Vector<NumT> & true_output8_y)
{
  // initialize the correct outputs

  true_output1_x.push_back(static_cast<NumT>(0.0));
  true_output1_x.push_back(static_cast<NumT>(0.5));
  true_output1_x.push_back(static_cast<NumT>(0.0));

  true_output1_y.push_back(static_cast<NumT>(-1.0));
  true_output1_y.push_back(static_cast<NumT>(-1.0));
  true_output1_y.push_back(static_cast<NumT>(-2.0));

  true_output2_x.push_back(static_cast<NumT>(-0.5));
  true_output2_x.push_back(static_cast<NumT>(-1.0));

  true_output2_y.push_back(static_cast<NumT>(-3.0));
  true_output2_y.push_back(static_cast<NumT>(-3.0));

  true_output3_x.push_back(static_cast<NumT>(-0.5));
  true_output3_x.push_back(static_cast<NumT>(0.5));
  true_output3_x.push_back(static_cast<NumT>(0.25));
  true_output3_x.push_back(static_cast<NumT>(-0.5));

  true_output3_y.push_back(static_cast<NumT>(-1.0));
  true_output3_y.push_back(static_cast<NumT>(-1.0));
  true_output3_y.push_back(static_cast<NumT>(-1.5));
  true_output3_y.push_back(static_cast<NumT>(-1.5));

  true_output4_x.push_back(static_cast<NumT>(-2.0));
  true_output4_x.push_back(static_cast<NumT>(-1.0));
  true_output4_x.push_back(static_cast<NumT>(-1.0));
  true_output4_x.push_back(static_cast<NumT>(-2.0));

  true_output4_y.push_back(static_cast<NumT>(-1.0));
  true_output4_y.push_back(static_cast<NumT>(-1.0));
  true_output4_y.push_back(static_cast<NumT>(-2.0));
  true_output4_y.push_back(static_cast<NumT>(-2.0));

  true_output5_x.push_back(static_cast<NumT>(-0.5));
  true_output5_x.push_back(static_cast<NumT>(-0.5));
  true_output5_x.push_back(static_cast<NumT>(-1.5));
  true_output5_x.push_back(static_cast<NumT>(-1.5));

  true_output5_y.push_back(static_cast<NumT>(-1.5));
  true_output5_y.push_back(static_cast<NumT>(-2.5));
  true_output5_y.push_back(static_cast<NumT>(-2.5));
  true_output5_y.push_back(static_cast<NumT>(-1.5));

  true_output6_x.push_back(static_cast<NumT>(0.0));

  true_output6_y.push_back(static_cast<NumT>(0.0));

  true_output7_x.push_back(static_cast<NumT>(-3.0));
  true_output7_x.push_back(static_cast<NumT>(-2.0));
  true_output7_x.push_back(static_cast<NumT>(0.5));
  true_output7_x.push_back(static_cast<NumT>(-0.5));

  true_output7_y.push_back(static_cast<NumT>(-3.0));
  true_output7_y.push_back(static_cast<NumT>(-1.0));
  true_output7_y.push_back(static_cast<NumT>(-1.0));
  true_output7_y.push_back(static_cast<NumT>(-3.0));

  true_output8_x.push_back(static_cast<NumT>(-2.0));

  true_output8_y.push_back(static_cast<NumT>(-1.0));
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>convex_polygon_intersect</i> function. The function 
 * returns TRUE if the two values compared, \f$output\f$ and 
 * \f$true\_output\f$, match, and returns FALSE if they do not match.
 *
 * \param output1_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square1
 * \param output1_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square1
 * \param output2_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square2
 * \param output2_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square2
 * \param output3_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square3
 * \param output3_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square3
 * \param output4_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square4
 * \param output4_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square4
 * \param output5_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square5
 * \param output5_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square5
 * \param output6_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square6
 * \param output6_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square6
 * \param output7_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square7
 * \param output7_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square7
 * \param output8_x (INPUT) is the x-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square8
 * \param output8_y (INPUT) is the y-coordinates created by 
 * <i>convex_polygon_intersect</i> for the overlap of the parallelogram with 
 * square8
 * \param true_output1_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square1
 * \param true_output1_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square1
 * \param true_output2_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square2
 * \param true_output2_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square2
 * \param true_output3_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square3
 * \param true_output3_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square3
 * \param true_output4_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square4
 * \param true_output4_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square4
 * \param true_output5_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square5
 * \param true_output5_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square5
 * \param true_output6_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square6
 * \param true_output6_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square6
 * \param true_output7_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square7
 * \param true_output7_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square7
 * \param true_output8_x (INPUT) is the true x-coordinates of the overlap of 
 * the parallelogram with square8
 * \param true_output8_y (INPUT) is the true y-coordinates of the overlap of 
 * the parallelogram with square8
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output1_x,
               Nessi::Vector<NumT> & output1_y,
               Nessi::Vector<NumT> & output2_x,
               Nessi::Vector<NumT> & output2_y,
               Nessi::Vector<NumT> & output3_x,
               Nessi::Vector<NumT> & output3_y,
               Nessi::Vector<NumT> & output4_x,
               Nessi::Vector<NumT> & output4_y,
               Nessi::Vector<NumT> & output5_x,
               Nessi::Vector<NumT> & output5_y,
               Nessi::Vector<NumT> & output6_x,
               Nessi::Vector<NumT> & output6_y,
               Nessi::Vector<NumT> & output7_x,
               Nessi::Vector<NumT> & output7_y,
               Nessi::Vector<NumT> & output8_x,
               Nessi::Vector<NumT> & output8_y,
               Nessi::Vector<NumT> & true_output1_x,
               Nessi::Vector<NumT> & true_output1_y,
               Nessi::Vector<NumT> & true_output2_x,
               Nessi::Vector<NumT> & true_output2_y,
               Nessi::Vector<NumT> & true_output3_x,
               Nessi::Vector<NumT> & true_output3_y,
               Nessi::Vector<NumT> & true_output4_x,
               Nessi::Vector<NumT> & true_output4_y,
               Nessi::Vector<NumT> & true_output5_x,
               Nessi::Vector<NumT> & true_output5_y,
               Nessi::Vector<NumT> & true_output6_x,
               Nessi::Vector<NumT> & true_output6_y,
               Nessi::Vector<NumT> & true_output7_x,
               Nessi::Vector<NumT> & true_output7_y,
               Nessi::Vector<NumT> & true_output8_x,
               Nessi::Vector<NumT> & true_output8_y)
{
  bool value = true;

  // fraction 1 x comparison
  if (!test_okay(output1_x, true_output1_x, VV))
    {
      value = false;
    }
  // fraction 1 y comparison
  if (!test_okay(output1_y, true_output1_y, VV))
    {
      value = false;
    }
  // fraction 2 x comparison
  if (!test_okay(output2_x, true_output2_x, VV))
    {
      value = false;
    }
  // fraction 2 y comparison
  if (!test_okay(output2_y, true_output2_y, VV))
    {
      value = false;
    }
  // fraction 3 x comparison
  if (!test_okay(output3_x, true_output3_x, VV))
    {
      value = false;
    }
  // fraction 3 y comparison
  if (!test_okay(output3_y, true_output3_y, VV))
    {
      value = false;
    }
  // fraction 4 x comparison
  if (!test_okay(output4_x, true_output4_x, VV))
    {
      value = false;
    }
  // fraction 4 y comparison
  if (!test_okay(output4_y, true_output4_y, VV))
    {
      value = false;
    }
  // fraction 5 x comparison
  if (!test_okay(output5_x, true_output5_x, VV))
    {
      value = false;
    }
  // fraction 5 y comparison
  if (!test_okay(output5_y, true_output5_y, VV))
    {
      value = false;
    }
  // fraction 6 x comparison
  if (!test_okay(output6_x, true_output6_x, VV))
    {
      value = false;
    }
  // fraction 6 y comparison
  if (!test_okay(output6_y, true_output6_y, VV))
    {
      value = false;
    }
  // fraction 7 x comparison
  if (!test_okay(output7_x, true_output7_x, VV))
    {
      value = false;
    }
  // fraction 7 y comparison
  if (!test_okay(output7_y, true_output7_y, VV))
    {
      value = false;
    }
  // fraction 8 x comparison
  if (!test_okay(output8_x, true_output8_x, VV))
    {
      value = false;
    }
  // fraction 8 y comparison
  if (!test_okay(output8_y, true_output8_y, VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>convex_polygon_intersect</i> 
 * function (as described in the documentation of the 
 * <i>convex_polygon_intersect</i> function) and launches the comparison of 
 * the data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug)
{ 
  // allocate arrays and values
  Nessi::Vector<NumT> parallelogram_x;
  Nessi::Vector<NumT> parallelogram_y;
  Nessi::Vector<NumT> square1_x;
  Nessi::Vector<NumT> square1_y;
  Nessi::Vector<NumT> square2_x;
  Nessi::Vector<NumT> square2_y;
  Nessi::Vector<NumT> square3_x;
  Nessi::Vector<NumT> square3_y;
  Nessi::Vector<NumT> square4_x;
  Nessi::Vector<NumT> square4_y;
  Nessi::Vector<NumT> square5_x;
  Nessi::Vector<NumT> square5_y;
  Nessi::Vector<NumT> square6_x;
  Nessi::Vector<NumT> square6_y;
  Nessi::Vector<NumT> square7_x;
  Nessi::Vector<NumT> square7_y;
  Nessi::Vector<NumT> square8_x;
  Nessi::Vector<NumT> square8_y;

  Nessi::Vector<NumT> true_output1_x;
  Nessi::Vector<NumT> true_output1_y;
  Nessi::Vector<NumT> true_output2_x;
  Nessi::Vector<NumT> true_output2_y;
  Nessi::Vector<NumT> true_output3_x;
  Nessi::Vector<NumT> true_output3_y;
  Nessi::Vector<NumT> true_output4_x;
  Nessi::Vector<NumT> true_output4_y;
  Nessi::Vector<NumT> true_output5_x;
  Nessi::Vector<NumT> true_output5_y;
  Nessi::Vector<NumT> true_output6_x;
  Nessi::Vector<NumT> true_output6_y;
  Nessi::Vector<NumT> true_output7_x;
  Nessi::Vector<NumT> true_output7_y;
  Nessi::Vector<NumT> true_output8_x;
  Nessi::Vector<NumT> true_output8_y;

  // fill in values as appropriate
  initialize_inputs(parallelogram_x, parallelogram_y, square1_x, square1_y, 
                    square2_x, square2_y, square3_x, square3_y, 
                    square4_x, square4_y, square5_x, square5_y,
                    square6_x, square6_y, square7_x, square7_y, 
                    square8_x, square8_y);

  // allocate the output arrays since we now know the sizes
  Nessi::Vector<NumT> output1_x(parallelogram_x.size()+square1_x.size());
  Nessi::Vector<NumT> output1_y(parallelogram_y.size()+square1_y.size());
  Nessi::Vector<NumT> output2_x(parallelogram_x.size()+square2_x.size());
  Nessi::Vector<NumT> output2_y(parallelogram_y.size()+square2_y.size());
  Nessi::Vector<NumT> output3_x(parallelogram_x.size()+square3_x.size());
  Nessi::Vector<NumT> output3_y(parallelogram_y.size()+square3_y.size());
  Nessi::Vector<NumT> output4_x(parallelogram_x.size()+square4_x.size());
  Nessi::Vector<NumT> output4_y(parallelogram_y.size()+square4_y.size());
  Nessi::Vector<NumT> output5_x(parallelogram_x.size()+square5_x.size());
  Nessi::Vector<NumT> output5_y(parallelogram_y.size()+square5_y.size());
  Nessi::Vector<NumT> output6_x(parallelogram_x.size()+square6_x.size());
  Nessi::Vector<NumT> output6_y(parallelogram_y.size()+square6_y.size());
  Nessi::Vector<NumT> output7_x(parallelogram_x.size()+square7_x.size());
  Nessi::Vector<NumT> output7_y(parallelogram_y.size()+square7_y.size());
  Nessi::Vector<NumT> output8_x(parallelogram_x.size()+square8_x.size());
  Nessi::Vector<NumT> output8_y(parallelogram_y.size()+square8_y.size());

  initialize_true_outputs(true_output1_x, true_output1_y, 
                          true_output2_x, true_output2_y, 
                          true_output3_x, true_output3_y, 
                          true_output4_x, true_output4_y,
                          true_output5_x, true_output5_y,
                          true_output6_x, true_output6_y,
                          true_output7_x, true_output7_y,
                          true_output8_x, true_output8_y);

  // run the code being tested

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square1_x, square1_y, output1_x, output1_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square2_x, square2_y, output2_x, output2_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square3_x, square3_y, output3_x, output3_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square4_x, square4_y, output4_x, output4_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square5_x, square5_y, output5_x, output5_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square6_x, square6_y, output6_x, output6_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square7_x, square7_y, output7_x, output7_y);

  Utils::convex_polygon_intersect(parallelogram_x, parallelogram_y, 
                                  square8_x, square8_y, output8_x, output8_y);

  if(!debug.empty())
    {
      cout << endl;
      print(output1_x, true_output1_x, VV, debug);
      print(output1_y, true_output1_y, VV, debug);
      print(output2_x, true_output2_x, VV, debug);
      print(output2_y, true_output2_y, VV, debug);
      print(output3_x, true_output3_x, VV, debug);
      print(output3_y, true_output3_y, VV, debug);
      print(output4_x, true_output4_x, VV, debug);
      print(output4_y, true_output4_y, VV, debug);
      print(output5_x, true_output5_x, VV, debug);
      print(output5_y, true_output5_y, VV, debug);
      print(output6_x, true_output6_x, VV, debug);
      print(output6_y, true_output6_y, VV, debug);
      print(output7_x, true_output7_x, VV, debug);
      print(output7_y, true_output7_y, VV, debug);
      print(output8_x, true_output8_x, VV, debug);
      print(output8_y, true_output8_y, VV, debug);
    }

  return test_okay(output1_x, output1_y, output2_x, output2_y, 
                   output3_x, output3_y, output4_x, output4_y,
                   output5_x, output5_y, output6_x, output6_y,
                   output7_x, output7_y, output8_x, output8_y,
                   true_output1_x, true_output1_y, 
                   true_output2_x, true_output2_y, 
                   true_output3_x, true_output3_y, 
                   true_output4_x, true_output4_y,
                   true_output5_x, true_output5_y,
                   true_output6_x, true_output6_y,
                   true_output7_x, true_output7_y,
                   true_output8_x, true_output8_y);
}

/**
 * Main function that tests <i>convex_polygon_intersect</i> for float and 
 * double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "convex_polygon_intersect_test.cpp..........";

  string debug;
  if(argc > 1)
    {
      debug = argv[1];
    }

  int value = 0;

  if(!test_func(static_cast<float>(1), debug))
    {
      value = -1;
    }

  if(!test_func(static_cast<double>(1), debug))
    {
      value = -1;
    }

  if(value == 0)
    {
      cout << "Functionality OK" << endl;
    }

  return value;
}

/**
 * \}
 */   //end of convex_polygon_intersect_test group
