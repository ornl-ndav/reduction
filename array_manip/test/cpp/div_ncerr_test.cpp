// $Id$

#include "arith.hpp"
#include "test_common.hpp"

using namespace std;

const int NUM_VAL=5;

/**
 * \ingroup div_ncerr_test
 *
 * This test compares the output data (\f$output_sv\f$, \f$output_vs\f$ and
 * \f$output_vv\f$)calculated by the library function div_ncerr and described
 * in section 3.4, 3.5 and 3.9 of the DR_Lib_RS_1 with the true output data
 * (\f$true_output_sv\f$, \f$true_output_vs\f$ and \f$true_output_vv\f$)
 * manually calculated .
 * Any discrepancy between the outputs (\f$output\f$ and \f$true_output\f$)
 * will generate in the testsuite.log file an error message that gives
 * details about the location and type of the error.
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
 * Function that generates the true outputs using \f$input1\f$ and
 * \f$input2\f$.
 * For the vs and sv cases, the scalar used is the last element
 * of the array \f$input2\f$, \f$input2[NUM\_VAL]\f$.
 *
 * \param true_output_vs (OUTPUT) is the true result array for the
 * vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty
 * in the true result array for the vs case
 * \param true_output_sv (OUTPUT) is the true result array for the
 * sv case
 * \param true_output_sv_err2 (OUTPUT) is the square of the uncertainty
 * in the true result array for the sv case
 * \param true_output_vv (OUTPUT) is the true result array for the
 * vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty
 * in the true result array for the vv case
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
 * Function that testes the discrepancies between the output
 * generated by the div_ncerr function for the vs, sv and vv cases.
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_vs (INPUT) is the result array created by div_ncerr for the vs
 * case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the result
 * array created by div_ncerr for the vs case
 * \param true_output_vs (INPUT) is the true result array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vs case
 * \param output_sv (INPUT) is the result array created by div_ncerr for the sv
 * case
 * \param output_sv_err2 (INPUT) is the square of the uncertainty in the result
 * array created by div_ncerr for the sv case
 * \param true_output_sv (INPUT) is the true result array for the sv case
 * \param true_output_sv_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the sv case
 * \param output_vv (INPUT) is the result array created by div_ncerr for the vv
 * case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the result
 * array created by div_ncerr for the vv case
 * \param true_output_vv (INPUT) is the true result array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vv case
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
  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    return false;
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS,ERROR))
    return false;

  // scalar vector
  if(!test_okay(output_sv,true_output_sv,SV))
    return false;
  if(!test_okay(output_sv_err2,true_output_sv_err2,SV,ERROR))
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
 * Function that generates the data using the div_ncerr function
 * (as described in the documentation of the div_ncerr function)
 * and launches the comparison of the data. Returns the result
 * of the test_okay function (TRUE/FALSE).
 *
 * \param input1 (OUTPUT) is the array to be dividedfrom
 * \param input1_err2 (OUTPUT) is the square of the uncertainty in the array
 * to be divided from
 * \param input2 (OUTPUT) is the array to divide by
 * \param input2_err2 (OUTPUT) is the square of the uncertainty in the array
 * to divide by
 * \param output_vs (INPUT) is the result array created by div_ncerr for the vs
 * case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the result
 * array created by div_ncerr for the vs case
 * \param output_sv (INPUT) is the result array created div_ncerr for the sv
 * case
 * \param output_sv_err2 (INPUT) is the square of the uncertainty in the result
 * array created by div_ncerr for the sv case
 * \param output_vv (INPUT) is the result array created by div_ncerr for the vv
 * case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the result
 * array created div_ncerr for the vv case
 * \param true_output_vs (INPUT) is the true result array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the vs case
 * \param true_output_sv (INPUT) is the true result array for the sv case
 * \param true_output_sv_err2 (INPUT) is the square of the uncertainty in the
 * true result array for the sv case
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

  return test_okay(output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_sv, output_sv_err2,
                   true_output_sv, true_output_sv_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that testes div_ncerr for
 * float, double, int and unsigned int.
 */
int main()
{
  cout << "div_ncerr_test.cpp..........";

  if(!test_func(static_cast<double>(1)))
    return -1;

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<int>(1)))
    return -1;

  if(!test_func(static_cast<unsigned int>(1)))
    return -1;

  cout << "Functionality OK" << endl;

  return 0;
}
