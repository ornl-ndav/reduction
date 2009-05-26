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
 * \file utils/test/cpp/calc_eq_jacobian_dgs_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup calc_eq_jacobian_dgs_test calc_eq_jacobian_dgs_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>calc_eq_jacobian_dgs</i> and described in section 3.68 of the
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
 * This function initializes the values of the vertex coordinate arrays
 *
 * \param e1_axis (OUTPUT) is the first energy transfer vertex coordinate array
 * \param e2_axis (OUTPUT) is the second energy transfer vertex coordinate 
 * array
 * \param e3_axis (OUTPUT) is the third energy transfer vertex coordinate array
 * \param e4_axis (OUTPUT) is the fourth energy transfer vertex coordinate 
 * array
 * \param q1_axis (OUTPUT) is the first momentum transfer vertex coordinate 
 * array
 * \param q2_axis (OUTPUT) is the second momentum transfer vertex coordinate
 * array
 * \param q3_axis (OUTPUT) is the third momentum transfer vertex coordinate 
 * array
 * \param q4_axis (OUTPUT) is the fourth momentum transfer vertex coordinate
 * array
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & e1_axis,
                       Nessi::Vector<NumT> & e2_axis,
                       Nessi::Vector<NumT> & e3_axis,
                       Nessi::Vector<NumT> & e4_axis,
                       Nessi::Vector<NumT> & q1_axis,
                       Nessi::Vector<NumT> & q2_axis,
                       Nessi::Vector<NumT> & q3_axis,
                       Nessi::Vector<NumT> & q4_axis)

{
  for( int i=0 ; i<NUM_VAL; i++ )
    {
      e1_axis.push_back(static_cast<NumT>(i)); // 0,1,2,3,4
      e2_axis.push_back(static_cast<NumT>(i+1)); // 1,2,3,4,5
      e3_axis.push_back(static_cast<NumT>(i+1.5)); // 1.5,2.5,3.5,4.5,5.5
      e4_axis.push_back(static_cast<NumT>(i+0.5)); // 0.5,1.5,2.5,3.5,4.5
      q1_axis.push_back(static_cast<NumT>(0.)); // 0,0,0,0,0
      q2_axis.push_back(static_cast<NumT>(0.)); // 0,0,0,0,0
      q3_axis.push_back(static_cast<NumT>(1.)); // 1,1,1,1,1
      q4_axis.push_back(static_cast<NumT>(1.)); // 1,1,1,1,1
    }
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$e1\_axis\f$, \f$e2\_axis\f$, \f$e3\_axis\f$, \f$e4\_axis\f$, 
 * \f$q1\_axis\f$, \f$q2\_axis\f$, \f$q3\_axis\f$ and \f$q4\_axis\f$
 *
 * \param true_output (OUTPUT) is the true value of the calculated jacobian
 */
void initialize_true_outputs(Nessi::Vector<float> & true_output)
{
  // initialize the correct outputs

  // vector-vector
  true_output.push_back(static_cast<float>(1.0));
  true_output.push_back(static_cast<float>(1.0));
  true_output.push_back(static_cast<float>(1.0));
  true_output.push_back(static_cast<float>(1.0));
  true_output.push_back(static_cast<float>(1.0));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$e1\_axis\f$, \f$e2\_axis\f$, \f$e3\_axis\f$, \f$e4\_axis\f$, 
 * \f$q1\_axis\f$, \f$q2\_axis\f$, \f$q3\_axis\f$ and \f$q4\_axis\f$
 *
 * \param true_output (OUTPUT) is the true value of the calculated jacobian
 */
void initialize_true_outputs(Nessi::Vector<double> & true_output)
{
  // initialize the correct outputs

  // vector-vector
  true_output.push_back(static_cast<double>(1.0));
  true_output.push_back(static_cast<double>(1.0));
  true_output.push_back(static_cast<double>(1.0));
  true_output.push_back(static_cast<double>(1.0));
  true_output.push_back(static_cast<double>(1.0));
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>calc_eq_jacobian_dgs</i> function. The function returns
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>calc_eq_jacobian_dgs</i>
 * \param true_output (INPUT) is the true value of the calculate bin widths
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & true_output)
{
  bool value = true;

  // vector vector comparison
  if(!test_okay(output, true_output, VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>calc_eq_jacobian_dgs</i> 
 * function (as described in the documentation of the 
 * <i>calc_eq_jacobian_dgs</i> function) and launches the comparison of the 
 * data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 */
template <typename NumT>
bool test_func(NumT key, string debug){ // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> e1_axis;
  Nessi::Vector<NumT> e2_axis;
  Nessi::Vector<NumT> e3_axis;
  Nessi::Vector<NumT> e4_axis;
  Nessi::Vector<NumT> q1_axis;
  Nessi::Vector<NumT> q2_axis;
  Nessi::Vector<NumT> q3_axis;
  Nessi::Vector<NumT> q4_axis;
  Nessi::Vector<NumT> output(NUM_VAL);
  Nessi::Vector<NumT> true_output;

  // fill in values as appropriate
  initialize_inputs(e1_axis, e2_axis, e3_axis, e4_axis, 
                    q1_axis, q2_axis, q3_axis, q4_axis);
  initialize_true_outputs(true_output);

  // run the code being tested
  Utils::calc_eq_jacobian_dgs(e1_axis, e2_axis, e3_axis, e4_axis, 
                              q1_axis, q2_axis, q3_axis, q4_axis, output);
  
  if(!debug.empty())
    {
      cout << endl;
      print(output, true_output, VV, debug);
    }

  return test_okay(output, true_output);
}

/**
 * Main function that tests <i>calc_eq_jacobian_dgs</i> for float and double
 *
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "calc_eq_jacobian_dgs_test.cpp..........";

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
 */   //end of calc_eq_jacobian_dgs_test group
