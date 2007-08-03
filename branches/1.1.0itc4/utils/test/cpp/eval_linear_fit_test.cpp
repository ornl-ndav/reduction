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
 * \file utils/test/cpp/eval_linear_fit_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup eval_linear_fit_test eval_linear_fit_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>eval_linear_fit</i> and described in section 3.56 of the
 * <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications"</i> with the true output data (\f$true\_output\f$)
 * manually calculated.
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
 * This function initializes the values of arrays, \f$axis1\f$ and 
 * \f$axis1\_err2\f$.
 *
 * \param axis1 (OUTPUT) is the array of independent axis values to have the 
 * linear fit function evaluated from
 * \param axis1_err2 (OUTPUT) is the square of the uncertainty associated
 * with the array of independent axis values.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis1,
                       Nessi::Vector<NumT> & axis1_err2)
{
  axis1.push_back(static_cast<NumT>(1.0));
  axis1.push_back(static_cast<NumT>(2.0));
  axis1.push_back(static_cast<NumT>(3.0));
  axis1.push_back(static_cast<NumT>(4.0));
  axis1.push_back(static_cast<NumT>(5.0));

  axis1_err2.push_back(static_cast<NumT>(0.));
  axis1_err2.push_back(static_cast<NumT>(0.));
  axis1_err2.push_back(static_cast<NumT>(0.));
  axis1_err2.push_back(static_cast<NumT>(0.));
  axis1_err2.push_back(static_cast<NumT>(0.));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$axis1\f$ and \f$axis1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the linear fit function
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of 
 * the true value of the linear fit function
 */
void initialize_true_outputs(Nessi::Vector<float> & true_output,
                             Nessi::Vector<float> & true_output_err2)
{
  // initialize the correct outputs
  // vector-vector
  true_output.push_back(static_cast<float>(3.0183015));
  true_output.push_back(static_cast<float>(5.0092858));
  true_output.push_back(static_cast<float>(7.0002701));
  true_output.push_back(static_cast<float>(8.9912544));
  true_output.push_back(static_cast<float>(10.9822386));

  true_output_err2.push_back(static_cast<float>(1.3007042e-01));
  true_output_err2.push_back(static_cast<float>(1.6353401e-01));
  true_output_err2.push_back(static_cast<float>(2.1930666e-01));
  true_output_err2.push_back(static_cast<float>(2.9738838e-01));
  true_output_err2.push_back(static_cast<float>(3.9777915e-01));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$axis1\f$ and \f$axis1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the linear fit function
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of 
 * the true value of the linear fit function
 */
void initialize_true_outputs(Nessi::Vector<double> & true_output,
                             Nessi::Vector<double> & true_output_err2)
{
  // initialize the correct outputs

  // vector-vector
  true_output.push_back(static_cast<double>(3.01830147798497883));
  true_output.push_back(static_cast<double>(5.00928576955814275));
  true_output.push_back(static_cast<double>(7.00027006113130668));
  true_output.push_back(static_cast<double>(8.99125435270446971));
  true_output.push_back(static_cast<double>(10.9822386442776327));

  true_output_err2.push_back(static_cast<double>(1.30070417085816042e-01));
  true_output_err2.push_back(static_cast<double>(1.63534009131006797e-01));
  true_output_err2.push_back(static_cast<double>(2.19306662539658082e-01));
  true_output_err2.push_back(static_cast<double>(2.97388377311769814e-01));
  true_output_err2.push_back(static_cast<double>(3.97779153447342104e-01));
}

/**
 * Function that tests the discrepancies between the outputs generated by the 
 * <i>eval_linear_fit</i> function. The function returns TRUE if the two 
 * values compared \f$output\_slope\f$ and \f$true\_output\_slope\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>eval_linear_fit</i> for 
 * the value of the linear fit function
 * \param output_err2 (INPUT) is the square of the uncertainty in the value 
 * created by <i>eval_linear_fit</i> for the value of the linear fit function
 * \param true_output (INPUT) is the true value of the value of the linear fit 
 * function
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the 
 * true value of the value of the linear fit function
 */
template <typename NumT>
bool test_okay(NumT & output,
               NumT & output_err2,
               NumT & true_output,
               NumT & true_output_err2)
{
  bool value = true;

  // scalar scalar comparison
  if(!test_okay(output, true_output, VV))
    {
      value = false;
    }
  if(!test_okay(output_err2, true_output_err2, VV, ERROR))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>eval_linear_fit</i> 
 * function (as described in the documentation of the 
 * <i>eval_linear_fit</i> function) and launches the comparison of the 
 * data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 */
template <typename NumT>
bool test_func(NumT key, string debug)
{ 
  // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> axis1;
  Nessi::Vector<NumT> axis1_err2;
  NumT slope = static_cast<NumT>(1.99098429157316348);
  NumT slope_err2 = static_cast<NumT>(1.11545306817302532e-02);
  NumT intercept = static_cast<NumT>(1.02731718641181557);
  NumT intercept_err2 = static_cast<NumT>(1.18915886404085791e-01);
  Nessi::Vector<NumT> output(NUM_VAL);
  Nessi::Vector<NumT> output_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output;
  Nessi::Vector<NumT> true_output_err2;

  // fill in values as appropriate
  initialize_inputs(axis1, axis1_err2);
  initialize_true_outputs(true_output, true_output_err2);

  // run the code being tested
  Utils::eval_linear_fit(axis1, axis1_err2, slope, slope_err2, 
                         intercept, intercept_err2, output, output_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug); 
    }

  return test_okay(output, output_err2, true_output, true_output_err2);
}

/**
 * Main function that tests <i>eval_linear_fit</i> for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "eval_linear_fit_test.cpp..........";

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
 */   //end of eval_linear_fit_test group
