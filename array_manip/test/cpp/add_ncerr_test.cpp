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
 * \file array_manip/test/cpp/add_ncerr_test.cpp
 */

#include "arith.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL = 5;
const int SCALE = 2;

/**
 * \defgroup add_ncerr_test add_ncerr_test
 * \{
 *
 * This test compares the output data (\f$output\_vs\f$ and \f$output\_vv\f$)
 * calculated by the library function <i>add_ncerr</i> and described in
 * section 3.1 and 3.6 of the <i>SNS 107030214-TD0001-R00, "Data Reduction
 * Library Software Requirements and Specifications"</i> with the true output
 * data (\f$true\_output\_vs\f$ and \f$true\_output\_vv\f$) manually
 * calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notations used:</b>
 * - vv : vector-vector
 * - vs : vector-scalar
 * - VV = "v,v"
 * - SV = "s,v"
 * - VS = "v,s"
 * - ERROR = "error "
 * - EMPTY = ""
 */

/**
 *
 * This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
 * \f$input1\_err2\f$, and \f$input2\_err2\f$.
 *
 * \param input1 (OUTPUT) is the first array to be added
 * \param input1_err2 (OUTPUT) is the square of the uncertainty in the first
 * array to be added
 * \param input2 (OUTPUT) is the second array to be added
 * \param input2_err2 (OUTPUT) is the square of the uncertainty in the second
 * array to be added
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2,
                       Nessi::Vector<NumT> & input2,
                       Nessi::Vector<NumT> & input2_err2,
                       Nessi::Vector<NumT> & input3,
                       Nessi::Vector<NumT> & input3_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>(NUM_VAL+1-i)); // 6,5,4,3,2
      input2.push_back(static_cast<NumT>(i));           // 0,1,2,3,4
      input3.push_back(static_cast<NumT>(i)); 
      input1_err2.push_back(static_cast<NumT>(1.));
      input2_err2.push_back(static_cast<NumT>(1.));
      input3_err2.push_back(static_cast<NumT>(1.));
    }
  for( int i=NUM_VAL ; i < NUM_VAL*SCALE; ++i)
    {
      input3.push_back(static_cast<NumT>(i));
      input3_err2.push_back(static_cast<NumT>(1.));
    }
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$, \f$input2\f$, \f$input1\_err2\f$, and \f$input2\_err2\f$.
 *
 * For the vs case, the scalar used is the last element
 * of the array \f$input2\f$, \f$input2[NUM\_VAL - 1]\f$
 *
 * where \f$NUM\_VAL\f$ is the number of element of the arrays.
 *
 * \param true_output_vs (OUTPUT) is the true array for the
 * vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vs case
 * \param true_output_vv (OUTPUT) is the true array for the
 * vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vv case
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output_vs,
                             Nessi::Vector<NumT> & true_output_vs_err2,
                             Nessi::Vector<NumT> & true_output_vv,
                             Nessi::Vector<NumT> & true_output_vv_err2)
{
  // initialize the correct outputs for vector vector case
  true_output_vv.push_back(static_cast<NumT>(6.)); // =0+6
  true_output_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_vv.push_back(static_cast<NumT>(6.)); // =1+5
  true_output_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_vv.push_back(static_cast<NumT>(6.)); // =2+4
  true_output_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_vv.push_back(static_cast<NumT>(6.)); // =3+3
  true_output_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_vv.push_back(static_cast<NumT>(6.)); // =4+2
  true_output_vv_err2.push_back(static_cast<NumT>(2.));

  // initialize the correct true_outputs for vector scalar case
  true_output_vs.push_back(static_cast<NumT>(10.)); // =4+6
  true_output_vs_err2.push_back(static_cast<NumT>(2.));
  true_output_vs.push_back(static_cast<NumT>(9.));  // =4+5
  true_output_vs_err2.push_back(static_cast<NumT>(2.));
  true_output_vs.push_back(static_cast<NumT>(8.));  // =4+4
  true_output_vs_err2.push_back(static_cast<NumT>(2.));
  true_output_vs.push_back(static_cast<NumT>(7.));  // =4+3
  true_output_vs_err2.push_back(static_cast<NumT>(2.));
  true_output_vs.push_back(static_cast<NumT>(6.));  // =4+2
  true_output_vs_err2.push_back(static_cast<NumT>(2.));
}

/**
 * Function that sets the true outputs based on values contained in
 * \f$input1\f$, \f$input2\f$, \f$input1\_err2\f$, and \f$input2\_err2\f$.
 *
 * For the vs case, the scalar used is the last element
 * of the array \f$input2\f$, \f$input2[NUM\_VAL - 1]\f$
 *
 * where \f$NUM\_VAL\f$ is the number of element of the arrays.
 *
 * \param true_output_vs (OUTPUT) is the true array for the
 * vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vs case
 * \param true_output_vv (OUTPUT) is the true array for the
 * vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vv case
 */
