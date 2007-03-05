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
 * \file utils/test/cpp/linear_order_jacobian_test.cpp
 */

#include "utils.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;

/**
 * \defgroup linear_order_jacobian_test linear_order_jacobian_test
 * \{
 *
 * This test compares the output data (\f$output\f$) calculated by the library
 * function <i>linear_order_jacobian</i> and described in section 3.49 of the
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
 * - ss : scalar-scalar
 * - SS : "s,s"
 * - ERROR = "error "
 */

/**
 *
 * This function initializes the values of arrays, \f$input1\f$ and
 * \f$input1\_err2\f$, \f$axis\_in\f$ and \f$axis\_out\f$.
 *
 * \param input1 (OUTPUT) is the array to apply the Jacobian to
 * \param input1_err2 (OUTPUT) is the square of the uncertainty associated
 * with the value array.
 * \param axis_in (OUTPUT) is the original axis associated with the value array
 * \param axis_out (OUTPUT) is the transformed axis that will 
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2,
                       Nessi::Vector<NumT> & axis_in,
                       Nessi::Vector<NumT> & axis_out)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>((i+1)*10.)); // 10,20,30,40,50
      input1_err2.push_back(static_cast<NumT>(2.*(i+1))); // 2,4,6,8,10
      axis_in.push_back(static_cast<NumT>(i+1.)); // 1,2,3,4,5
      axis_out.push_back(static_cast<NumT>(1.1*(i+1))); // 1.1,2.2,3.3,4.4,5.5
    }
  axis_in.push_back(static_cast<NumT>(NUM_VAL+1.)); // 6
  axis_out.push_back(static_cast<NumT>(1.1*(NUM_VAL+1))); // 6.6
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the weighted average
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * weighted average
 */
void initialize_true_outputs(float & true_output_ss,
                             float & true_output_ss_err2,
                             Nessi::Vector<float> & true_output,
                             Nessi::Vector<float> & true_output_err2)
{
  // initialize the correct outputs

  // scalar-scalar
  true_output_ss = static_cast<float>(9.09090909);
  true_output_ss_err2 = static_cast<float>(1.65289256);

  // vector-vector
  true_output.push_back(static_cast<float>(9.09090909));
  true_output_err2.push_back(static_cast<float>(1.65289256));
  true_output.push_back(static_cast<float>(18.18182009));
  true_output_err2.push_back(static_cast<float>(3.30578560));
  true_output.push_back(static_cast<float>(27.27272346));
  true_output_err2.push_back(static_cast<float>(4.95867673));
  true_output.push_back(static_cast<float>(36.36364017));
  true_output_err2.push_back(static_cast<float>(6.61157119));
  true_output.push_back(static_cast<float>(45.45455308));
  true_output_err2.push_back(static_cast<float>(8.26446471));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$ and \f$input1\_err2\f$.
 *
 * \param true_output (OUTPUT) is the true value of the weighted average
 * \param true_output_err2 (OUTPUT) is the square of the uncertainty of the
 * weighted average
 */
void initialize_true_outputs(double & true_output_ss,
                             double & true_output_ss_err2,
                             Nessi::Vector<double> & true_output,
                             Nessi::Vector<double> & true_output_err2)
{
  // initialize the correct outputs

  // scalar-scalar
  true_output_ss = static_cast<double>(9.09090909090908994);
  true_output_ss_err2 = static_cast<double>(1.65289256198347090);

  // vector-vector
  true_output.push_back(static_cast<double>(9.09090909090908994));
  true_output_err2.push_back(static_cast<double>(1.65289256198347090));
  true_output.push_back(static_cast<double>(18.1818181818181799));
  true_output_err2.push_back(static_cast<double>(3.30578512396694180));
  true_output.push_back(static_cast<double>(27.2727272727272728));
  true_output_err2.push_back(static_cast<double>(4.95867768595041269));
  true_output.push_back(static_cast<double>(36.3636363636363740));
  true_output_err2.push_back(static_cast<double>(6.61157024793388892));
  true_output.push_back(static_cast<double>(45.4545454545454319));
  true_output_err2.push_back(static_cast<double>(8.26446280991734739));
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>linear_order_jacobian</i> function. The function returns
 * TRUE if the two values compared \f$output\f$ and \f$true\_output\f$ match,
 * and returns FALSE if they do not match.
 *
 * \param output (INPUT) is the value created by <i>linear_order_jacobian</i>
 * \param output_err2 (INPUT) is the square of the uncertainty in the
 * value created by <i>linear_order_jacobian</i>
 * \param true_output (INPUT) is the true value of the linear order jacobian
 * \param true_output_err2 (INPUT) is the square of the uncertainty in the
 * true value of the linear order jacobian
 */
template <typename NumT>
bool test_okay(NumT    & output_ss,
               NumT    & output_ss_err2,
               NumT    & true_output_ss,
               NumT    & true_output_ss_err2,
               Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               Nessi::Vector<NumT> & true_output,
               Nessi::Vector<NumT> & true_output_err2)
{
  bool value = true;

  // scalar scalar
  if(!test_okay(output_ss,true_output_ss))
    {
      value = false;
    }
  if(!test_okay(output_ss_err2,true_output_ss_err2))
    {
      value = false;
    }

  // vector vector comparison
  if(!test_okay(output,true_output,VV))
    {
      value = false;
    }
  if(!test_okay(output_err2,true_output_err2,VV,ERROR))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>linear_order_jacobian</i> 
 * function (as described in the documentation of the 
 * <i>linear_order_jacobian</i> function) and launches the comparison of the 
 * data. Returns the result of the test_okay function (TRUE/FALSE).
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any sting that launches the debug mode (print all
 * the array created and calculated)
 */
template <typename NumT>
bool test_func(NumT key, string debug){ // key forces correct test to happen
  // allocate arrays and values
  Nessi::Vector<NumT> input1;
  Nessi::Vector<NumT> input1_err2;
  Nessi::Vector<NumT> axis_in;
  Nessi::Vector<NumT> axis_out;
  NumT                output_ss;
  NumT                output_ss_err2;
  NumT                true_output_ss;
  NumT                true_output_ss_err2;
  Nessi::Vector<NumT> output(NUM_VAL);
  Nessi::Vector<NumT> output_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output;
  Nessi::Vector<NumT> true_output_err2;

  // fill in values as appropriate
  initialize_inputs(input1, input1_err2, axis_in, axis_out);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output, true_output_err2);

  // run the code being tested
  Utils::linear_order_jacobian(axis_in, axis_out,
                               input1, input1_err2,
                               output, output_err2);
  
  Utils::linear_order_jacobian(axis_in[0], axis_in[1], 
                               axis_out[0], axis_out[1],
                               input1[0], input1_err2[0],
                               output_ss, output_ss_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug); 
      print(output, true_output, VV, debug);
      print(output_err2, true_output_err2, ERROR+VV, debug); 
    }

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2, 
                   output, output_err2, 
                   true_output, true_output_err2);
}

/**
 * Main function that tests <i>linear_order_jacobian</i> for float and double
 *
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "linear_order_jacobian_test.cpp..........";

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
 */   //end of linear_order_jacobian_test group
