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
 * \file axis_manip/test/cpp/rebin_2D_quad_to_rectlin_test.cpp
 */

#include "rebinning.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL = 5;
const size_t SIZE_QUAD = 4;
const size_t SIZE_TWO_QUADS = 2 * SIZE_QUAD;

/**
 * \defgroup rebin_2D_quad_to_rectlin_test rebin_2D_quad_to_rectlin_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>rebin_2D_quad_to_rectlin</i> and described in 3.61
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 */

/**
 * This function initializes the value of arrays, \f$axis\_in\_x1\f$,
 * \f$axis\_in\_2\f$, \f$axis\_out\_1\f$, \f$axis\_out\_2\f$, \f$input\f$,
 * and \f$input\_err2\f$.
 *
 * \param axis_in_x1 (OUTPUT) is the x-coordinate of the 1st corner of the 
 * initial data axis
 * \param axis_in_y1 (OUTPUT) is the y-coordinate of the 1st corner of the 
 * initial data axis
 * \param axis_in_x2 (OUTPUT) is the x-coordinate of the 2nd corner of the 
 * initial data axis
 * \param axis_in_y2 (OUTPUT) is the y-coordinate of the 2nd corner of the 
 * initial data axis
 * \param axis_in_x3 (OUTPUT) is the x-coordinate of the 3rd corner of the 
 * initial data axis
 * \param axis_in_y3 (OUTPUT) is the y-coordinate of the 3rd corner of the 
 * initial data axis
 * \param axis_in_x4 (OUTPUT) is the x-coordinate of the 4th corner of the 
 * initial data axis
 * \param axis_in_y4 (OUTPUT) is the y-coordinate of the 4th corner of the 
 * initial data axis
 * \param axis_out_1 (OUTPUT) is the 1st target axis for rebinning
 * \param axis_out_2 (OUTPUT) is the 2nd target axis for rebinning
 * \param input (OUTPUT) is the data associated with the initial axis
 * \param input_err2 (OUTPUT) is the square of the uncertainty associated with
 * the data
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis_in_x1,
                       Nessi::Vector<NumT> & axis_in_y1,
                       Nessi::Vector<NumT> & axis_in_x2,
                       Nessi::Vector<NumT> & axis_in_y2,
                       Nessi::Vector<NumT> & axis_in_x3,
                       Nessi::Vector<NumT> & axis_in_y3,
                       Nessi::Vector<NumT> & axis_in_x4,
                       Nessi::Vector<NumT> & axis_in_y4,
                       Nessi::Vector<NumT> & axis_out_1,
                       Nessi::Vector<NumT> & axis_out_2,
                       Nessi::Vector<NumT> & input,
                       Nessi::Vector<NumT> & input_err2)
{
  for (size_t i = 0; i < NUM_VAL; ++i)
    {
      input.push_back(static_cast<NumT>(10.));
      input_err2.push_back(static_cast<NumT>(1.));
      axis_out_1.push_back(static_cast<NumT>(i));
      axis_out_2.push_back(static_cast<NumT>(i));
    }

  axis_in_x1.push_back(static_cast<NumT>(0.75));
  axis_in_x1.push_back(static_cast<NumT>(1.25));
  axis_in_x1.push_back(static_cast<NumT>(1.75));
  axis_in_x1.push_back(static_cast<NumT>(2.25));
  axis_in_x1.push_back(static_cast<NumT>(2.75));

  axis_in_y1.push_back(static_cast<NumT>(0.75));
  axis_in_y1.push_back(static_cast<NumT>(1.25));
  axis_in_y1.push_back(static_cast<NumT>(1.75));
  axis_in_y1.push_back(static_cast<NumT>(2.25));
  axis_in_y1.push_back(static_cast<NumT>(2.75));

  axis_in_x2.push_back(static_cast<NumT>(0.75));
  axis_in_x2.push_back(static_cast<NumT>(1.25));
  axis_in_x2.push_back(static_cast<NumT>(1.75));
  axis_in_x2.push_back(static_cast<NumT>(2.25));
  axis_in_x2.push_back(static_cast<NumT>(2.75));

  axis_in_y2.push_back(static_cast<NumT>(1.25));
  axis_in_y2.push_back(static_cast<NumT>(1.75));
  axis_in_y2.push_back(static_cast<NumT>(2.25));
  axis_in_y2.push_back(static_cast<NumT>(2.75));
  axis_in_y2.push_back(static_cast<NumT>(3.25));

  axis_in_x3.push_back(static_cast<NumT>(1.25));
  axis_in_x3.push_back(static_cast<NumT>(1.75));
  axis_in_x3.push_back(static_cast<NumT>(2.25));
  axis_in_x3.push_back(static_cast<NumT>(2.75));
  axis_in_x3.push_back(static_cast<NumT>(3.25));

  axis_in_y3.push_back(static_cast<NumT>(1.75));
  axis_in_y3.push_back(static_cast<NumT>(2.25));
  axis_in_y3.push_back(static_cast<NumT>(2.75));
  axis_in_y3.push_back(static_cast<NumT>(3.25));
  axis_in_y3.push_back(static_cast<NumT>(3.75));

  axis_in_x4.push_back(static_cast<NumT>(1.25));
  axis_in_x4.push_back(static_cast<NumT>(1.75));
  axis_in_x4.push_back(static_cast<NumT>(2.25));
  axis_in_x4.push_back(static_cast<NumT>(2.75));
  axis_in_x4.push_back(static_cast<NumT>(3.25));

  axis_in_y4.push_back(static_cast<NumT>(1.25));
  axis_in_y4.push_back(static_cast<NumT>(1.75));
  axis_in_y4.push_back(static_cast<NumT>(2.25));
  axis_in_y4.push_back(static_cast<NumT>(2.75));
  axis_in_y4.push_back(static_cast<NumT>(3.25));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis\_in\_x1\f$, \f$axis\_in\_y1\f$, \f$axis\_in\_x2\f$, 
 * \f$axis\_in\_y2\f$, \f$axis\_in\_x3\f$, \f$axis\_in\_y3\f$, 
 * \f$axis\_in\_x4\f$, \f$axis\_in\_y4\f$, \f$axis\_out\_1\f$,
 * \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$ for the float case.
 *
 * \param true_output (OUTPUT) is the true output
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * true output
 * \param true_frac_area (OUTPUT) is the true fractional area
 *
 */
