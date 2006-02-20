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
 * \file axis_manip/test/cpp/wavelength_to_energy_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup wavelength_to_energy_test wavelength_to_energy_test
 *
 * This test compares the output data calculated by the library
 * function wavelength_to_energy() and described in 3.22
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
                       Nessi::Vector<NumT> & wavelength_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      wavelength.push_back(static_cast<NumT>(i+1));
      wavelength_err2.push_back(static_cast<NumT>(i+0.5));
    }
}

/**
 * This function generate the values to compare the calculation to.
 */
void initialize_true_outputs(float    & true_output_ss,
                             float    & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(81.8042068481);
  true_output_ss_err2=static_cast<float>(13383.8564453125);

  // vector vector
  true_output_vv.push_back(static_cast<float>(81.8042068481));
  true_output_vv_err2.push_back(static_cast<float>(13383.8564453125));
  true_output_vv.push_back(static_cast<float>(20.4510517120));
  true_output_vv_err2.push_back(static_cast<float>(627.3682861328125));
  true_output_vv.push_back(static_cast<float>(9.08935642242));
  true_output_vv_err2.push_back(static_cast<float>(91.79599761962890));
  true_output_vv.push_back(static_cast<float>(5.11276292800));
  true_output_vv_err2.push_back(static_cast<float>(22.87280082702636));
  true_output_vv.push_back(static_cast<float>(3.27216815948));
  true_output_vv_err2.push_back(static_cast<float>(7.709101676940917));
}

void initialize_true_outputs(double    & true_output_ss,
                             double    & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(81.8042051000000043);
  true_output_ss_err2=static_cast<double>(13383.8559440857334266);

  // vector vector
  true_output_vv.push_back(static_cast<double>(81.80420510000000433));
  true_output_vv_err2.push_back(static_cast<double>(13383.85594408573342661));
  true_output_vv.push_back(static_cast<double>(20.45105127500000108));
  true_output_vv_err2.push_back(static_cast<double>(627.3682473790187259510));
  true_output_vv.push_back(static_cast<double>(9.089356122222222111));
  true_output_vv_err2.push_back(static_cast<double>(91.79599412953177761664));
  true_output_vv.push_back(static_cast<double>(5.112762818750000270));
  true_output_vv_err2.push_back(static_cast<double>(22.87280068569339164241));
  true_output_vv.push_back(static_cast<double>(3.272168204000000191));
  true_output_vv_err2.push_back(static_cast<double>(7.709101023793382800874));
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
  Nessi::Vector<NumT>   wavelength;
  Nessi::Vector<NumT>   wavelength_err2;
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
  AxisManip::wavelength_to_energy(wavelength[0], wavelength_err2[0],
                                  output_ss, output_ss_err2);

  AxisManip::wavelength_to_energy(wavelength, wavelength_err2,
                                  output_vv, output_vv_err2);

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
  cout << "wavelength_to_energy_test.cpp..........";

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