template <typename NumT>
void initialize_true_outputs_mul(Nessi::Vector<NumT> & true_output_mul_vv,
                                 Nessi::Vector<NumT> & true_output_mul_vv_err2)
{
  // initialize the correct outputs for vector vector case
  true_output_mul_vv.push_back(static_cast<NumT>(0.)); // =0+0
  true_output_mul_vv_err2.push_back(static_cast<NumT>(1.));
  true_output_mul_vv.push_back(static_cast<NumT>(1.)); // =1+0
  true_output_mul_vv_err2.push_back(static_cast<NumT>(1.));
  true_output_mul_vv.push_back(static_cast<NumT>(2.)); // =2+0
  true_output_mul_vv_err2.push_back(static_cast<NumT>(1.));
  true_output_mul_vv.push_back(static_cast<NumT>(3.)); // =3+0
  true_output_mul_vv_err2.push_back(static_cast<NumT>(1.));
  true_output_mul_vv.push_back(static_cast<NumT>(4.)); // =4+0
  true_output_mul_vv_err2.push_back(static_cast<NumT>(1.));
  true_output_mul_vv.push_back(static_cast<NumT>(11.)); // =5+6
  true_output_mul_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_mul_vv.push_back(static_cast<NumT>(11.)); // =6+5
  true_output_mul_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_mul_vv.push_back(static_cast<NumT>(11.)); // =7+4
  true_output_mul_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_mul_vv.push_back(static_cast<NumT>(11.)); // =8+3
  true_output_mul_vv_err2.push_back(static_cast<NumT>(2.));
  true_output_mul_vv.push_back(static_cast<NumT>(11.)); // =9+2
  true_output_mul_vv_err2.push_back(static_cast<NumT>(2.));
}

/**
 * Function that tests the discrepancies between the outputs
 * generated by the <i>add_ncerr</i> function for the vs and vv cases.
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_vs (INPUT) is the array created by <i>add_ncerr</i>
 * for the vs case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the
 * array created by <i>add_ncerr</i> for the vs case
 * \param true_output_vs (INPUT) is the true array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vs case
 * \param output_vv (INPUT) is the array created by <i>add_ncerr</i>
 * for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the
 * array created by <i>add_ncerr</i> for the vv case
 * \param true_output_vv (INPUT) is the true array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vv case
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2,
               Nessi::Vector<NumT> & output_mul_vv,
               Nessi::Vector<NumT> & output_mul_vv_err2,
               Nessi::Vector<NumT> & true_output_mul_vv,
               Nessi::Vector<NumT> & true_output_mul_vv_err2)
{
  bool value = true;

  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS,ERROR))
    {
      value = false;
    }

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV,ERROR))
    {
      value = false;
    }

  // multi-dimensional vector vector
  if(!test_okay(output_mul_vv,true_output_mul_vv,VV))
    {
      value = false;
    }
  if(!test_okay(output_mul_vv_err2,true_output_mul_vv_err2,VV,ERROR))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>add_ncerr</i> function
 * (as described in the documentation of the <i>add_ncerr</i> function)
 * and launches the comparison of the data.
 *
 * \param key (INPUT) key that permits to launch the correct test
 * \param debug (INPUT) is any string that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
 */
template <typename NumT>
bool test_func(NumT key, string debug){ // key forces correct test to happen
  // allocate arrays
  Nessi::Vector<NumT> input1;
  Nessi::Vector<NumT> input1_err2;
  Nessi::Vector<NumT> input2;
  Nessi::Vector<NumT> input2_err2;

  Nessi::Vector<NumT> output_vs(NUM_VAL);
  Nessi::Vector<NumT> output_vs_err2(NUM_VAL);
  Nessi::Vector<NumT> output_vv(NUM_VAL);
  Nessi::Vector<NumT> output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // multi-dimensional allocation
  Nessi::Vector<NumT> input3;
  Nessi::Vector<NumT> input3_err2;
  Nessi::Vector<NumT> true_output_mul_vv;
  Nessi::Vector<NumT> true_output_mul_vv_err2;

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2,input3,input3_err2);
  initialize_true_outputs(true_output_vs,true_output_vs_err2,
                          true_output_vv,true_output_vv_err2);
  initialize_true_outputs_mul(true_output_mul_vv,true_output_mul_vv_err2);


  // run the code being tested
  ArrayManip::add_ncerr(input1, input1_err2, input2, input2_err2,
                        output_vv, output_vv_err2);
  ArrayManip::add_ncerr(input1, input1_err2,
                        input2[NUM_VAL-1], input2_err2[NUM_VAL-1],
                        output_vs, output_vs_err2);
  ArrayManip::add_ncerr(input3, input3_err2, NUM_VAL, 1, 
                        input1, input1_err2, 0, 1, input1.size(),
                        input3, input3_err2, NUM_VAL, 1);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv, true_output_vv, VV, debug);
      print(output_vv_err2, true_output_vv_err2, ERROR+VV, debug);
      print(output_vs, true_output_vs, VS, debug);
      print(output_vs_err2, true_output_vs_err2, ERROR+VS, debug);
      print(input3, true_output_mul_vv, VV, debug);
      print(input3_err2, true_output_mul_vv_err2, ERROR+VV, debug);
    }

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2,
                   input3, input3_err2,
                   true_output_mul_vv, true_output_mul_vv_err2);
}

/**
 * Main function that tests <i>add_ncerr</i> for
 * float, double, int and unsigned int.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "add_ncerr_test.cpp..........";

  string debug;
  if (argc >1)
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

  int value = 0;

  if(!test_func(static_cast<int>(1), debug))
    {
      value = -1;
    }

  if(!test_func(static_cast<unsigned int>(1), debug))
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
 */   //end of add_ncerr_test group
