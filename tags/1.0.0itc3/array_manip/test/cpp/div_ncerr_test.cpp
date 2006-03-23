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
 * \file array_manip/test/cpp/div_ncerr_test.cpp
 */

#include "arith.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL=5;

/**
 * \defgroup div_ncerr_test div_ncerr_test
 * \{
 *
 * This test compares the output data (\f$output\_sv\f$, \f$output\_vs\f$ and
 * \f$output\_vv\f$)calculated by the library function <i>div_ncerr</i> and
 * described in section 3.4, 3.5 and 3.9 of the <i>SNS 107030214-TD0001-R00,
 * "Data Reduction Library Software Requirements and Specifications"</i>
 * with the true output data (\f$true\_output\_sv\f$, \f$true\_output\_vs\f$
 * and \f$true\_output\_vv\f$) manually calculated .
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives
 * details about the location and type of the error.
 *
 * <b>Notation used:</b>
 * - vv : vector-vector
 * - vs : vector-scalar
 * - VV = "v,v"
 * - SV = "s,v"
 * - VS = "v,s"
 * - ERROR = "error "
 * - EMPTY = ""
 */

/**
 * \ingroup initialize_inputs
 *
 * This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
 * \f$input1\_err2\f$, and \f$input2\_err2\f$.
 *
 * \param input1 (OUTPUT) is the array to be divided from
 * \param input1_err2 (OUTPUT) is the square of the uncertainty in the array
 * to be divided from
 * \param input2 (OUTPUT) is the array to divide by
 * \param input2_err2 (OUTPUT) is the square of the uncertainty in the array
 * to divide by
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & input1,
                       Nessi::Vector<NumT> & input1_err2,
                       Nessi::Vector<NumT> & input2,
                       Nessi::Vector<NumT> & input2_err2)
{
  for( int i=0 ; i<NUM_VAL ; i++ )
    {
      input1.push_back(static_cast<NumT>(10-i)); // 10,9,8,7,6
      input2.push_back(static_cast<NumT>(2+i));  //  2,3,4,5,6
      input1_err2.push_back(static_cast<NumT>(1.));
      input2_err2.push_back(static_cast<NumT>(1.));
    }
}

/**
 * Function that sets the true outputs based on values containes in
 * \f$input1\f$, \f$input2\f$, \f$input1\_err2\f$, and \f$input2\_err2\f$.
 *
 * For the vs and sv cases, the scalar used is the last element
 * of the array \f$input2\f$, \f$input2[NUM\_VAL-1]\f$.
 *
 * where \f$NUM\_VAL\f$ is the number of element of the arrays.
 *
 * \param true_output_vs (OUTPUT) is the true array for the
 * vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vs case
 * \param true_output_sv (OUTPUT) is the true array for the
 * sv case
 * \param true_output_sv_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the sv case
 * \param true_output_vv (OUTPUT) is the true array for the
 * vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty
 * in the true array for the vv case
 */
template <typename NumT>
void initialize_true_outputs(Nessi::Vector<NumT> & true_output_vs,
                             Nessi::Vector<NumT> & true_output_vs_err2,
                             Nessi::Vector<NumT> & true_output_sv,
                             Nessi::Vector<NumT> & true_output_sv_err2,
                             Nessi::Vector<NumT> & true_output_vv,
                             Nessi::Vector<NumT> & true_output_vv_err2)
{
  // initialize the correct true_outputs for vector vector case
  true_output_vv.push_back(static_cast<NumT>(5.)); // =10/2
  true_output_vv_err2.push_back(static_cast<NumT>(6.5));
  true_output_vv.push_back(static_cast<NumT>(3.)); // =9/3
  true_output_vv_err2.push_back(static_cast<NumT>(1.11111111111111111111111111111));
  true_output_vv.push_back(static_cast<NumT>(2.)); // =8/4
  true_output_vv_err2.push_back(static_cast<NumT>(0.3125));
  true_output_vv.push_back(static_cast<NumT>(1.4)); // =7/5
  true_output_vv_err2.push_back(static_cast<NumT>(0.1184));
  true_output_vv.push_back(static_cast<NumT>(1.)); // =6/6
  true_output_vv_err2.push_back(static_cast<NumT>(0.05555555555555555555555555556));

  // initialize the correct true_outputs for vector scalar case
  true_output_vs.push_back(static_cast<NumT>(5.)); // =10/2
  true_output_vs_err2.push_back(static_cast<NumT>(6.5));
  true_output_vs.push_back(static_cast<NumT>(4.5)); // =9/2
  true_output_vs_err2.push_back(static_cast<NumT>(5.3125));
  true_output_vs.push_back(static_cast<NumT>(4.)); // =8/2
  true_output_vs_err2.push_back(static_cast<NumT>(4.25));
  true_output_vs.push_back(static_cast<NumT>(3.5)); // =7/2
  true_output_vs_err2.push_back(static_cast<NumT>(3.3125));
  true_output_vs.push_back(static_cast<NumT>(3.)); // =6/2
  true_output_vs_err2.push_back(static_cast<NumT>(2.5));

  // initialize the correct true_outputs for scalar vector case
  true_output_sv.push_back(static_cast<NumT>(5.)); // =10/2
  true_output_sv_err2.push_back(static_cast<NumT>(6.5));
  true_output_sv.push_back(static_cast<NumT>(3.33333333333333333333333333)); //=10/3
  true_output_sv_err2.push_back(static_cast<NumT>(1.34567901234567899));
  true_output_sv.push_back(static_cast<NumT>(2.5)); // =10/4
  true_output_sv_err2.push_back(static_cast<NumT>(0.453125));
  true_output_sv.push_back(static_cast<NumT>(2.)); // =10/5
  true_output_sv_err2.push_back(static_cast<NumT>(0.2));
  true_output_sv.push_back(static_cast<NumT>(1.66666666666666666666666667)); //=10/6
  true_output_sv_err2.push_back(static_cast<NumT>(0.104938271604938266));
}