void initialize_true_outputs(Nessi::Vector<float> & true_output,
                             Nessi::Vector<float> & true_output_err2,
                             Nessi::Vector<float> & true_frac_area)
{
  true_output.push_back(static_cast<float>(0.3125));
  true_output.push_back(static_cast<float>(0.9375));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(3.75));
  true_output.push_back(static_cast<float>(1.25));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(3.75));
  true_output.push_back(static_cast<float>(1.25));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(1.25));

  true_output_err2.push_back(static_cast<float>(0.0009766));
  true_output_err2.push_back(static_cast<float>(0.0087891));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0644531));
  true_output_err2.push_back(static_cast<float>(0.0097656));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0644531));
  true_output_err2.push_back(static_cast<float>(0.0097656));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.015625));

  true_frac_area.push_back(static_cast<float>(0.03125));
  true_frac_area.push_back(static_cast<float>(0.09375));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.375));
  true_frac_area.push_back(static_cast<float>(0.125));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.375));
  true_frac_area.push_back(static_cast<float>(0.125));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.0));
  true_frac_area.push_back(static_cast<float>(0.125));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis\_in\_x1\f$, \f$axis\_in\_y1\f$, \f$axis\_in\_x2\f$, 
 * \f$axis\_in\_y2\f$, \f$axis\_in\_x3\f$, \f$axis\_in\_y3\f$, 
 * \f$axis\_in\_x4\f$, \f$axis\_in\_y4\f$, \f$axis\_out\_1\f$,
 * \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$ for the double case.
 *
 * \param true_output (OUTPUT) is the true output
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * true output
 * \param true_frac_area (OUTPUT) is the true fractional area
 *
 */
