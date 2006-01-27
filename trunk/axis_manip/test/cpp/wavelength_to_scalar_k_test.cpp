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

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup wavelength_to_scalar_k_test wavelength_to_scalar_k_test
 *
 * This test compares the output data calculated by the library
 * function wavelength_to_scalar_k() and described in 3.24
 * of the DR_Lib_RS_q with the true output data manually
 * calculated. Any discrepancy between the outputs will generate an
 * error message in the testsuite.log file that gives details about
 * the location and type of the error.
 */

/**
 * This function initiales the input arrays.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & wavelength,
                       Nessi::Vector<NumT> & wavelength_err2){
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      wavelength.push_back(static_cast<NumT>(1+i));
      wavelength_err2.push_back(static_cast<NumT>(0.5+i));
    }
}

/**
 * This function generate the values to compare the calculation to.
 */
//template <typename NumT>
void initialize_true_outputs(float    & true_output_ss,
                             float    & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<float>(6.283185482025146484375);
  true_output_ss_err2=static_cast<float>(19.7392101287841796875);

  // vector vector
  true_output_vv.push_back(static_cast<float>(6.283185482025146484375));
  true_output_vv_err2.push_back(static_cast<float>(19.7392101287841796875));
  true_output_vv.push_back(static_cast<float>(3.1415927410125732421875));
  true_output_vv_err2.push_back(static_cast<float>(3.701101779937744140625));
  true_output_vv.push_back(static_cast<float>(2.094395160675048828125));
  true_output_vv_err2.push_back(static_cast<float>(1.21846973896026611328125));
  true_output_vv.push_back(static_cast<float>(1.57079637050628662109375));
  true_output_vv_err2.push_back(static_cast<float>(0.53974401950836181640625));
  true_output_vv.push_back(static_cast<float>(1.256637096405029296875));
  true_output_vv_err2.push_back(static_cast<float>(0.2842446267604827880859375));
}

void initialize_true_outputs(double    & true_output_ss,
                             double    & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<double>(6.283185307179586231995926937088);
  true_output_ss_err2=static_cast<double>(19.739208802178715984609880251810);

  // vector vector
  true_output_vv.push_back(static_cast<double>(6.283185307179586231995926937088));
  true_output_vv_err2.push_back(static_cast<double>(19.739208802178715984609880251810));
  true_output_vv.push_back(static_cast<double>(3.141592653589793115997963468544));
  true_output_vv_err2.push_back(static_cast<double>(3.701101650408509247114352547214));
  true_output_vv.push_back(static_cast<double>(2.094395102393195262635572362342));
  true_output_vv_err2.push_back(static_cast<double>(1.218469679146834350191852536227));
  true_output_vv.push_back(static_cast<double>(1.570796326794896557998981734272));
  true_output_vv_err2.push_back(static_cast<double>(0.539743990684574237448600797507));
  true_output_vv.push_back(static_cast<double>(1.256637061435917246399185387418));
  true_output_vv_err2.push_back(static_cast<double>(0.284244606751373529718307509029));
}

/**
 * This functions compares the expected with calculated values.
 */
template <typename NumT>
bool test_okay(NumT    & output_ss,
               NumT    & output_ss_err2,
               NumT    & true_output_ss,
               NumT    & true_output_ss_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2){
  // scalar scalar
  if(!test_okay(output_ss,true_output_ss))
    return false;
  if(!test_okay(output_ss_err2,true_output_ss_err2))
    return false;

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    return false;
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV))
    return false;

  // everything okay
  return true;
}


/**
 * Function that runs the test for a numeric type
 */
template <typename NumT>
bool test_func(NumT key){ // key forces correct test to happen
  // allocate arrays
  Nessi::Vector< NumT > wavelength;
  Nessi::Vector< NumT > wavelength_err2;
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(5);
  Nessi::Vector<NumT>   output_vv_err2(5);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(wavelength,wavelength_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::wavelength_to_scalar_k(wavelength[0], wavelength_err2[0],
                                  output_ss, output_ss_err2);

  AxisManip::wavelength_to_scalar_k(wavelength, wavelength_err2,
                                  output_vv, output_vv_err2);

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that test scalar_k_transfer for float and double
 */
int main(){
  cout << "wavelength_to_scalar_k_test.cpp..........";

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<double>(1)))
    return -1;

  cout << "Functionality OK" << endl;

  return 0;
}
