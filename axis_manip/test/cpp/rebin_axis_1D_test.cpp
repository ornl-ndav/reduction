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

#include "rebinning.hpp"
#include "test_common.hpp"

using namespace std;

/**
 * \defgroup rebin_array_1D_test rebin_array_1D_test
 *
 * This test compares the output data calculated by the library
 * function rebin_array_1D() as described in 3.12 of the DR_Lib_RS_q
 * with the true output data manually calculated. Any discrepancy
 * between the outputs will generate an error message in the
 * testsuite.log file that gives details about the location and type
 * of the error.
 */

/**
 * This function initiales the input arrays.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis_in,
                       Nessi::Vector<NumT> & axis_out,
                       Nessi::Vector<NumT> & input,
                       Nessi::Vector<NumT> & input_err2)
{
  axis_in.push_back(static_cast<NumT>(0.));
  axis_in.push_back(static_cast<NumT>(1.));
  axis_in.push_back(static_cast<NumT>(2.));
  axis_in.push_back(static_cast<NumT>(3.));

  axis_out.push_back(static_cast<NumT>(0.));
  axis_out.push_back(static_cast<NumT>(1.5));
  axis_out.push_back(static_cast<NumT>(3.));

  input.push_back(static_cast<NumT>(10.));
  input.push_back(static_cast<NumT>(20.));
  input.push_back(static_cast<NumT>(30.));

  input_err2.push_back(static_cast<NumT>(1.));
  input_err2.push_back(static_cast<NumT>(4.));
  input_err2.push_back(static_cast<NumT>(9.));
}

/**
 * This function generate the values to compare the calculation to.
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output,
                             Nessi::Vector<NumT> & true_output_err2)
{
  true_output.push_back(static_cast<NumT>(20));
  true_output.push_back(static_cast<NumT>(40));

  true_output_err2.push_back(static_cast<NumT>(2));
  true_output_err2.push_back(static_cast<NumT>(10));
}

/**
 * This functions compares the expected with calculated values.
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               Nessi::Vector<NumT> & true_output,
               Nessi::Vector<NumT> & true_output_err2)
{
  bool value = true;

  if(!test_okay(output,true_output,VV))
    {
      value = false;
    }

  if(!test_okay(output_err2,true_output_err2,VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that runs the test for a numeric type
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  Nessi::Vector<NumT>   axis_in;
  Nessi::Vector<NumT>   axis_out;
  Nessi::Vector<NumT>   input;
  Nessi::Vector<NumT>   input_err2;
  Nessi::Vector<NumT>   output(2);
  Nessi::Vector<NumT>   output_err2(2);
  Nessi::Vector<NumT>   true_output;
  Nessi::Vector<NumT>   true_output_err2;

  // fill in values as appropriate
  initialize_inputs(axis_in,axis_out,input,input_err2);
  initialize_true_outputs(true_output,true_output_err2);

  // run the code being tested
  AxisManip::rebin_axis_1D(axis_in,input,input_err2,axis_out,
                           output,output_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug);
    }

  return test_okay(output, output_err2, true_output, true_output_err2);
}

/**
 * Main function that test energy_transfer for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "rebin_axis_1D_test.cpp..........";

  string debug;
  if(argc > 1)
    {
      debug = argv[1];
    }

  if(!test_func(static_cast<float>(1), debug))
    {
      return -1;
    }

  if(!test_func(static_cast<double>(1), debug))
    {
      return -1;
    }

  cout << "Functionality OK" << endl;

  return 0;
}
