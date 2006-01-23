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

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp"
#include "test_common.hpp"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup init_scatt_wavevector_to_scalar_Q init_scatt_wavevector_to_scalar_Q
 *
 * This test compares the output data calculated by the library
 * function init_scatt_wavevector_to_scalar_Q() and described in 3.33
 * of the DR_Lib_RS_q with the true output data manually
 * calculated. Any discrepancy between the outputs will generate an
 * error message in the testsuite.log file that gives details about
 * the location and type of the error.
 */

/**
 * This function initiales the input arrays.
 */
template <typename NumT>
void initialize_inputs(NumT & polar,
                       NumT & polar_err2,
                       Nessi::Vector<NumT> & k_i,
                       Nessi::Vector<NumT> & k_i_err2,
                       Nessi::Vector<NumT> & k_f,
                       Nessi::Vector<NumT> & k_f_err2){
  polar=static_cast<NumT>(0.);
  polar_err2=static_cast<NumT>(0.);

  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      k_i.push_back(static_cast<NumT>(0.));
      k_i_err2.push_back(static_cast<NumT>(0.));
      k_f.push_back(static_cast<NumT>(0.));
      k_f_err2.push_back(static_cast<NumT>(0.));
    }
}

/**
 * This function generate the values to compare the calculation to.
 */
template <typename NumT>
void initialize_true_outputs(NumT                & true_output_ss,
                             NumT                & true_output_ss_err2,
                             Nessi::Vector<NumT> & true_output_sv,
                             Nessi::Vector<NumT> & true_output_sv_err2,
                             Nessi::Vector<NumT> & true_output_vs,
                             Nessi::Vector<NumT> & true_output_vs_err2,
                             Nessi::Vector<NumT> & true_output_vv,
                             Nessi::Vector<NumT> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<NumT>(0.);
  true_output_ss_err2=static_cast<NumT>(0.);
  
  // scalar vector
  true_output_sv.push_back(static_cast<NumT>(0.));
  true_output_sv_err2.push_back(static_cast<NumT>(0.));
  true_output_sv.push_back(static_cast<NumT>(0.));
  true_output_sv_err2.push_back(static_cast<NumT>(0.));
  true_output_sv.push_back(static_cast<NumT>(0.));
  true_output_sv_err2.push_back(static_cast<NumT>(0.));
  true_output_sv.push_back(static_cast<NumT>(0.));
  true_output_sv_err2.push_back(static_cast<NumT>(0.));
  true_output_sv.push_back(static_cast<NumT>(0.));
  true_output_sv_err2.push_back(static_cast<NumT>(0.));

  // vector scalar
  true_output_vs.push_back(static_cast<NumT>(0.));
  true_output_vs_err2.push_back(static_cast<NumT>(0.));
  true_output_vs.push_back(static_cast<NumT>(0.));
  true_output_vs_err2.push_back(static_cast<NumT>(0.));
  true_output_vs.push_back(static_cast<NumT>(0.));
  true_output_vs_err2.push_back(static_cast<NumT>(0.));
  true_output_vs.push_back(static_cast<NumT>(0.));
  true_output_vs_err2.push_back(static_cast<NumT>(0.));
  true_output_vs.push_back(static_cast<NumT>(0.));
  true_output_vs_err2.push_back(static_cast<NumT>(0.));

  // vector vector
  true_output_vv.push_back(static_cast<NumT>(0.));
  true_output_vv_err2.push_back(static_cast<NumT>(0.));
  true_output_vv.push_back(static_cast<NumT>(0.));
  true_output_vv_err2.push_back(static_cast<NumT>(0.));
  true_output_vv.push_back(static_cast<NumT>(0.));
  true_output_vv_err2.push_back(static_cast<NumT>(0.));
  true_output_vv.push_back(static_cast<NumT>(0.));
  true_output_vv_err2.push_back(static_cast<NumT>(0.));
  true_output_vv.push_back(static_cast<NumT>(0.));
  true_output_vv_err2.push_back(static_cast<NumT>(0.));
}

/**
 * This functions compares the expected with calculated values.
 */
template <typename NumT>
bool test_okay(NumT                & output_ss,
               NumT                & output_ss_err2,
               NumT                & true_output_ss,
               NumT                & true_output_ss_err2,
               Nessi::Vector<NumT> & output_sv,
               Nessi::Vector<NumT> & output_sv_err2,
               Nessi::Vector<NumT> & true_output_sv,
               Nessi::Vector<NumT> & true_output_sv_err2,
               Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2,
               Nessi::Vector<NumT> & output_vv,
               Nessi::Vector<NumT> & output_vv_err2,
               Nessi::Vector<NumT> & true_output_vv,
               Nessi::Vector<NumT> & true_output_vv_err2){
  // scalar scalar
  if(!test_okay(output_ss,true_output_ss))
    return false;
  if(!test_okay(output_ss_err2,true_output_ss_err2))
    return false;

  // scalar vector
  if(!test_okay(output_sv,true_output_sv,SV))
    return false;
  if(!test_okay(output_sv_err2,true_output_sv_err2,SV))
    return false;

  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    return false;
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS))
    return false;

  // scalar vector
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
  NumT                polar;
  NumT                polar_err2;
  Nessi::Vector<NumT> k_i;
  Nessi::Vector<NumT> k_i_err2;
  Nessi::Vector<NumT> k_f;
  Nessi::Vector<NumT> k_f_err2;
  NumT                output_ss;
  NumT                output_ss_err2;
  NumT                true_output_ss;
  NumT                true_output_ss_err2;
  Nessi::Vector<NumT> output_sv;
  Nessi::Vector<NumT> output_sv_err2;
  Nessi::Vector<NumT> true_output_sv;
  Nessi::Vector<NumT> true_output_sv_err2;
  Nessi::Vector<NumT> output_vs;
  Nessi::Vector<NumT> output_vs_err2;
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> output_vv;
  Nessi::Vector<NumT> output_vv_err2;
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(polar,polar_err2,k_i,k_i_err2,k_f,k_f_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_sv, true_output_sv_err2,
                          true_output_vs, true_output_vs_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::init_scatt_wavevector_to_scalar_Q(k_i[0], k_i_err2[0],
                                               k_f[0], k_f_err2[0],
                                               polar,polar_err2,
                                               output_ss, output_ss_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(k_i[0], k_i_err2[0],
                                               k_f, k_f_err2,
                                               polar,polar_err2,
                                               output_sv, output_sv_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(k_i, k_i_err2,
                                               k_f[0], k_f_err2[0],
                                               polar,polar_err2,
                                               output_vs, output_vs_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(k_i, k_i_err2,
                                               k_f, k_f_err2,
                                               polar,polar_err2,
                                               output_vv, output_vv_err2);

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_sv, output_sv_err2,
                   true_output_sv, true_output_sv_err2,
                   output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main functino that test energy_transfer for float and double
 */
int main(){
  cout << "init_scatt_wavevector_to_scalar_Q_test.cpp..........";

  if(!test_func(static_cast<float>(1)))
    return -1;

  if(!test_func(static_cast<double>(1)))
    return -1;

  cout << "Functionality OK" << endl;

  return 0;
}
