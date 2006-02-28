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
 * \file axis_manip/test/cpp/reverse_array_nc_test.cpp
 */

#include "reverse_array.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup reverse_array_nc_test reverse_array_nc_test
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>reverse_array_nc</i> and not described but based on
 * the section 3.11 of the <i>SNS 107030214-TD0001-R00, 
 * "Data Reduction Library Software Requirements and Specifications"</i> 
 * with the true output data  \f$true\_output\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.

/**
 * This function initializes the value of the array, \f$input\f$.
 *
 * \param input (OUTPUT) is the array to be reversed
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      input.push_back(static_cast<NumT>(i+1));
    }
}

/**
 * This function sets the true outputs based on values contained in
 * \f$input\f$.
 *
 * \param true_output (OUTPUT) is the true output.
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output)
{
  true_output.push_back(static_cast<NumT>(5));
  true_output.push_back(static_cast<NumT>(4));
  true_output.push_back(static_cast<NumT>(3));
  true_output.push_back(static_cast<NumT>(2));
  true_output.push_back(static_cast<NumT>(1));
}

/* Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>reverse_array_nc</i> function.
 * 
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the array created by <i>reverse_array_nc</i>
 * \param output (INPUT) is the true array
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & true_output)
{
  return test_okay(output,true_output,VV);
}

/**
 * Function that generates the data using the <i>reverse_array_nc</i> function
 * (as described in the documentation of the <i>reverse_array_cp</i> function)
 * and launches the comparison of the data. 
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  Nessi::Vector<NumT> input;
  Nessi::Vector<NumT>   true_output;

  // fill in values as appropriate
  initialize_inputs(input);
  initialize_true_outputs(true_output);

  // run the code being tested
  AxisManip::reverse_array_nc(input);

  if(!debug.empty())
    {
      cout << endl;
      print(input, true_output, VV, debug);
    }

  return test_okay(input, true_output);
}

/**
 * Main function that test reverse_array_nc for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "reverse_array_nc_test.cpp..........";

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