/**
 * Function that tests the discrepancies between the output
 * generated by the <i>div_ncerr</i> function for the vs, sv and vv cases.
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_vs (INPUT) is the array created by <i>div_ncerr</i>
 * for the vs case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the
 * array created by <i>div_ncerr</i> for the vs case
 * \param true_output_vs (INPUT) is the true array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vs case
 * \param output_sv (INPUT) is the array created by <i>div_ncerr</i>
 * for the sv case
 * \param output_sv_err2 (INPUT) is the square of the uncertainty in the
 * array created by <i>div_ncerr</i> for the sv case
 * \param true_output_sv (INPUT) is the true array for the sv case
 * \param true_output_sv_err2 (INPUT) is the square of the uncertainty in the
 * true array for the sv case
 * \param output_vv (INPUT) is the array created by <i>div_ncerr</i>
 * for the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the
 * array created by <i>div_ncerr</i> for the vv case
 * \param true_output_vv (INPUT) is the true array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vv case
 */
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_sv,
               Nessi::Vector<NumT> & output_sv_err2,
               Nessi::Vector<NumT> & true_output_sv,
               Nessi::Vector<NumT> & true_output_sv_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2)
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
  // scalar vector
  if(!test_okay(output_sv,true_output_sv,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_err2,true_output_sv_err2,SV,ERROR))
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

  // everything okay
  return value;
}

/**
 * Function that generates the data using the <i>div_ncerr</i> function
 * (as described in the documentation of the <i>div_ncerr</i> function)
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
  Nessi::Vector<NumT> output_sv(NUM_VAL);
  Nessi::Vector<NumT> output_sv_err2(NUM_VAL);
  Nessi::Vector<NumT> output_vv(NUM_VAL);
  Nessi::Vector<NumT> output_vv_err2(NUM_VAL);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> true_output_sv;
  Nessi::Vector<NumT> true_output_sv_err2;
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(input1,input1_err2,input2,input2_err2);
  initialize_true_outputs(true_output_vs,true_output_vs_err2,
                          true_output_sv,true_output_sv_err2,
                          true_output_vv,true_output_vv_err2);

  // run the code being tested
  ArrayManip::div_ncerr(input1, input1_err2, input2, input2_err2,
                        output_vv, output_vv_err2);
  ArrayManip::div_ncerr(input1[0], input1_err2[0], input2, input2_err2,
                        output_sv, output_sv_err2);
  ArrayManip::div_ncerr(input1, input1_err2,
                        input2[0], input2_err2[0],
                        output_vs, output_vs_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv,true_output_vv,VV,debug);
      print(output_vv_err2,true_output_vv_err2,ERROR+VV,debug);
      print(output_vs,true_output_vs,VS,debug);
      print(output_vs_err2,true_output_vs_err2,ERROR+VS,debug);
      print(output_sv,true_output_sv,SV,debug);
      print(output_sv_err2,true_output_sv_err2,ERROR+SV,debug);
    }

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_sv, output_sv_err2,
                   true_output_sv, true_output_sv_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that tests <i>sub_ncerr</i> for
 * float, double, int and unsigned int.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "div_ncerr_test.cpp..........";

  string debug;
  if (argc>1)
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

  if(!test_func(static_cast<int>(1), debug))
    {
      return -1;
    }

  if(!test_func(static_cast<unsigned int>(1), debug))
    {
      return -1;
    }

  cout << "Functionality OK" << endl;

  return 0;
}

/**
 * \}
 */     //end of div_ncerr_test group
