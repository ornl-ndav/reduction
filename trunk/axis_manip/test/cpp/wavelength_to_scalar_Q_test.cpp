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
 * \file axis_manip/test/cpp/wavelength_to_scalar_Q_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup wavelength_to_scalar_Q_test wavelength_to_scalar_Q_test
 * \{
 *
 */

/**

 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & wavelength,
                       Nessi::Vector<NumT> & wavelength_err2,
                       NumT & scatt_angle,
                       NumT & scatt_angle_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      wavelength.push_back(static_cast<NumT>(2*i+1));
      wavelength_err2.push_back(static_cast<NumT>(i+0.5));
      scatt_angle = static_cast<NumT>(2.);
      scatt_angle_err2 = static_cast<NumT>(0.5);
    }
}

/**
 */
void initialize_true_outputs(float                & true_output_ss,
                             float                & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_vs,
                             Nessi::Vector<float> & true_output_vs_err2)
{
  // scalar scalar
  true_output_ss=static_cast<float>(11.4265689850);
  true_output_ss_err2=static_cast<float>(32.4255943298);

  // vector scalar
  true_output_vs.push_back(static_cast<float>(11.4265689850));
  true_output_vs_err2.push_back(static_cast<float>(32.4255943298));
  true_output_vs.push_back(static_cast<float>(3.8088562489));
  true_output_vs_err2.push_back(static_cast<float>(-1.2329516411));
  true_output_vs.push_back(static_cast<float>(2.2853136063));
  true_output_vs_err2.push_back(static_cast<float>(-0.7920397520));
  true_output_vs.push_back(static_cast<float>(1.6323668957));
  true_output_vs_err2.push_back(static_cast<float>(-0.4802339375));
  true_output_vs.push_back(static_cast<float>(1.2696187496));
  true_output_vs_err2.push_back(static_cast<float>(-0.3160981238));

}

/**
 */
void initialize_true_outputs(double                & true_output_ss,
                             double                & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_vs,
                             Nessi::Vector<double> & true_output_vs_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(11.42656846417465566);
  true_output_ss_err2=static_cast<double>(32.42559623735466801);

  // vector scalar
  true_output_vs.push_back(static_cast<double>(11.42656846417465566));
  true_output_vs_err2.push_back(static_cast<double>(32.42559623735466801));
  true_output_vs.push_back(static_cast<double>(3.80885615472488537));
  true_output_vs_err2.push_back(static_cast<double>(-1.23295104275580614));
  true_output_vs.push_back(static_cast<double>(2.28531369283493113));
  true_output_vs_err2.push_back(static_cast<double>(-0.79203962036934561));
  true_output_vs.push_back(static_cast<double>(1.63236692345352230));
  true_output_vs_err2.push_back(static_cast<double>(-0.48023389777822056));
  true_output_vs.push_back(static_cast<double>(1.26961871824162853));
  true_output_vs_err2.push_back(static_cast<double>(-0.31609808138503581));
}

/**
 */
template <typename NumT>
bool test_okay(NumT                & output_ss,
               NumT                & output_ss_err2,
               NumT                & true_output_ss,
               NumT                & true_output_ss_err2,
               Nessi::Vector<NumT> & output_vs,
               Nessi::Vector<NumT> & output_vs_err2,
               Nessi::Vector<NumT> & true_output_vs,
               Nessi::Vector<NumT> & true_output_vs_err2)
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

  // vector scalar
  if(!test_okay(output_vs,true_output_vs,VS))
    {
      value = false;
    }
  if(!test_okay(output_vs_err2,true_output_vs_err2,VS))
    {
      value = false;
    }

  // everything okay
  return value;
}

/**
 */
template <typename NumT>
bool test_func(NumT key, string debug) // key forces correct test to happen
{
  // allocate arrays
  Nessi::Vector<NumT> wavelength;
  Nessi::Vector<NumT> wavelength_err2;
  NumT                scatt_angle;
  NumT                scatt_angle_err2;
  NumT                output_ss;
  NumT                output_ss_err2;
  NumT                true_output_ss;
  NumT                true_output_ss_err2;
  Nessi::Vector<NumT> output_vs(5);
  Nessi::Vector<NumT> output_vs_err2(5);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;

  // fill in values as appropriate
  initialize_inputs(wavelength,
                    wavelength_err2,
                    scatt_angle,
                    scatt_angle_err2);

  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_vs, true_output_vs_err2);

  // run the code being tested
  AxisManip::wavelength_to_scalar_Q(wavelength[0],
                                    wavelength_err2[0],
                                    scatt_angle,
                                    scatt_angle_err2,
                                    output_ss, 
                                    output_ss_err2);
  
  AxisManip::wavelength_to_scalar_Q(wavelength,
                                    wavelength_err2,
                                    scatt_angle,
                                    scatt_angle_err2,
                                    output_vs, 
                                    output_vs_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vs, true_output_vs, VS, debug);
      print(output_vs_err2, true_output_vs_err2, ERROR+VS, debug);
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }

  return test_okay(output_ss, output_ss_err2,
                   true_output_ss, true_output_ss_err2,
                   output_vs, output_vs_err2,
                   true_output_vs, true_output_vs_err2);
}

/**
 * Main function that test wavelength_to_scalar_Q for float and double.
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "wavelength_to_scalar_Q_test.cpp..........";

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
