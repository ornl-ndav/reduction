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
 * \file utils/test/cpp/fit_linear_background_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup fit_linear_background_test fit_linear_background_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>fit_linear_background</i> and described in section 3.43 of the
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
 * This function initializes the values of arrays, \f$axis1\f$, \f$input1\f$ 
 * and \f$input1\_err2\f$.
 *
 * \param axis1 (OUTPUT) is the array of independent values to have the fit 
 * linear background calculated from
 * \param input1 (OUTPUT) is the array to have the fit linear background 
 * calculated from
 * \param input1_err2 (OUTPUT) is the square of the uncertainty associated
 * with the value array.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & axis1,
                       Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2)
{
  axis1.push_back(static_cast<NumT>(1.0));
  axis1.push_back(static_cast<NumT>(2.0));
  axis1.push_back(static_cast<NumT>(3.0));
  axis1.push_back(static_cast<NumT>(4.0));
  axis1.push_back(static_cast<NumT>(5.0));

  input1.push_back(static_cast<NumT>(3.05));
  input1.push_back(static_cast<NumT>(4.95));
  input1.push_back(static_cast<NumT>(7.02));
  input1.push_back(static_cast<NumT>(9.01));
  input1.push_back(static_cast<NumT>(10.97));

  input1_err2.push_back(static_cast<NumT>(0.11));
  input1_err2.push_back(static_cast<NumT>(0.1));
  input1_err2.push_back(static_cast<NumT>(0.09));
  input1_err2.push_back(static_cast<NumT>(0.1));
  input1_err2.push_back(static_cast<NumT>(0.12));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$axis1\f$, \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output_slope (OUTPUT) is the true value of the line slope
 * \param true_output_slope_err2 (OUTPUT) is the square of the uncertainty of 
 * the line slope
 * \param true_output_intercept (OUTPUT) is the true value of the line 
 * intercept
 * \param true_output_intercept_err2 (OUTPUT) is the square of the uncertainty 
 * of the line intercept
 */
void initialize_true_outputs(float & true_output_slope,
                             float & true_output_slope_err2,
                             float & true_output_intercept,
                             float & true_output_intercept_err2)
{
  // initialize the correct outputs
#ifdef LINUX
  true_output_slope = static_cast<float>(1.9909854);
  true_output_intercept = static_cast<float>(1.0273134);
#else
  true_output_slope = static_cast<float>(1.9909847);
  true_output_intercept = static_cast<float>(1.0273158);
#endif
  true_output_slope_err2 = static_cast<float>(1.1154531e-02);
  true_output_intercept_err2 = static_cast<float>(1.1891589e-01);
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$axis1\f$, \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output_slope (OUTPUT) is the true value of the line slope
 * \param true_output_slope_err2 (OUTPUT) is the square of the uncertainty of 
 * the line slope
 * \param true_output_intercept (OUTPUT) is the true value of the line 
 * intercept
 * \param true_output_intercept_err2 (OUTPUT) is the square of the uncertainty 
 * of the line intercept
 */
void initialize_true_outputs(double & true_output_slope,
                             double & true_output_slope_err2,
                             double & true_output_intercept,
                             double & true_output_intercept_err2)
{
  // initialize the correct outputs
#ifdef LINUX
  true_output_slope = static_cast<double>(1.99098429157316548);
  true_output_intercept = static_cast<double>(1.02731718641181979);
#else
  true_output_slope = static_cast<double>(1.99098429157316348);
  true_output_intercept = static_cast<double>(1.02731718641181557);
#endif
  true_output_slope_err2 = static_cast<double>(1.11545306817302532e-02);
  true_output_intercept_err2 = static_cast<double>(1.18915886404085791e-01);
}

/**
 * Function that tests the discrepancies between the outputs generated by the 
 * <i>fit_linear_background</i> function. The function returns TRUE if the two 
 * values compared \f$output\_slope\f$ and \f$true\_output\_slope\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output_slope (INPUT) is the value created by 
 * <i>fit_linear_background</i> for the line slope
 * \param output_slope_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>fit_linear_background</i> for the line slope
 * \param output_intercept (INPUT) is the value created by 
 * <i>fit_linear_background</i> for the line intercept
 * \param output_intercept_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>fit_linear_background</i> for the line intercept
 * \param true_output_slope (INPUT) is the true value of the line slope
 * \param true_output_slope_err2 (INPUT) is the square of the uncertainty in 
 * the true value of the line slope
 * \param true_output_intercept (INPUT) is the true value of the line intercept
 * \param true_output_intercept_err2 (INPUT) is the square of the uncertainty 
 * in the true value of the line intercept
 */
template <typename NumT>
bool test_okay(NumT & output_slope,
               NumT & output_slope_err2,
               NumT & output_intercept,
               NumT & output_intercept_err2,
               NumT & true_output_slope,
               NumT & true_output_slope_err2,
               NumT & true_output_intercept,
               NumT & true_output_intercept_err2)
{
  bool value = true;

  // scalar scalar comparison
  if(!test_okay(output_slope, true_output_slope ,SS))
    {
      value = false;
    }
  if(!test_okay(output_slope_err2, true_output_slope_err2, SS, ERROR))
    {
      value = false;
    }
  if(!test_okay(output_intercept, true_output_intercept ,SS))
    {
      value = false;
    }
  if(!test_okay(output_intercept_err2, true_output_intercept_err2, SS, ERROR))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>fit_linear_background</i> 
 * function (as described in the documentation of the 
 * <i>fit_linear_background</i> function) and launches the comparison of the 
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
  Nessi::Vector<NumT> input1;
  Nessi::Vector<NumT> input1_err2;
  NumT output_slope;
  NumT output_slope_err2;
  NumT output_intercept;
  NumT output_intercept_err2;
  NumT true_output_slope;
  NumT true_output_slope_err2;
  NumT true_output_intercept;
  NumT true_output_intercept_err2;

  // fill in values as appropriate
  initialize_inputs(axis1, input1, input1_err2);
  initialize_true_outputs(true_output_slope, true_output_slope_err2, 
                          true_output_intercept, true_output_intercept_err2);

  // run the code being tested
  Utils::fit_linear_background(axis1, input1, input1_err2, -1, -1,
                               output_slope, output_slope_err2,
                               output_intercept, output_intercept_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_slope, true_output_slope, SS, debug);
      print(output_slope_err2, true_output_slope_err2, ERROR+SS, debug); 
      print(output_intercept, true_output_intercept, SS, debug);
      print(output_intercept_err2, true_output_intercept_err2, ERROR+SS, 
            debug); 
    }


  return test_okay(output_slope, output_slope_err2, 
                   output_intercept, output_intercept_err2,
                   true_output_slope, true_output_slope_err2,
                   true_output_intercept, true_output_intercept_err2);
}

/**
 * Main function that tests <i>fit_linear_background</i> for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "fit_linear_background_test.cpp..........";

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
 */   //end of fit_linear_background_test group
