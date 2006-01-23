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

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi.hpp"
#include "num_comparison.hpp"
#include "test_common.hpp"
#include <cmath>
#include <iostream>

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
      tof.push_back(static_cast<NumT>(0.));
      tof_err2.push_back(static_cast<NumT>(0.));
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
  true_output_ss=static_cast<NumT>(0.);
  true_output_ss_err2=static_cast<NumT>(0.);
  
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
  NumT                  final_wavelength=static_cast<NumT>(0.);
  NumT                  final_wavelength_err2=static_cast<NumT>(0.);
  NumT                  time_offset=static_cast<NumT>(0.);
  NumT                  time_offset_err2=static_cast<NumT>(0.);
  NumT                  dist_source_sample=static_cast<NumT>(0.);
  NumT                  dist_source_sample_err2=static_cast<NumT>(0.);
  NumT  	        dist_sample_detector=static_cast<NumT>(0.);
  NumT  	        dist_sample_detector_err2=static_cast<NumT>(0.);
  NumT                  output_ss;
  NumT                  output_ss_err2;
  NumT                  true_output_ss;
  NumT                  true_output_ss_err2;
  Nessi::Vector<NumT>   output_vv;
  Nessi::Vector<NumT>   output_vv_err2;
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


/*
int main()
{
  // SNS-FIXME

  int num_val = 20;

  //float
  Nessi::Vector<float> f_tof;
  Nessi::Vector<float> f_tof_err2;
  Nessi::Vector<float> f_initial_wavelength(num_val);
  Nessi::Vector<float> f_initial_wavelength_err2(num_val);
  Nessi::Vector<float> f_true_initial_wavelength(num_val);
  Nessi::Vector<float> f_true_initial_wavelength_err2(num_val);
  float f_final_wavelength;
  float f_final_wavelength_err2;
  float f_time_offset;
  float f_time_offset_err2;
  float f_dist_source_sample;
  float f_dist_source_sample_err2;
  float f_dist_sample_detector;
  float f_dist_sample_detector_err2;
  float f_a, f_a2;
  float f_b;
  float f_c, f_c2;
  float f_d, f_d2;
  float f_ls2;

  //double
  Nessi::Vector<double> d_tof;
  Nessi::Vector<double> d_tof_err2;
  Nessi::Vector<double> d_initial_wavelength(num_val);
  Nessi::Vector<double> d_initial_wavelength_err2(num_val);
  Nessi::Vector<double> d_true_initial_wavelength(num_val);
  Nessi::Vector<double> d_true_initial_wavelength_err2(num_val);
  double d_final_wavelength;
  double d_final_wavelength_err2;
  double d_time_offset;
  double d_time_offset_err2;
  double d_dist_source_sample;
  double d_dist_source_sample_err2;
  double d_dist_sample_detector;
  double d_dist_sample_detector_err2;
  double d_a, d_a2;
  double d_b;
  double d_c, d_c2;
  double d_d, d_d2;
  double d_ls2;

  int error=0;          //==0,Pass  !=0,Fail

  double final_wavelength = 345.34;
  double final_wavelength_err2 = 35.;
  double time_offset = 0.0245;
  double time_offset_err2 = 0.002;
  double dist_source_sample = 34.45;
  double dist_source_sample_err2 = 9.2;
  double dist_sample_detector = 13.35;
  double dist_sample_detector_err2 = 8.5;

  f_final_wavelength = static_cast<float>(final_wavelength);
  f_final_wavelength_err2 = static_cast<float>(final_wavelength_err2);
  f_time_offset = static_cast<float>(time_offset);
  f_time_offset_err2 = static_cast<float>(time_offset_err2);
  f_dist_source_sample = static_cast<float>(dist_source_sample);
  f_dist_source_sample_err2 = static_cast<float>(dist_source_sample_err2);
  f_dist_sample_detector = static_cast<float>(dist_sample_detector);
  f_dist_sample_detector_err2 = static_cast<float>(dist_sample_detector_err2);

  d_final_wavelength = static_cast<double>(final_wavelength);
  d_final_wavelength_err2 = static_cast<double>(final_wavelength_err2);
  d_time_offset = static_cast<double>(time_offset);
  d_time_offset_err2 = static_cast<double>(time_offset_err2);
  d_dist_source_sample = static_cast<double>(dist_source_sample);
  d_dist_source_sample_err2 = static_cast<double>(dist_source_sample_err2);
  d_dist_sample_detector = static_cast<double>(dist_sample_detector);
  d_dist_sample_detector_err2 = static_cast<double>(dist_sample_detector_err2);

  for (int i = 0 ; i < num_val ; i++)      //create the arrays
    {
      //_input1 array
      f_tof.push_back(2.*static_cast<float>(i+1));
      d_tof.push_back(2.*static_cast<double>(i+1));

      f_tof_err2.push_back(static_cast<float>(i+2));
      d_tof_err2.push_back(static_cast<double>(i+2));
    }

  AxisManip::tof_to_initial_wavelength_igs(f_tof, f_tof_err2,
             f_final_wavelength,
             f_final_wavelength_err2,
             f_time_offset, f_time_offset_err2,
             f_dist_source_sample,
             f_dist_source_sample_err2,
             f_dist_sample_detector,
             f_dist_sample_detector_err2,
             f_initial_wavelength,
             f_initial_wavelength_err2);

  AxisManip::tof_to_initial_wavelength_igs(d_tof, d_tof_err2,
             d_final_wavelength,
             d_final_wavelength_err2,
             d_time_offset, d_time_offset_err2,
             d_dist_source_sample,
             d_dist_source_sample_err2,
             d_dist_sample_detector,
             d_dist_sample_detector_err2,
             d_initial_wavelength,
             d_initial_wavelength_err2);

  f_a = static_cast<float>(PhysConst::H_OVER_MNEUT / f_dist_source_sample);
  f_a2 = f_a * f_a;

  f_b = (f_dist_sample_detector * f_final_wavelength);
  f_b = f_b / f_dist_source_sample;
  f_b += (f_a * f_time_offset);

  f_c = f_final_wavelength / f_dist_source_sample;
  f_c2 = f_c * f_c;

  f_d = f_dist_sample_detector / f_dist_source_sample;
  f_d2 = f_d * f_d;

  f_ls2 = f_dist_source_sample * f_dist_source_sample;


  d_a = static_cast<double>(PhysConst::H_OVER_MNEUT / d_dist_source_sample);
  d_a2 = d_a * d_a;
  d_b = (d_dist_sample_detector * d_final_wavelength);
  d_b =  d_b / d_dist_source_sample;
  d_b += (d_a * d_time_offset);

  d_c = d_final_wavelength / d_dist_source_sample;
  d_c2 = d_c * d_c;

  d_d = d_dist_sample_detector / d_dist_source_sample;
  d_d2 = d_d * d_d;

  d_ls2 = d_dist_source_sample * d_dist_source_sample;

  for (int i = 0 ; i < num_val ; i++)
    {
      //float
      f_true_initial_wavelength[i] = f_a * f_tof[i] - f_b;
      f_true_initial_wavelength_err2[i] = f_a2 * (f_tof_err2[i] +
              f_time_offset_err2);
      f_true_initial_wavelength_err2[i] += f_c2 * f_dist_sample_detector_err2;
      f_true_initial_wavelength_err2[i] += f_d2 * f_final_wavelength_err2;
      f_true_initial_wavelength_err2[i] += f_initial_wavelength[i] *
  f_initial_wavelength[i] * f_dist_source_sample_err2 / f_ls2;

      //double
      d_true_initial_wavelength[i] = (d_a * d_tof[i]) - d_b;
      d_true_initial_wavelength_err2[i] = d_a2 * (d_tof_err2[i] +
              d_time_offset_err2);
      d_true_initial_wavelength_err2[i] += d_c2 * d_dist_sample_detector_err2;
      d_true_initial_wavelength_err2[i] += d_d2 * d_final_wavelength_err2;
      d_true_initial_wavelength_err2[i] += d_initial_wavelength[i] *
  d_initial_wavelength[i] * d_dist_source_sample_err2 / d_ls2;
    }

  //check first if the size are in good agreement
  if ( (f_tof.size() != f_initial_wavelength.size())
       || (d_tof.size() != d_initial_wavelength.size()) )
    {
      cout << "Input and output vectors do not have the same size"  << endl;
      ++error;
    }
  else
    {
      while(1)
  {
    Utils::vector_comparison(f_initial_wavelength, f_true_initial_wavelength,
           error, 10);
    if (error != 0) break;
    Utils::vector_comparison(f_initial_wavelength_err2,
           f_true_initial_wavelength_err2,
           error, 20);
    if (error != 0) break;

    Utils::vector_comparison(d_initial_wavelength, d_true_initial_wavelength,
           error, 110);
    if (error != 0) break;
    Utils::vector_comparison(d_initial_wavelength_err2,
           d_true_initial_wavelength_err2,
           error, 120);
    break;
  }
    }

  cout << "tof_to_initial_wavelength_igs_test.cpp..........";

  switch (error)
    {
    case 0:
      cout << "Functionality OK" << endl;
      break;
    case 1:
      cout << "FAILED....Output and input vectors have different sizes" << endl;
      break;
    case 10:
      cout << "(float) FAILED....Output vector different from vector expected"
     << endl;
      break;
    case 20:
      cout << "(float) FAILED....Output error vector different from vector "
     << "expected" << endl;
      break;
    case 110:
      cout << "(double) FAILED....Output vector different from vector expected"
     << endl;
      break;
    case 120:
      cout << "(double) FAILED....Output error vector different from vector "
     << "expected" << endl;
      break;
    default:
      cout << "FAILED" << endl;
      break;
    }

  return 0;
}
*/
