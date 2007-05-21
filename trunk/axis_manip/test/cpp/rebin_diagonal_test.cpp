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
 * \file axis_manip/test/cpp/rebin_diagonal_test.cpp
 */

#include "rebinning.hpp"
#include "test_common.hpp"

using namespace std;

/**
 * \defgroup rebin_diagonal_test rebin_diagonal_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>rebin_diagonal</i> and described in 3.53
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 */

/**
 * This function initializes the value of arrays, \f$axis\_in\_1\f$,
 * \f$axis\_in\_2\f$, \f$axis\_out\_1\f$, \f$axis\_out\_2\f$, \f$input\f$,
 * and \f$input\_err2\f$.
 *
 * \param axis_in_1 (OUTPUT) is the initial data 1st axis
 * \param axis_in_2 (OUTPUT) is the initial data 2nd axis
 * \param axis_out_1 (OUTPUT) is the 1st target axis for rebinning
 * \param axis_out_2 (OUTPUT) is the 2nd target axis for rebinning
 * \param input (OUTPUT) is the data associated with the initial axis
 * \param input_err2 (OUTPUT) is the square of the uncertainty associated with
 * the data
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis_in_1,
                       Nessi::Vector<NumT> & axis_in_2,
                       Nessi::Vector<NumT> & axis_out_1,
                       Nessi::Vector<NumT> & axis_out_2,
                       Nessi::Vector<NumT> & input,
                       Nessi::Vector<NumT> & input_err2)
{
  axis_in_1.push_back(static_cast<NumT>(0.));
  axis_in_1.push_back(static_cast<NumT>(1.));
  axis_in_1.push_back(static_cast<NumT>(2.));
  axis_in_1.push_back(static_cast<NumT>(3.));
  axis_in_1.push_back(static_cast<NumT>(4.));

  axis_in_2.push_back(static_cast<NumT>(0.));
  axis_in_2.push_back(static_cast<NumT>(1.));
  axis_in_2.push_back(static_cast<NumT>(2.));
  axis_in_2.push_back(static_cast<NumT>(3.));
  axis_in_2.push_back(static_cast<NumT>(4.));

  axis_out_1.push_back(static_cast<NumT>(0.));
  axis_out_1.push_back(static_cast<NumT>(1.33333));
  axis_out_1.push_back(static_cast<NumT>(2.66666));
  axis_out_1.push_back(static_cast<NumT>(4.));

  axis_out_2.push_back(static_cast<NumT>(0.));
  axis_out_2.push_back(static_cast<NumT>(2.));
  axis_out_2.push_back(static_cast<NumT>(4.));

  input.push_back(static_cast<NumT>(10.));
  input.push_back(static_cast<NumT>(10.));
  input.push_back(static_cast<NumT>(10.));
  input.push_back(static_cast<NumT>(10.));

  input_err2.push_back(static_cast<NumT>(1.));
  input_err2.push_back(static_cast<NumT>(1.));
  input_err2.push_back(static_cast<NumT>(1.));
  input_err2.push_back(static_cast<NumT>(1.));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis\_in\_1\f$, \f$axis\_in\_2\f$, \f$axis\_out\_1\f$,
 * \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$ for the float case.
 *
 * \param true_output (OUTPUT) is the true output
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * true output
 *
 */
void initialize_true_outputs(Nessi::Vector<float> & true_output,
                             Nessi::Vector<float> & true_output_err2)
{
  true_output.push_back(static_cast<float>(13.33330049));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(6.66669938));
  true_output.push_back(static_cast<float>(6.66660067));
  true_output.push_back(static_cast<float>(0.0));
  true_output.push_back(static_cast<float>(13.33339905));

  true_output_err2.push_back(static_cast<float>(1.11110894));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(0.44444882));
  true_output_err2.push_back(static_cast<float>(0.44443565));
  true_output_err2.push_back(static_cast<float>(0.0));
  true_output_err2.push_back(static_cast<float>(1.11111551));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$axis\_in\_1\f$, \f$axis\_in\_2\f$, \f$axis\_out\_1\f$,
 * \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$ for the double case.
 *
 * \param true_output (OUTPUT) is the true output
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * true output
 *
 */
void initialize_true_outputs(Nessi::Vector<double> & true_output,
                             Nessi::Vector<double> & true_output_err2)
{
  true_output.push_back(static_cast<double>(13.3333));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(6.66670000000000051));
  true_output.push_back(static_cast<double>(6.66659999999999808));
  true_output.push_back(static_cast<double>(0.0));
  true_output.push_back(static_cast<double>(13.3334000000000010));

  true_output_err2.push_back(static_cast<double>(1.1111088889));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(0.4444488889000001));
  true_output_err2.push_back(static_cast<double>(0.4444355555999998));
  true_output_err2.push_back(static_cast<double>(0.0));
  true_output_err2.push_back(static_cast<double>(1.1111155556));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>rebin_diagonal</i> function.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the array created by <i>rebin_diagonal</i>
 * \param output_err2 (INPUT) is the square of the uncertainty in the array
 * created by <i>rebin_diagonal</i>
 * \param true_output (INPUT) is the true array
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the true
 * array
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               Nessi::Vector<NumT> & true_output,
               Nessi::Vector<NumT> & true_output_err2)
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

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>rebin_diagonal</i> function
 * (as described in the documentation of the <i>rebin_diagonal</i> function)
 * and launches the comparison of the data.
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
  Nessi::Vector<NumT> axis_in_1;
  Nessi::Vector<NumT> axis_in_2;
  Nessi::Vector<NumT> axis_out_1;
  Nessi::Vector<NumT> axis_out_2;
  Nessi::Vector<NumT> input;
  Nessi::Vector<NumT> input_err2;
  Nessi::Vector<NumT> true_output;
  Nessi::Vector<NumT> true_output_err2;

  // fill in values as appropriate
  initialize_inputs(axis_in_1, axis_in_2, axis_out_1, axis_out_2,
                    input, input_err2);
  initialize_true_outputs(true_output, true_output_err2);

  // allocate output arrays
  Nessi::Vector<NumT> output((axis_out_1.size()-1)*(axis_out_2.size()-1));
  Nessi::Vector<NumT> output_err2((axis_out_1.size()-1)*
                                  (axis_out_2.size()-1));

  // run the code being tested
  AxisManip::rebin_diagonal(axis_in_1, axis_in_2, input, input_err2,
                            axis_out_1, axis_out_2, output, output_err2);

  if(!debug.empty())
    {
      cout << endl;
      cout << output.size() << " " << output_err2.size() << endl;
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug);
    }

  return test_okay(output, output_err2, true_output, true_output_err2);
}

/**
 * Main function that test rebin_diagonal for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "rebin_diagonal_test.cpp..........";

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
 */  // end of rebin_diagonal_test group
