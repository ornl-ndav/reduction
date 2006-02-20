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
 * \file axis_manip/test/cpp/tof_to_wavelength_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup tof_to_wavelength_test tof_to_wavelength_test
 *
 * This test compares the output data calculated by the library
 * function tof_to_wavelength() and described in 3.15
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
                       Nessi::Vector<NumT> & tof_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      tof.push_back(static_cast<NumT>(i+1));
      tof_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function generate the values for float to compare the calculation to.
 */
void initialize_true_outputs(float    & true_output_ss,
                             float    & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(0.00079120678128674626);
  true_output_ss_err2=static_cast<float>(0.00000037560488408417);

  // vector vector
  true_output_vv.push_back(static_cast<float>(0.00079120678128674626));
  true_output_vv_err2.push_back(static_cast<float>(0.00000037560488408417));
  true_output_vv.push_back(static_cast<float>(0.00158241356257349253));
  true_output_vv_err2.push_back(static_cast<float>(0.00000118941545679263));
  true_output_vv.push_back(static_cast<float>(0.00237362040206789970));
  true_output_vv_err2.push_back(static_cast<float>(0.00000212842769542476));
  true_output_vv.push_back(static_cast<float>(0.00316482712514698505));
  true_output_vv_err2.push_back(static_cast<float>(0.00000319264154313714));
  true_output_vv.push_back(static_cast<float>(0.00395603384822607040));
  true_output_vv_err2.push_back(static_cast<float>(0.00000438205688624294));
}

/**
 * This function generate the values for double to compare the calculation to.
 */
void initialize_true_outputs(double    & true_output_ss,
                             double    & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(0.00079120679999999997);
  true_output_ss_err2=static_cast<double>(0.00000037560492021974);

  // vector vector
  true_output_vv.push_back(static_cast<double>(0.00079120679999999997));
  true_output_vv_err2.push_back(static_cast<double>(0.00000037560492021974));
  true_output_vv.push_back(static_cast<double>(0.00158241359999999995));
  true_output_vv_err2.push_back(static_cast<double>(0.00000118941558069586));
  true_output_vv.push_back(static_cast<double>(0.00237362040000000003));
  true_output_vv_err2.push_back(static_cast<double>(0.00000212842788124522));
  true_output_vv.push_back(static_cast<double>(0.00316482719999999990));
  true_output_vv_err2.push_back(static_cast<double>( 0.00000319264182186782));
  true_output_vv.push_back(static_cast<double>(0.00395603399999999977));
  true_output_vv_err2.push_back(static_cast<double>(0.00000438205740256368));
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
         Nessi::Vector<NumT> & true_output_vv_err2)
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

  // vector vector
  if(!test_okay(output_vv,true_output_vv,VV))
    {
      value = false;
    }
  if(!test_okay(output_vv_err2,true_output_vv_err2,VV))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 * Function that runs the test for a numeric type
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{ 
// allocate arrays
  Nessi::Vector<NumT>   tof;
  Nessi::Vector<NumT>   tof_err2;
  NumT                  pathlength=static_cast<NumT>(5.);
  NumT                  pathlength_err2=static_cast<NumT>(2.5);
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

  AxisManip::tof_to_wavelength(tof[0], tof_err2[0],
                               pathlength, pathlength_err2,
                               output_ss,
                               output_ss_err2);

  AxisManip::tof_to_wavelength(tof, tof_err2,
                               pathlength, pathlength_err2,
                               output_vv,
                               output_vv_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv, true_output_vv, VV, debug);
      print(output_vv_err2, true_output_vv_err2, ERROR+VV, debug);
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }
  
  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_vv, output_vv_err2,
                   true_output_vv, true_output_vv_err2);
}

/**
 * Main function that test energy_transfer for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "tof_to_wavelength_test.cpp..........";
  
  string debug;
  if(argc > 1)
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

  cout << "Functionality OK" << endl;

  return 0;
}
