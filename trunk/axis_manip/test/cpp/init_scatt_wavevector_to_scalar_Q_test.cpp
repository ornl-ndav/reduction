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

/*
void f_function_init_scatt_wavevector_to_scalar_Q(
                              Nessi::Vector<float> & f_initial_wavevector,
                              Nessi::Vector<float> & f_initial_wavevector_err2,
                              int f_initial_wavevector_i,
                              Nessi::Vector<float> & f_final_wavevector,
                              Nessi::Vector<float> & f_final_wavevector_err2,
                              int f_final_wavector_j,
                              float f_polar_angle,
                              float f_polar_angle_err2,
                              Nessi::Vector<float> & f_true_Q,
                              Nessi::Vector<float> & f_true_Q_err2,
                              int k);

void d_function_init_scatt_wavevector_to_scalar_Q(
                             Nessi::Vector<double> & d_initial_wavevector,
                             Nessi::Vector<double> & d_initial_wavevector_err2,
                             int d_initial_wavevector_i,
                             Nessi::Vector<double> & d_final_wavevector,
                             Nessi::Vector<double> & d_final_wavevector_err2,
                             int d_final_wavector_j,
                             double d_polar_angle,
                             double d_polar_angle_err2,
                             Nessi::Vector<double> & d_true_Q,
                             Nessi::Vector<double> & d_true_Q_err2,
                             int k);

int main()
{
  // SNS-FIXME

  int num_val = 20;

  //float
  Nessi::Vector<float> f_initial_wavevector;
  Nessi::Vector<float> f_initial_wavevector_err2;
  Nessi::Vector<float> f_final_wavevector;
  Nessi::Vector<float> f_final_wavevector_err2;
  Nessi::Vector<float> f_Q(num_val);
  Nessi::Vector<float> f_Q_err2(num_val);
  Nessi::Vector<float> f_true_Q(num_val);
  Nessi::Vector<float> f_true_Q_err2(num_val);
  float f_polar_angle;
  float f_polar_angle_err2;

  //double
  Nessi::Vector<double> d_initial_wavevector;
  Nessi::Vector<double> d_initial_wavevector_err2;
  Nessi::Vector<double> d_final_wavevector;
  Nessi::Vector<double> d_final_wavevector_err2;
  Nessi::Vector<double> d_Q(num_val);
  Nessi::Vector<double> d_Q_err2(num_val);
  Nessi::Vector<double> d_true_Q(num_val);
  Nessi::Vector<double> d_true_Q_err2(num_val);
  double d_polar_angle;
  double d_polar_angle_err2;

  int error_case_1 = 0;
  int error_case_2 = 0;
  int error_case_3 = 0;
  int error_case_4 = 0;
  int error = 0;

  //initialization of parameters

  f_polar_angle = static_cast<float>(34.45);
  d_polar_angle = static_cast<double>(34.45);

  f_polar_angle_err2 = static_cast<float>(34.45);
  d_polar_angle_err2 = static_cast<double>(34.45);

  //case 1

  f_initial_wavevector.push_back(static_cast<float>(2)*3.5);
  f_initial_wavevector_err2.push_back(static_cast<float>(4.4));

  d_initial_wavevector.push_back(static_cast<double>(2)*3.5);
  d_initial_wavevector_err2.push_back(static_cast<double>(4.4));

  for(int i = 0 ; i < num_val ; i++)
    {
      f_final_wavevector.push_back(static_cast<float>(2*i+1));
      f_final_wavevector_err2.push_back(static_cast<float>(2*i));

      d_final_wavevector.push_back(static_cast<double>(2*i+1));
      d_final_wavevector_err2.push_back(static_cast<double>(2*i));
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                               f_initial_wavevector_err2,
                                               f_final_wavevector,
                                               f_final_wavevector_err2,
                                               f_polar_angle,
                                               f_polar_angle_err2,
                                               f_Q,
                                               f_Q_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                               d_initial_wavevector_err2,
                                               d_final_wavevector,
                                               d_final_wavevector_err2,
                                               d_polar_angle,
                                               d_polar_angle_err2,
                                               d_Q,
                                               d_Q_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                                   f_initial_wavevector_err2,
                                                   0,
                                                   f_final_wavevector,
                                                   f_final_wavevector_err2,
                                                   i,
                                                   f_polar_angle,
                                                   f_polar_angle_err2,
                                                   f_true_Q,
                                                   f_true_Q_err2,
                                                   i);

      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                                   d_initial_wavevector_err2,
                                                   0,
                                                   d_final_wavevector,
                                                   d_final_wavevector_err2,
                                                   i,
                                                   d_polar_angle,
                                                   d_polar_angle_err2,
                                                   d_true_Q,
                                                   d_true_Q_err2,
                                                   i);
    }

  //compare results for case 1

  while (1)
  {
    Utils::vector_comparison(f_Q, f_true_Q, error_case_1, 10);
    if (error_case_1 != 0) break;
    Utils::vector_comparison(f_Q_err2, f_true_Q_err2, error_case_1, 20);
    if (error_case_1 != 0) break;
    Utils::vector_comparison(d_Q, d_true_Q, error_case_1, 110);
    if (error_case_1 != 0) break;
    Utils::vector_comparison(d_Q_err2, d_true_Q_err2, error_case_1, 120);
    break;
   }

  // ****case 2****

  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  f_final_wavevector.push_back(static_cast<float>(14.34));
  d_final_wavevector.push_back(static_cast<double>(14.34));

  f_final_wavevector_err2.push_back(static_cast<float>(4.34));
  d_final_wavevector_err2.push_back(static_cast<double>(4.34));

  for(int i = 0 ; i < num_val ; i++)
    {
      f_initial_wavevector.push_back(static_cast<float>(i+1));
      f_initial_wavevector_err2.push_back(static_cast<float>(i));

      d_initial_wavevector.push_back(static_cast<double>(i+1));
      d_initial_wavevector_err2.push_back(static_cast<double>(i));
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                               f_initial_wavevector_err2,
                                               f_final_wavevector,
                                               f_final_wavevector_err2,
                                               f_polar_angle,
                                               f_polar_angle_err2,
                                               f_Q,
                                               f_Q_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                               d_initial_wavevector_err2,
                                               d_final_wavevector,
                                               d_final_wavevector_err2,
                                               d_polar_angle,
                                               d_polar_angle_err2,
                                               d_Q,
                                               d_Q_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                                   f_initial_wavevector_err2,
                                                   i,
                                                   f_final_wavevector,
                                                   f_final_wavevector_err2,
                                                   0,
                                                   f_polar_angle,
                                                   f_polar_angle_err2,
                                                   f_true_Q,
                                                   f_true_Q_err2,
                                                   i);

      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                                   d_initial_wavevector_err2,
                                                   i,
                                                   d_final_wavevector,
                                                   d_final_wavevector_err2,
                                                   0,
                                                   d_polar_angle,
                                                   d_polar_angle_err2,
                                                   d_true_Q,
                                                   d_true_Q_err2,
                                                   i);
    }

  //compare results for case 2

  while (1)
    {
      Utils::vector_comparison(f_Q, f_true_Q, error_case_2, 10);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(f_Q_err2, f_true_Q_err2, error_case_2, 20);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(d_Q, d_true_Q, error_case_2, 110);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(d_Q_err2, d_true_Q_err2, error_case_2, 120);
      if (error_case_2 != 0) break;
      break;
    }

  // ****case 3****

  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  f_final_wavevector.push_back(static_cast<float>(14.34));
  d_final_wavevector.push_back(static_cast<double>(14.34));

  f_final_wavevector_err2.push_back(static_cast<float>(4.34));
  d_final_wavevector_err2.push_back(static_cast<double>(4.34));

  f_initial_wavevector.push_back(static_cast<float>(11.44));
  f_initial_wavevector_err2.push_back(static_cast<float>(2.2));

  d_initial_wavevector.push_back(static_cast<double>(11.44));
  d_initial_wavevector_err2.push_back(static_cast<double>(2.2));

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                               f_initial_wavevector_err2,
                                               f_final_wavevector,
                                               f_final_wavevector_err2,
                                               f_polar_angle,
                                               f_polar_angle_err2,
                                               f_Q,
                                               f_Q_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                               d_initial_wavevector_err2,
                                               d_final_wavevector,
                                               d_final_wavevector_err2,
                                               d_polar_angle,
                                               d_polar_angle_err2,
                                               d_Q,
                                               d_Q_err2);

  f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                               f_initial_wavevector_err2,
                                               0,
                                               f_final_wavevector,
                                               f_final_wavevector_err2,
                                               0,
                                               f_polar_angle,
                                               f_polar_angle_err2,
                                               f_true_Q,
                                               f_true_Q_err2,
                                               0);

  d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                               d_initial_wavevector_err2,
                                               0,
                                               d_final_wavevector,
                                               d_final_wavevector_err2,
                                               0,
                                               d_polar_angle,
                                               d_polar_angle_err2,
                                               d_true_Q,
                                               d_true_Q_err2,
                                               0);

  //compare results for case 3

  while (1)
    {
      Utils::vector_comparison(f_Q, f_true_Q, error_case_3, 10);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(f_Q_err2, f_true_Q_err2, error_case_3, 20);
      if (error_case_2 != 0) break;
      Utils::vector_comparison(d_Q, d_true_Q, error_case_3, 110);
      if (error_case_3 != 0) break;
      Utils::vector_comparison(d_Q_err2, d_true_Q_err2, error_case_3, 120);
      if (error_case_3 != 0) break;
      break;
    }

  // ****case 4****

  //initialization

  f_final_wavevector.clear();
  f_final_wavevector_err2.clear();
  d_final_wavevector.clear();
  d_final_wavevector_err2.clear();

  f_initial_wavevector.clear();
  f_initial_wavevector_err2.clear();
  d_initial_wavevector.clear();
  d_initial_wavevector_err2.clear();

  for(int i = 0 ; i < num_val ; i++)
    {
      f_initial_wavevector.push_back(static_cast<float>(i+1));
      f_initial_wavevector_err2.push_back(static_cast<float>(i));
      f_final_wavevector.push_back(static_cast<float>(2*i+3));
      f_final_wavevector_err2.push_back(static_cast<float>(i+2));

      d_initial_wavevector.push_back(static_cast<double>(i+1));
      d_initial_wavevector_err2.push_back(static_cast<double>(i));
      d_final_wavevector.push_back(static_cast<double>(2*i+3));
      d_final_wavevector_err2.push_back(static_cast<double>(i+2));
    }

  AxisManip::init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                               f_initial_wavevector_err2,
                                               f_final_wavevector,
                                               f_final_wavevector_err2,
                                               f_polar_angle,
                                               f_polar_angle_err2,
                                               f_Q,
                                               f_Q_err2);

  AxisManip::init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                               d_initial_wavevector_err2,
                                               d_final_wavevector,
                                               d_final_wavevector_err2,
                                               d_polar_angle,
                                               d_polar_angle_err2,
                                               d_Q,
                                               d_Q_err2);

  for(int i = 0 ; i < num_val ; i++)
    {
      f_function_init_scatt_wavevector_to_scalar_Q(f_initial_wavevector,
                                                   f_initial_wavevector_err2,
                                                   i,
                                                   f_final_wavevector,
                                                   f_final_wavevector_err2,
                                                   i,
                                                   f_polar_angle,
                                                   f_polar_angle_err2,
                                                   f_true_Q,
                                                   f_true_Q_err2,
                                                   i);


      d_function_init_scatt_wavevector_to_scalar_Q(d_initial_wavevector,
                                                   d_initial_wavevector_err2,
                                                   i,
                                                   d_final_wavevector,
                                                   d_final_wavevector_err2,
                                                   i,
                                                   d_polar_angle,
                                                   d_polar_angle_err2,
                                                   d_true_Q,
                                                   d_true_Q_err2,
                                                   i);
    }

  //compare results for case 4

  while (1)
    {
      Utils::vector_comparison(f_Q, f_true_Q, error_case_4, 10);
      if (error_case_4 != 0) break;
      Utils::vector_comparison(f_Q_err2, f_true_Q_err2, error_case_4, 20);
      if (error_case_4 != 0) break;
      Utils::vector_comparison(d_Q, d_true_Q, error_case_4, 110);
      if (error_case_4 != 0) break;
      Utils::vector_comparison(d_Q_err2, d_true_Q_err2, error_case_4, 120);
      if (error_case_4 != 0) break;
      break;
    }

  error = error_case_1 + error_case_2 + error_case_3 + error_case_4;

  cout << "init_scatt_wavevector_to_scalar_Q_test.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK" << endl;
      break;
    default:
      {
        if (error_case_1 != 0)
          {
            cout << "(sz1 == 1 && sz2 != 1):" << endl;
            switch (error_case_1)
              {
              case 10:
                cout << "(float) FAILED....Output vector different from vector"
                     << " expected" << endl;
                break;
              case 20:
                cout << "(float) FAILED....Output error vector different from "
                     << "vector expected" << endl;
                break;
              case 110:
                cout << "(double) FAILED....Output vector different from "
                     << "vector expected" << endl;
                break;
              case 120:
                cout << "(double) FAILED....Output error vector different from"
                     << " vector expected" << endl;
                break;
              }
          }
        else if (error_case_2 != 0)
          {
            cout << "(sz1 != 1 && sz2 == 1):" << endl;

            switch (error_case_2)
              {
              case 10:
                cout << "(float) FAILED....Output vector different from vector"
                     << " expected" << endl;
                break;
              case 20:
                cout << "(float) FAILED....Output error vector different from "
                     << "vector expected" << endl;
                break;
              case 110:
                cout << "(double) FAILED....Output vector different from "
                     << "vector expected" << endl;
                break;
              case 120:
                cout << "(double) FAILED....Output error vector different from"
                     << " vector expected" << endl;
                break;
              }
          }
        else if (error_case_3 != 0)
          {
            cout << "(sz1 == 1 && sz2 == 1):" << endl;

            switch (error_case_3)
              {
              case 10:
                cout << "(float) FAILED....Output vector different from vector"
                     << " expected" << endl;
                break;
              case 20:
                cout << "(float) FAILED....Output error vector different from "
                     << "vector expected" << endl;
                break;
              case 110:
                cout << "(double) FAILED....Output vector different from "
                     << "vector expected" << endl;
                break;
              case 120:
                cout << "(double) FAILED....Output error vector different from"
                     << " vector expected" << endl;
                break;
              }
          }
        else if (error_case_4 != 0)
          {
            cout << "(sz1 != 1 && sz2 != 1):" << endl;
            switch (error_case_4)
              {
              case 10:
                cout << "(float) FAILED....Output vector different from vector"
                     << " expected" << endl;
                break;
              case 20:
                cout << "(float) FAILED....Output error vector different from "
                     << "vector expected" << endl;
                break;
              case 110:
                cout << "(double) FAILED....Output vector different from "
                     << "vector expected" << endl;
                break;
              case 120:
                cout << "(double) FAILED....Output error vector different from"
                     << " vector expected" << endl;
                break;
              }
          }
      }
    }
  return 0;
}


void f_function_init_scatt_wavevector_to_scalar_Q(
                              Nessi::Vector<float> & f_initial_wavevector,
                              Nessi::Vector<float> & f_initial_wavevector_err2,
                              int i,
                              Nessi::Vector<float> & f_final_wavevector,
                              Nessi::Vector<float> & f_final_wavevector_err2,
                              int j,
                              float f_polar_angle,
                              float f_polar_angle_err2,
                              Nessi::Vector<float> & f_true_Q,
                              Nessi::Vector<float> & f_true_Q_err2,
                              int k)
{
  float f_a;
  float f_pang, f_sang;
  float f_ki2, f_kf2, f_akikf;
  float f_termi, f_termi2;
  float f_termf, f_termf2;
  float f_front;
  float f_polar, f_polar2;

  f_ki2 = f_initial_wavevector[i] * f_initial_wavevector[i];

  f_a = static_cast<float>(2 * std::cos(static_cast<double>(f_polar_angle)));
  f_pang = static_cast<float>(std::cos(static_cast<double>(f_polar_angle)));
  f_sang = static_cast<float>(std::sin(static_cast<double>(f_polar_angle)));

  f_kf2 = f_final_wavevector[j] * f_final_wavevector[j];
  f_akikf = f_a * f_initial_wavevector[i] * f_final_wavevector[j];

  f_true_Q[k] = static_cast<float>(std::sqrt(static_cast<double>(f_ki2 + f_kf2
                                                                 - f_akikf)));

  f_termi = f_initial_wavevector[i] - (f_final_wavevector[j] * f_pang);
  f_termi2 = f_termi * f_termi;

  f_termf = f_initial_wavevector[i] * f_pang;
  f_termf = f_final_wavevector[j] - f_termf;
  f_termf2 = f_termf * f_termf;

  f_polar = f_final_wavevector[j] * f_initial_wavevector[i];
  f_polar = f_polar * f_sang;
  f_polar2 = f_polar * f_polar;

  f_front = 1 / (f_true_Q[k] * f_true_Q[k]);

  f_true_Q_err2[k] = f_final_wavevector_err2[j] * f_termf2;
  f_true_Q_err2[k] = f_true_Q_err2[k]
    + f_initial_wavevector_err2[i] * f_termi2;
  f_true_Q_err2[k] = f_true_Q_err2[k] + (f_polar_angle_err2 * f_polar2);
  f_true_Q_err2[k] = f_true_Q_err2[k] * f_front ;

  return;
}


void d_function_init_scatt_wavevector_to_scalar_Q(
                             Nessi::Vector<double> & d_initial_wavevector,
                             Nessi::Vector<double> & d_initial_wavevector_err2,
                             int i,
                             Nessi::Vector<double> & d_final_wavevector,
                             Nessi::Vector<double> & d_final_wavevector_err2,
                             int j,
                             double d_polar_angle,
                             double d_polar_angle_err2,
                             Nessi::Vector<double> & d_true_Q,
                             Nessi::Vector<double> & d_true_Q_err2,
                             int k)
{
  double d_a;
  double d_pang, d_sang;
  double d_ki2, d_kf2, d_akikf;
  double d_termi, d_termi2;
  double d_termf, d_termf2;
  double d_front;
  double d_polar, d_polar2;

  d_a = static_cast<double>(2 * std::cos(static_cast<double>(d_polar_angle)));
  d_pang = static_cast<double>(std::cos(static_cast<double>(d_polar_angle)));
  d_sang = static_cast<double>(std::sin(static_cast<double>(d_polar_angle)));

  d_ki2 = d_initial_wavevector[i] * d_initial_wavevector[i];

  d_kf2 = d_final_wavevector[j] * d_final_wavevector[j];
  d_akikf = d_a * d_initial_wavevector[i];
  d_akikf = d_akikf * d_final_wavevector[j];

  d_true_Q[k] = static_cast<double>(std::sqrt(static_cast<double>(d_ki2 + d_kf2
                                                                  - d_akikf)));

  d_termi = d_final_wavevector[j] * d_pang;
  d_termi = d_initial_wavevector[i] - d_termi;
  d_termi2 = d_termi * d_termi;

  d_termf = d_initial_wavevector[i] * d_pang;
  d_termf = d_final_wavevector[j] - d_termf;
  d_termf2 = d_termf * d_termf;

  d_polar = d_final_wavevector[j] * d_initial_wavevector[i] ;
  d_polar = d_polar *  d_sang;
  d_polar2 = d_polar * d_polar;

  d_front = 1 / (d_true_Q[k] * d_true_Q[k]);

  d_true_Q_err2[k] = d_initial_wavevector_err2[i] * d_termi2;
  d_true_Q_err2[k] = d_true_Q_err2[k] + d_final_wavevector_err2[j] * d_termf2;
  d_true_Q_err2[k] = d_true_Q_err2[k] + d_polar_angle_err2 * d_polar2;
  d_true_Q_err2[k] = d_true_Q_err2[k] * d_front ;

  return;
}
*/
