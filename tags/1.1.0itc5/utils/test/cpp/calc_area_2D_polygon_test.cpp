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
 * \file utils/test/cpp/calc_area_2D_polygon_test.cpp
 */

#include "geometry.hpp"
#include "test_common.hpp"

using namespace std;

/**
 * \defgroup calc_area_2D_polygon_test calc_area_2D_polygon_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>calc_area_2D_polygon</i> and described in section 3.59 of the
 * <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications"</i> with the true output data (\f$true\_output\f$)
 * manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - ss : scalar-scalar
 * - SS : "s,s"
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of the coordinate arrays for the 
 * different polygons
 *
 * \param triangle_x (OUTPUT) is the x coordinate array for a triangle 
 * \param triangle_y (OUTPUT) is the y coordinate array for a triangle 
 * \param square_x (OUTPUT) is the x coordinate array for a square 
 * \param square_y (OUTPUT) is the y coordinate array for a square 
 * \param parallelogram_x (OUTPUT) is the x coordinate array for a 
 * parallelogram 
 * \param parallelogram_y (OUTPUT) is the y coordinate array for a 
 * parallelogram 
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & triangle_x,
                       Nessi::Vector<NumT> & triangle_y,
                       Nessi::Vector<NumT> & square_x,
                       Nessi::Vector<NumT> & square_y,
                       Nessi::Vector<NumT> & parallelogram_x,
                       Nessi::Vector<NumT> & parallelogram_y)
{
  triangle_x.push_back(static_cast<NumT>(1.0));
  triangle_x.push_back(static_cast<NumT>(-1.0));
  triangle_x.push_back(static_cast<NumT>(0.0));
  triangle_x.push_back(static_cast<NumT>(1.0));
  triangle_x.push_back(static_cast<NumT>(-1.0));

  triangle_y.push_back(static_cast<NumT>(1.0));
  triangle_y.push_back(static_cast<NumT>(1.0));
  triangle_y.push_back(static_cast<NumT>(3.0));
  triangle_y.push_back(static_cast<NumT>(1.0));
  triangle_y.push_back(static_cast<NumT>(1.0));

  square_x.push_back(static_cast<NumT>(2.5));
  square_x.push_back(static_cast<NumT>(1.5));
  square_x.push_back(static_cast<NumT>(1.5));
  square_x.push_back(static_cast<NumT>(2.5));
  square_x.push_back(static_cast<NumT>(2.5));
  square_x.push_back(static_cast<NumT>(1.5));

  square_y.push_back(static_cast<NumT>(-1.0));
  square_y.push_back(static_cast<NumT>(-1.0));
  square_y.push_back(static_cast<NumT>(0.0));
  square_y.push_back(static_cast<NumT>(0.0));
  square_y.push_back(static_cast<NumT>(-1.0));
  square_y.push_back(static_cast<NumT>(-1.0));

  parallelogram_x.push_back(static_cast<NumT>(-2.0));
  parallelogram_x.push_back(static_cast<NumT>(-3.0));
  parallelogram_x.push_back(static_cast<NumT>(-0.5));
  parallelogram_x.push_back(static_cast<NumT>(0.5));
  parallelogram_x.push_back(static_cast<NumT>(-2.0));
  parallelogram_x.push_back(static_cast<NumT>(-3.0));

  parallelogram_y.push_back(static_cast<NumT>(-1.0));
  parallelogram_y.push_back(static_cast<NumT>(-3.0));
  parallelogram_y.push_back(static_cast<NumT>(-3.0));
  parallelogram_y.push_back(static_cast<NumT>(-1.0));
  parallelogram_y.push_back(static_cast<NumT>(-1.0));
  parallelogram_y.push_back(static_cast<NumT>(-3.0));
}

/**
 * Function that sets the true outputs based on values contained coordinate 
 * arrays for the triangle, square and parallelogram.
 *
 * \param true_output_triangle (OUTPUT) is the true value of the area of the 
 * triangle
 * \param true_output_square (OUTPUT) is the true value of the area of the 
 * square
 * \param true_output_parallelogram (OUTPUT) is the true value of the area of 
 * the parallelogram
 */
