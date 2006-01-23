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

// $Id$

#include "arith.hpp"
#include "test_common.hpp"
#include <iostream>

using namespace std;

const int NUM_VAL=5;

/**
 * \ingroup mult_ncerr_test
 *
 * This test compares the output data (\f$output_vs\f$ and \f$output_vv\f$)
 * calculated by the library function mult_ncerr and described in
 * section 3.3 and 3.8 of the DR_Lib_RS_1 with the true output data
 * (\f$true_output_vs\f$ and (\f$true_output_vv\f$) manually calculated .
 * Any discrepancy between the outputs (\f$output\f$ and \f$true_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * Notation used:
 * vv : vector-vector
 * vs : vector-scalar
 * VV = "v,v"
 * SV = "s,v"
 * VS = "v,s"
 * ERROR = "error "
 * EMPTY = ""
 */

/**
 * \ingroup initialize_inputs
 *
 * This function initializes \f$NUM_VAL\f$ values of each array, \f$input1\f$
 * and \f$input2\f$.
 *
 * \param input1 (OUTPUT) is the first array to be multiplied
 * \param input1_err2 (OUTPUT) is the square of the uncertainty in the first
 * array to be multiplied
 * \param input2 (OUTPUT) is the second array to be multiplied
 * \param input2_err2 (OUTPUT) is the square of the uncertainty in the second
 * array to be multiplied
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2,
                       Nessi::Vector<NumT> & input2,
                       Nessi::Vector<NumT> & input2_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>(NUM_VAL+1-i)); // 6,5,4,3,2
      input2.push_back(static_cast<NumT>(i));           // 0,1,2,3,4
      input1_err2.push_back(static_cast<NumT>(1.));
      input2_err2.push_back(static_cast<NumT>(1.));
    }
}

/**
 * Function that generates the true outputs using \f$input1\f$ and
 * \f$input2\f$.
 * For the vs case, the scalar used is the last element
 * of the array \f$input2\f$, \f$input2[NUM\_VAL]\f$.
 *
 * \param true_output_vs (OUTPUT) is the true result array for the
 * vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty
 * in the true result array for the vs case
 * \param true_output_vv (OUTPUT) is the true result array for the
 * vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty
 * in the true result array for the vv case
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output_vs,
                                  Nessi::Vector<NumT> & true_output_vs_err2,
                                  Nessi::Vector<NumT> & true_output_vv,
                                  Nessi::Vector<NumT> & true_output_vv_err2)
{
  // initialize the correct true_outputs for vector vector case
  true_output_vv.push_back(static_cast<NumT>(0.)); // =0*6
  true_output_vv_err2.push_back(static_cast<NumT>(36.));
  true_output_vv.push_back(static_cast<NumT>(5.)); // =1*5
  true_output_vv_err2.push_back(static_cast<NumT>(26.));
  true_output_vv.push_back(static_cast<NumT>(8.)); // =2*4
  true_output_vv_err2.push_back(static_cast<NumT>(20.));
  true_output_vv.push_back(static_cast<NumT>(9.)); // =3*3
  true_output_vv_err2.push_back(static_cast<NumT>(18.));
  true_output_vv.push_back(static_cast<NumT>(8.)); // =4*2
  true_output_vv_err2.push_back(static_cast<NumT>(20.));

  // initialize the correct true_outputs for vector scalar case
  true_output_vs.push_back(static_cast<NumT>(24.)); // =4*6
  true_output_vs_err2.push_back(static_cast<NumT>(52.));
  true_output_vs.push_back(static_cast<NumT>(20.)); // =4*5
  true_output_vs_err2.push_back(static_cast<NumT>(41.));
  true_output_vs.push_back(static_cast<NumT>(16.)); // =4*4
  true_output_vs_err2.push_back(static_cast<NumT>(32.));
  true_output_vs.push_back(static_cast<NumT>(12.)); // =4*3
  true_output_vs_err2.push_back(static_cast<NumT>(25.));
  true_output_vs.push_back(static_cast<NumT>(8.));  // =4*2
  true_output_vs_err2.push_back(static_cast<NumT>(20.));
}

/**
 * Function that testes the discrepancies between the output
 * generated by the mult_ncerr function for the vs and vv cases.
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_vs (INPUT) is the result array created by mult_ncerr for the
 * vs case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the result
 * array created by mult_ncerr for the vs case
 * \param true_output_vs (INPUT) is the true result array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vs case
 * \param output_vv (INPUT) is the result array created by mult_ncerr for the
 * vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the result
 * array created by mult_ncerr for the vv case
 * \param true_output_vv (INPUT) is the true result array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vv case
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
{
  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    return false;
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS,ERROR))
    return false;

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    return false;
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV,ERROR))
    return false;

  // everything okay
  return true;
}

/**
 * Function that generates the data using the mult_ncerr function
 * (as described in the documentation of the mult_ncerr function)
 * and launches the comparison of the data. Returns the result
 * of the test_okay function (TRUE/FALSE).
 *
 * \param input1 (OUTPUT) is the first array to be multiplied
 * \param input1_err2 (OUTPUT) is the square of the uncertainty in the first
 * array to be multiplied
 * \param input2 (OUTPUT) is the second array to be multiplied
 * \param input2_err2 (OUTPUT) is the square of the uncertainty in the second
 * array to be multiplied
 * \param output_vs (INPUT) is the result array created by mult_ncerr for the
 * vs case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the result
 * \param output_vv (INPUT) is the result array created by mult_ncerr for the
 * vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the result
 * array created by mult_ncerr for the vv case
 * \param true_output_vs (INPUT) is the true result array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vs case
 * \param true_output_vv (INPUT) is the true result array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vv case
*/
template <typename NumT>
bool test_func(NumT key){ // key forces correct test to happen
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

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2);
  initialize_true_outputs(true_output_vs,true_output_vs_err2,
                          true_output_vv,true_output_vv_err2);

  // run the code being tested
  ArrayManip::mult_ncerr(input1, input1_err2, input2, input2_err2,
                         output_vv, output_vv_err2);
  ArrayManip::mult_ncerr(input1, input1_err2,
                         input2[NUM_VAL-1], input2_err2[NUM_VAL-1],
                         output_vs, output_vs_err2);

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that testes mult_ncerr for
 * float, double, int and unsigned int.
 */
int main()
{
  cout << "mult_ncerr_test.cpp..........";

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<double>(1)))
    return -1;

  if(!test_func(static_cast<int>(1)))
    return -1;

  if(!test_func(static_cast<unsigned int>(1)))
    return -1;

  cout << "Functionality OK" << endl;

  return 0;
}