void initialize_true_outputs(Nessi::Vector<double> & true_output,
                             Nessi::Vector<double> & true_output_err2,
                             Nessi::Vector<double> & true_frac_area)
{
  true_output.push_back(static_cast<double>(0.3125));
  true_output.push_back(static_cast<double>(0.9375));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(3.75));
  true_output.push_back(static_cast<double>(1.25));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(3.75));
  true_output.push_back(static_cast<double>(1.25));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(1.25));

  true_output_err2.push_back(static_cast<double>(0.0009765625));
  true_output_err2.push_back(static_cast<double>(0.0087890625));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.064453125));
  true_output_err2.push_back(static_cast<double>(0.009765625));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.064453125));
  true_output_err2.push_back(static_cast<double>(0.009765625));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.015625));

  true_frac_area.push_back(static_cast<double>(0.03125));
  true_frac_area.push_back(static_cast<double>(0.09375));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.375));
  true_frac_area.push_back(static_cast<double>(0.125));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.375));
  true_frac_area.push_back(static_cast<double>(0.125));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.0));
  true_frac_area.push_back(static_cast<double>(0.125));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>rebin_2D_quad_to_rectlin</i> function.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the array created by 
 * <i>rebin_2D_quad_to_rectlin</i>
 * \param output_err2 (INPUT) is the square of the uncertainty in the array
 * created by <i>rebin_2D_quad_to_rectlin</i> 
 * \param frac_area (INPUT) is the fractional area array created by 
 * <i>rebin_2D_quad_to_rectlin</i>
 * \param true_output (INPUT) is the true array
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the true
 * array
 * \param true_frac_area (INPUT) is the true fractional area array
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               Nessi::Vector<NumT> & frac_area,
               Nessi::Vector<NumT> & true_output,
               Nessi::Vector<NumT> & true_output_err2,
               Nessi::Vector<NumT> & true_frac_area)
{
  bool value = true;

  if(!test_okay(output, true_output, VV))
    {
      value = false;
    }

  if(!test_okay(output_err2, true_output_err2, VV))
    {
      value = false;
    }

  if(!test_okay(frac_area, true_frac_area, VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>rebin_2D_quad_to_rectlin</i> 
 * function (as described in the documentation of the 
 * <i>rebin_2D_quad_to_rectlin</i> function) and launches the comparison of 
 * the data.
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any string that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  Nessi::Vector<NumT> axis_in_x1;
  Nessi::Vector<NumT> axis_in_y1;
  Nessi::Vector<NumT> axis_in_x2;
  Nessi::Vector<NumT> axis_in_y2;
  Nessi::Vector<NumT> axis_in_x3;
  Nessi::Vector<NumT> axis_in_y3;
  Nessi::Vector<NumT> axis_in_x4;
  Nessi::Vector<NumT> axis_in_y4;
  Nessi::Vector<NumT> axis_out_1;
  Nessi::Vector<NumT> axis_out_2;
  Nessi::Vector<NumT> input;
  Nessi::Vector<NumT> input_err2;
  Nessi::Vector<NumT> true_output;
  Nessi::Vector<NumT> true_output_err2;
  Nessi::Vector<NumT> true_frac_area;

  Nessi::Vector<NumT> orig_bin_x(SIZE_QUAD);
  Nessi::Vector<NumT> orig_bin_y(SIZE_QUAD);
  Nessi::Vector<NumT> rebin_bin_x(SIZE_QUAD);
  Nessi::Vector<NumT> rebin_bin_y(SIZE_QUAD);
  Nessi::Vector<NumT> frac_bin_x(SIZE_TWO_QUADS);
  Nessi::Vector<NumT> frac_bin_y(SIZE_TWO_QUADS);

  // fill in values as appropriate
  initialize_inputs(axis_in_x1, axis_in_y1, axis_in_x2, axis_in_y2, 
                    axis_in_x3, axis_in_y3, axis_in_x4, axis_in_y4,
                    axis_out_1, axis_out_2, input, input_err2);
  initialize_true_outputs(true_output, true_output_err2, true_frac_area);

  // allocate output arrays
  Nessi::Vector<NumT> output((axis_out_1.size()-1)*(axis_out_2.size()-1));
  Nessi::Vector<NumT> output_err2((axis_out_1.size()-1)*
                                  (axis_out_2.size()-1));
  Nessi::Vector<NumT> frac_area((axis_out_1.size()-1)*(axis_out_2.size()-1));

  // run the code being tested
  AxisManip::rebin_2D_quad_to_rectlin(axis_in_x1, axis_in_y1, 
                                      axis_in_x2, axis_in_y2, 
                                      axis_in_x3, axis_in_y3, 
                                      axis_in_x4, axis_in_y4, 
                                      input, input_err2, 
                                      axis_out_1, axis_out_2, 
                                      orig_bin_x, orig_bin_y, 
                                      rebin_bin_x, rebin_bin_y, 
                                      frac_bin_x, frac_bin_y, 
                                      output, output_err2,
                                      frac_area);

  if(!debug.empty())
    {
      cout << endl;
      cout << output.size() << " " << output_err2.size() << endl;
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug);
      print(frac_area, true_frac_area, VV, debug);
    }

  return test_okay(output, output_err2, frac_area, 
                   true_output, true_output_err2, true_frac_area);
}

/**
 * Main function that test rebin_2D_quad_to_rectlin for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "rebin_2D_quad_to_rectlin_test.cpp..........";

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
 */  // end of rebin_2D_quad_to_rectlin_test group
