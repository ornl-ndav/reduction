/*
 *         SNS Common Libraries
 *     A part of the SNS Analysis Software Suite.
 *
 *      Spallation Neutron Source
 *    Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *           NOTICE
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
 * \defgroup tof_to_initial_wavelength_igs_test tof_to_initial_wavelength_igs_test
 *
 * This test compares the output data calculated by the library
 * function tof_to_initial_wavelength_igs_test() and described in 3.29
 * of the DR_Lib_RS_q with the true output data manually
 * calculated. Any discrepancy between the outputs will generate an
 * error message in the testsuite.log file that gives details about
 * the location and type of the error.
 */

/**
 * This function initiales the input arrays.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & tof,
                       Nessi::Vector<NumT> & tof_err2){
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      tof.push_back(static_cast<NumT>(1+i));
      tof_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function generate the values to compare the calculation to.
 */
template <typename NumT>
void initialize_true_outputs(NumT    & true_output_ss,
           NumT    & true_output_ss_err2,
           Nessi::Vector<NumT> & true_output_vv,
           Nessi::Vector<NumT> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<NumT>(-0.58583914499999989456);
  true_output_ss_err2=static_cast<NumT>(0.0821200935022268902);

  // vector vector
  true_output_vv.push_back(static_cast<NumT>(-0.58583914499999989456));
  true_output_vv_err2.push_back(static_cast<NumT>(0.0821200935022268902));
  true_output_vv.push_back(static_cast<NumT>(-0.58224275045454543243));
  true_output_vv_err2.push_back(static_cast<NumT>(0.0817858471131884257));
  true_output_vv.push_back(static_cast<NumT>(-0.57864635590909085927));
  true_output_vv_err2.push_back(static_cast<NumT>(0.0814537385842700606));
  true_output_vv.push_back(static_cast<NumT>(-0.57504996136363628612));
  true_output_vv_err2.push_back(static_cast<NumT>(0.0811237679154717811));
  true_output_vv.push_back(static_cast<NumT>(-0.57145356681818171296));
  true_output_vv_err2.push_back(static_cast<NumT>(0.0807959351067936149));
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
  Nessi::Vector< NumT > tof;
  Nessi::Vector< NumT > tof_err2;
  NumT                  final_wavelength=static_cast<NumT>(1.25);
  NumT                  final_wavelength_err2=static_cast<NumT>(0.25);
  NumT                  time_offset=static_cast<NumT>(2.75);
  NumT                  time_offset_err2=static_cast<NumT>(0.75);
  NumT                  dist_source_sample=static_cast<NumT>(1.1);
  NumT                  dist_source_sample_err2=static_cast<NumT>(0.1);
  NumT            dist_sample_detector=static_cast<NumT>(0.51);
  NumT            dist_sample_detector_err2=static_cast<NumT>(0.05);
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv(5);
  Nessi::Vector<NumT>   output_vv_err2(5);
  Nessi::Vector<NumT>   true_output_vv;
  Nessi::Vector<NumT>   true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(tof,tof_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::tof_to_initial_wavelength_igs(tof[0], tof_err2[0],
                                           final_wavelength,
                                           final_wavelength_err2,
                                           time_offset, time_offset_err2,
                                           dist_source_sample,
                                           dist_source_sample_err2,
                                           dist_sample_detector,
                                           dist_sample_detector_err2,
                                           output_ss,
                                           output_ss_err2);

  AxisManip::tof_to_initial_wavelength_igs(tof, tof_err2,
                                           final_wavelength,
                                           final_wavelength_err2,
                                           time_offset, time_offset_err2,
                                           dist_source_sample,
                                           dist_source_sample_err2,
                                           dist_sample_detector,
                                           dist_sample_detector_err2,
                                           output_vv,
                                           output_vv_err2);

  return test_okay(output_ss, output_ss_err2,
       true_output_ss, true_output_ss_err2,
       output_vv, output_vv_err2,
       true_output_vv, true_output_vv_err2);
}

/**
 * Main functino that test energy_transfer for float and double
 */
int main(){
  cout << "tof_to_initial_wavelength_igs_test.cpp..........";

   if(!test_func(static_cast<float>(1)))
    return -1;

   if(!test_func(static_cast<double>(1)))
   return -1;

  cout << "Functionality OK" << endl;

  return 0;
}
