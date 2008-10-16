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
 * \file utils/test/cpp/integrate_1D_hist_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup integrate_1D_hist_test integrate_1D_hist_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>integrate_1D_hist</i> and described in section 3.65 of the
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
 * This function initializes the values of arrays, \f$axis\f$, \f$axis\_bc\f$, 
 * \f$input\f$ and \f$input\_err2\f$.
 *
 * \param axis (OUTPUT) is the array of independent values for the data to 
 * shift
 * \param axis_bw (OUTPUT) is the array of bin widths from the independent 
 * values
 * \param input (OUTPUT) is the array of values to be shifted
 * \param input_err2 (OUTPUT) is the square of the uncertainty associated
 * with the value array.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis,
                       Nessi::Vector<NumT> & axis_bw,
                       Nessi::Vector<NumT> & input,
                       Nessi::Vector<NumT> & input_err2)
{
  axis.push_back(static_cast<NumT>(1.0));
  axis.push_back(static_cast<NumT>(1.5));
  axis.push_back(static_cast<NumT>(2.0));
  axis.push_back(static_cast<NumT>(2.5));
  axis.push_back(static_cast<NumT>(3.0));
  axis.push_back(static_cast<NumT>(3.5));

  axis_bw.push_back(static_cast<NumT>(0.5));
  axis_bw.push_back(static_cast<NumT>(0.5));
  axis_bw.push_back(static_cast<NumT>(0.5));
  axis_bw.push_back(static_cast<NumT>(0.5));
  axis_bw.push_back(static_cast<NumT>(0.5));

  input.push_back(static_cast<NumT>(30.0));
  input.push_back(static_cast<NumT>(20.0));
  input.push_back(static_cast<NumT>(10.0));
  input.push_back(static_cast<NumT>(20.0));
  input.push_back(static_cast<NumT>(30.0));

  input_err2.push_back(static_cast<NumT>(4.0));
  input_err2.push_back(static_cast<NumT>(3.0));
  input_err2.push_back(static_cast<NumT>(2.0));
  input_err2.push_back(static_cast<NumT>(3.0));
  input_err2.push_back(static_cast<NumT>(4.0));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input\f$ and \f$input\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the full integration 
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * full integration
 * \param true_output_w (OUTPUT) is the true value of the full integration 
 * with width removal
 * \param true_output_w_err2 (OUTPUT) is the square of the uncertainty of the
 * full integration with width removal
 * \param true_output_r (OUTPUT) is the true value of the ranged integration 
 * \param true_output_r_err2 (OUTPUT) is the square of the uncertainty of the
 * ranged integration
 * \param true_output_rw (OUTPUT) is the true value of the ranged integration 
 * with width removal 
 * \param true_output_rw_err2 (OUTPUT) is the square of the uncertainty of the
 * ranged integration with width removal
 */
template <typename NumT>
void initialize_true_outputs(NumT & true_output,
                             NumT & true_output_err2,
                             NumT & true_output_w,
                             NumT & true_output_w_err2,
                             NumT & true_output_r,
                             NumT & true_output_r_err2,
                             NumT & true_output_rw,
                             NumT & true_output_rw_err2)
{
  // initialize the correct outputs
  true_output = static_cast<NumT>(3.);
  true_output_err2 = static_cast<NumT>(0.2);
  true_output_w = static_cast<NumT>(3.);
  true_output_w_err2 = static_cast<NumT>(0.2);
  true_output_r = static_cast<NumT>(3.);
  true_output_r_err2 = static_cast<NumT>(0.2);
  true_output_rw = static_cast<NumT>(3.);
  true_output_rw_err2 = static_cast<NumT>(0.2);
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>integrate_1D_hist</i> function. The function returns
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>integrate_1D_hist</i> full 
 * integration
 * \param output_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>integrate_1D_hist</i> full integration
 * \param output_w (INPUT) is the value created by <i>integrate_1D_hist</i> 
 * full integration
 * \param output_w_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>integrate_1D_hist</i> full integration
 * \param true_output (INPUT) is the true value of the full integration 
 * \param true_output_err2 (INPUT) is the square of the uncertainty of the
 * full integration
 * \param true_output_w (INPUT) is the true value of the full integration 
 * with width removal
 * \param true_output_w_err2 (INPUT) is the square of the uncertainty of the
 * full integration with width removal
 * \param true_output_r (INPUT) is the true value of the ranged integration 
 * \param true_output_r_err2 (INPUT) is the square of the uncertainty of the
 * ranged integration
 * \param true_output_rw (INPUT) is the true value of the ranged integration 
 * with width removal 
 * \param true_output_rw_err2 (INPUT) is the square of the uncertainty of the
 * ranged integration with width removal
 */
template <typename NumT>
bool test_okay(NumT & output,
               NumT & output_err2,
               NumT & output_w,
               NumT & output_w_err2,
               NumT & output_r,
               NumT & output_r_err2,
               NumT & output_rw,
               NumT & output_rw_err2,
               NumT & true_output,
               NumT & true_output_err2,
               NumT & true_output_w,
               NumT & true_output_w_err2,
               NumT & true_output_r,
               NumT & true_output_r_err2,
               NumT & true_output_rw,
               NumT & true_output_rw_err2)
{
  // scalar scalar comparison for full integration
  if(!test_okay(output, true_output, SS))
    {
      return false;
    }
  if(!test_okay(output_err2, true_output_err2, SS, ERROR))
    {
      return false;
    }

  // scalar scalar comparison for full integration with width removal
  if(!test_okay(output_w, true_output_w, SS))
    {
      return false;
    }
  if(!test_okay(output_w_err2, true_output_w_err2, SS, ERROR))
    {
      return false;
    }

  // scalar scalar comparison for ranged integration
  if(!test_okay(output_r, true_output_r, SS))
    {
      return false;
    }
  if(!test_okay(output_r_err2, true_output_r_err2, SS, ERROR))
    {
      return false;
    }

  // scalar scalar comparison for ranged integration with width removal
  if(!test_okay(output_rw, true_output_rw, SS))
    {
      return false;
    }
  if(!test_okay(output_rw_err2, true_output_rw_err2, SS, ERROR))
    {
      return false;
    }

  // everything okay
  return true;
}

/**
 * Function that generates the data using the <i>integrate_1D_hist</i> function
 * (as described in the documentation of the <i>integrate_1D_hist</i> function)
 * and launches the comparison of the data. Returns the result
 * of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 */
template <typename NumT>
bool test_func(NumT key)
{ 
  // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> input;
  Nessi::Vector<NumT> input_err2;
  Nessi::Vector<NumT> axis_in;
  Nessi::Vector<NumT> axis_bw;
  NumT min_int = static_cast<NumT>(1.6);
  NumT max_int = static_cast<NumT>(2.9);
  NumT output;
  NumT output_err2;
  NumT output_w;
  NumT output_w_err2;
  NumT output_r;
  NumT output_r_err2;
  NumT output_rw;
  NumT output_rw_err2;
  NumT true_output;
  NumT true_output_err2;
  NumT true_output_w;
  NumT true_output_w_err2;
  NumT true_output_r;
  NumT true_output_r_err2;
  NumT true_output_rw;
  NumT true_output_rw_err2;

  // fill in values as appropriate
  initialize_inputs(axis_in, axis_bw, input, input_err2);
  initialize_true_outputs(true_output, true_output_err2, 
                          true_output_w, true_output_w_err2,
                          true_output_r, true_output_r_err2,
                          true_output_rw, true_output_rw_err2);

  // run the code being tested

  // full integration
  Utils::integrate_1D_hist(input, input_err2, axis_in, false, axis_bw,
                           output, output_err2);

  // full integration with width removal
  Utils::integrate_1D_hist(input, input_err2, axis_in, true, axis_bw,
                           output_w, output_w_err2);

  // range integration
  Utils::integrate_1D_hist(input, input_err2, axis_in, min_int, max_int, 
                           false, axis_bw, output_r, output_r_err2);

  // range integration with width removal
  Utils::integrate_1D_hist(input, input_err2, axis_in, min_int, max_int, 
                           true, axis_bw, output_rw, output_rw_err2);

  return test_okay(output, output_err2, output_w, output_w_err2,
                   output_r, output_r_err2, output_rw, output_rw_err2, 
                   true_output, true_output_err2, 
                   true_output_w, true_output_w_err2,
                   true_output_r, true_output_r_err2,
                   true_output_rw, true_output_rw_err2);
}

/**
 * Main function that tests <i>integrate_1D_hist</i> for float and double
 */
int main()
{
  cout << "integrate_1D_hist_test.cpp..........";

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
 */   //end of integrate_1D_hist_test group