template <typename NumT>
void initialize_true_outputs(NumT & true_output_triangle,
                             NumT & true_output_square,
                             NumT & true_output_parallelogram)
{
  // initialize the correct outputs
  true_output_triangle = static_cast<NumT>(2.);
  true_output_square = static_cast<NumT>(-1.);
  true_output_parallelogram = static_cast<NumT>(5.);
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>calc_area_2D_polygon</i> function. The function returns
 * TRUE if the two values compared, \f$output\f$ and \f$true\_output\f$, match,
 * and returns FALSE if they do not match.
 *
 * \param output_triangle (INPUT) is the value created by 
 * <i>calc_area_2D_polygon</i> for the triangle case
 * \param output_square (INPUT) is the value created by 
 * <i>calc_area_2D_polygon</i> for the square case
 * \param output_parallelogram (INPUT) is the value created by 
 * <i>calc_area_2D_polygon</i> for the parallelogram case
 * \param true_output_triangle (INPUT) is the true value of the triangle area
 * \param true_output_square (INPUT) is the true value of the square area
 * \param true_output_parallelogram (INPUT) is the true value of the 
 * parallelogram area
 */
template <typename NumT>
bool test_okay(NumT & output_triangle,
               NumT & output_square,
               NumT & output_parallelogram,
               NumT & true_output_triangle,
               NumT & true_output_square,
               NumT & true_output_parallelogram)
{
  bool value = true;

  // triangle comparison
  if (!test_okay(output_triangle, true_output_triangle, SS))
    {
      value = false;
    }

  // square comparison
  if (!test_okay(output_square, true_output_square, SS))
    {
      value = false;
    }

  // parallelogram comparison
  if (!test_okay(output_parallelogram, true_output_parallelogram, SS))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>calc_area_2D_polygon</i> 
 * function (as described in the documentation of the 
 * <i>calc_area_2D_polygon</i> function) and launches the comparison of the 
 * data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 */
template <typename NumT>
bool test_func(NumT key)
{ 
  // allocate arrays and values
  Nessi::Vector<NumT> triangle_x;
  Nessi::Vector<NumT> triangle_y;
  Nessi::Vector<NumT> square_x;
  Nessi::Vector<NumT> square_y;
  Nessi::Vector<NumT> parallelogram_x;
  Nessi::Vector<NumT> parallelogram_y;
  NumT output_triangle;
  NumT output_square;
  NumT output_parallelogram;
  NumT true_output_triangle;
  NumT true_output_square;
  NumT true_output_parallelogram;

  // fill in values as appropriate
  initialize_inputs(triangle_x, triangle_y, square_x, square_y, 
                    parallelogram_x, parallelogram_y);
  initialize_true_outputs(true_output_triangle, true_output_square, 
                          true_output_parallelogram);

  // run the code being tested
  Utils::calc_area_2D_polygon(triangle_x, triangle_y, 3, false, 
                              output_triangle);

  Utils::calc_area_2D_polygon(square_x, square_y, 4, true, 
                              output_square);

  Utils::calc_area_2D_polygon(parallelogram_x, parallelogram_y, 4, true, 
                              output_parallelogram);

  return test_okay(output_triangle, output_square, output_parallelogram, 
                   true_output_triangle, true_output_square, 
                   true_output_parallelogram);
}

/**
 * Main function that tests <i>calc_area_2D_polygon</i> for float and double
 */
int main()
{
  cout << "calc_area_2D_polygon_test.cpp..........";

  int value = 0;

  if(!test_func(static_cast<float>(1)))
    {
      value = -1;
    }

  if(!test_func(static_cast<double>(1)))
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
 */   //end of calc_area_2D_polygon_test group
