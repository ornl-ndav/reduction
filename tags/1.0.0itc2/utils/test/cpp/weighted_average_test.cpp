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
 * \file utils/test/cpp/weighted_average_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup weighted_average_test weighted_average_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library 
 * function <i>weighted_average</i> and described in section 3.46 of the 
 * <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software Requirements 
 * and Specifications"</i> with the true output data (\f$true\_output\f$) 
 * manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of arrays, \f$input1\f$ and
 * \f$input1\_err2\f$.
 *
 * \param input1 (OUTPUT) is the array to have the weighted average calculated 
 * from
 * \param input1_err2 (OUTPUT) is the square of the uncertainty associated 
 * with the value array.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>(i+1.)); // 1,2,3,4,5
      input1_err2.push_back(static_cast<NumT>(1.));
    }
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the weighted average
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the 
 * weighted average
 */
template <typename NumT>
void initialize_true_outputs(NumT & true_output,
                             NumT & true_output_err2)
{
  // initialize the correct outputs
  true_output = static_cast<NumT>(3.);
  true_output_err2 = static_cast<NumT>(0.2);
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>weighted_average</i> function. The function returns 
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match, 
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>weighted_average</i>
 * \param output_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>weighted_average</i>
 * \param true_output (INPUT) is the true value of the weighted average
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the 
 * true value of the weighted average
 */
template <typename NumT>
bool test_okay(NumT & output,
               NumT & output_err2,
               NumT & true_output,
               NumT & true_output_err2)
{
  // scalar scalar comparison
  if(!test_okay(output,true_output,SS))
    return false;
  if(!test_okay(output_err2,true_output_err2,SS,ERROR))
    return false;

  // everything okay
  return true;
}

/**
 * Function that generates the data using the <i>weighted_average</i> function
 * (as described in the documentation of the <i>weighted_average</i> function)
 * and launches the comparison of the data. Returns the result
 * of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 */
template <typename NumT>
bool test_func(NumT key){ // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> input1;
  Nessi::Vector<NumT> input1_err2;
  NumT output;
  NumT output_err2;
  NumT true_output;
  NumT true_output_err2;

  // fill in values as appropriate
  initialize_inputs(input1, input1_err2);
  initialize_true_outputs(true_output, true_output_err2);

  // run the code being tested
  Utils::weighted_average(input1, input1_err2, static_cast<NumT>(0), 
                          static_cast<NumT>(NUM_VAL-1), output, output_err2);

  return test_okay(output, output_err2, true_output, true_output_err2);
}

/**
 * Main function that tests <i>weighted_average</i> for float and double
 */
int main()
{
  cout << "weighted_average_test.cpp..........";

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<double>(1)))
    return -1;

  cout << "Functionality OK" << endl;

  return 0;
}

/**
 * \}
 */   //end of weighted_average_test group
