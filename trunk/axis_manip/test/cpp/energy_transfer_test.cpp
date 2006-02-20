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
 * \file axis_manip/test/cpp/energy_transfer_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup energy_transfer_test energy_transfer_test
 *
 * This test compares the output data calculated by the library
 * function energy_transfer() and described in 3.30 of the DR_Lib_RS_q
 * with the true output data manually calculated. Any discrepancy
 * between the outputs will generate an error message in the
 * testsuite.log file that gives details about the location and type
 * of the error.
 */

/**
 * This function initiales the input arrays.
 */
template <typename NumT>
void initialize_inputs(Nessi::Vector<NumT> & E_i,
                       Nessi::Vector<NumT> & E_i_err2,
                       Nessi::Vector<NumT> & E_f,
                       Nessi::Vector<NumT> & E_f_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      E_i.push_back(static_cast<NumT>(2*i));
      E_i_err2.push_back(static_cast<NumT>(i+0.5));
      E_f.push_back(static_cast<NumT>(2.5+i));
      E_f_err2.push_back(static_cast<NumT>(1.5+i));
    }
}

/**
 * This function generate the values for float to compare the calculation to
 */
void initialize_true_outputs(float                & true_output_ss,
                             float                & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_sv,
                             Nessi::Vector<float> & true_output_sv_err2,
                             Nessi::Vector<float> & true_output_vs,
                             Nessi::Vector<float> & true_output_vs_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2)
{
  // scalar scalar
  //  true_output_ss=static_cast<float>(-0.604497373104095458984375);
  //  true_output_ss_err2=static_cast<float>(0.116933457553386688232421875000);
  true_output_ss=static_cast<float>(-0.6044973731);
  true_output_ss_err2=static_cast<float>(0.1169334575);

  // scalar vector
  true_output_sv.push_back(static_cast<float>(-0.6044973731));
  true_output_sv_err2.push_back(static_cast<float>(0.1169334575));
  true_output_sv.push_back(static_cast<float>(-0.8462963104));
  true_output_sv_err2.push_back(static_cast<float>(0.1754001826));
  true_output_sv.push_back(static_cast<float>(-1.0880953073));
  true_output_sv_err2.push_back(static_cast<float>(0.2338669151));
  true_output_sv.push_back(static_cast<float>(-1.3298941850));
  true_output_sv_err2.push_back(static_cast<float>(0.2923336327));
  true_output_sv.push_back(static_cast<float>(-1.5716931819));
  true_output_sv_err2.push_back(static_cast<float>(0.3508003652));

  // vector scalar
  true_output_vs.push_back(static_cast<float>(-0.6044973731));
  true_output_vs_err2.push_back(static_cast<float>(0.1169334575));
  true_output_vs.push_back(static_cast<float>(-0.12089947611));
  true_output_vs_err2.push_back(static_cast<float>(0.17540018260));
  true_output_vs.push_back(static_cast<float>(0.3626984059));
  true_output_vs_err2.push_back(static_cast<float>(0.23386691510));
  true_output_vs.push_back(static_cast<float>(0.8462963104));
  true_output_vs_err2.push_back(static_cast<float>(0.2923336327));
  true_output_vs.push_back(static_cast<float>(1.3298941850));
  true_output_vs_err2.push_back(static_cast<float>(0.3508003652));

  // vector vector
  true_output_vv.push_back(static_cast<float>(-0.6044973731));
  true_output_vv_err2.push_back(static_cast<float>(0.1169334575));
  true_output_vv.push_back(static_cast<float>(-0.3626984059));
  true_output_vv_err2.push_back(static_cast<float>(0.2338669151));
  true_output_vv.push_back(static_cast<float>(-0.1208994761));
  true_output_vv_err2.push_back(static_cast<float>(0.3508003652));
  true_output_vv.push_back(static_cast<float>(0.1208994761));
  true_output_vv_err2.push_back(static_cast<float>(0.4677338302));
  true_output_vv.push_back(static_cast<float>(0.3626984059));
  true_output_vv_err2.push_back(static_cast<float>(0.5846672654));
}

/**
 * This function generate the values for double to compare the calculation to
 */
void initialize_true_outputs(double                & true_output_ss,
                             double                & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_sv,
                             Nessi::Vector<double> & true_output_sv_err2,
                             Nessi::Vector<double> & true_output_vs,
                             Nessi::Vector<double> & true_output_vs_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2)
{
  // scalar scalar
  true_output_ss=static_cast<double>(-0.60449734953663813);
  true_output_ss_err2=static_cast<double>(0.11693345459098256);

  // scalar vector
  true_output_sv.push_back(static_cast<double>(-0.60449734953663813));
  true_output_sv_err2.push_back(static_cast<double>(0.1169334545909825));
  true_output_sv.push_back(static_cast<double>(-0.84629628935129341));
  true_output_sv_err2.push_back(static_cast<double>(0.17540018188647385));
  true_output_sv.push_back(static_cast<double>(-1.088095229165948696));
  true_output_sv_err2.push_back(static_cast<double>(0.23386690918196512));
  true_output_sv.push_back(static_cast<double>(-1.32989416898060408));
  true_output_sv_err2.push_back(static_cast<double>(0.29233363647745641));
  true_output_sv.push_back(static_cast<double>(-1.57169310879525925));
  true_output_sv_err2.push_back(static_cast<double>(0.35080036377294770));

  // vector scalar
  true_output_vs.push_back(static_cast<double>(-0.60449734953663813));
  true_output_vs_err2.push_back(static_cast<double>(0.11693345459098256));
  true_output_vs.push_back(static_cast<double>(-0.12089946990732763));
  true_output_vs_err2.push_back(static_cast<double>(0.17540018188647385));
  true_output_vs.push_back(static_cast<double>(0.362698409721982917));
  true_output_vs_err2.push_back(static_cast<double>(0.23386690918196512));
  true_output_vs.push_back(static_cast<double>(0.846296289351293418));
  true_output_vs_err2.push_back(static_cast<double>(0.29233363647745641));
  true_output_vs.push_back(static_cast<double>(1.329894168980604085));
  true_output_vs_err2.push_back(static_cast<double>(0.35080036377294770));

  // vector vector
  true_output_vv.push_back(static_cast<double>(-0.60449734953663813));
  true_output_vv_err2.push_back(static_cast<double>(0.11693345459098256));
  true_output_vv.push_back(static_cast<double>(-0.36269840972198291));
  true_output_vv_err2.push_back(static_cast<double>(0.23386690918196512));
  true_output_vv.push_back(static_cast<double>(-0.12089946990732763));
  true_output_vv_err2.push_back(static_cast<double>(0.35080036377294770));
  true_output_vv.push_back(static_cast<double>(0.120899469907327639));
  true_output_vv_err2.push_back(static_cast<double>(0.46773381836393024));
  true_output_vv.push_back(static_cast<double>(0.362698409721982917));
  true_output_vv_err2.push_back(static_cast<double>(0.58466727295491283));
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

  // scalar vector
  if(!test_okay(output_sv,true_output_sv,SV))
    {
      value = false;
    }
  if(!test_okay(output_sv_err2,true_output_sv_err2,SV))
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

  // scalar vector
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
  Nessi::Vector<NumT> E_i;
  Nessi::Vector<NumT> E_i_err2;
  Nessi::Vector<NumT> E_f;
  Nessi::Vector<NumT> E_f_err2;
  NumT                output_ss;
  NumT                output_ss_err2;
  NumT                true_output_ss;
  NumT                true_output_ss_err2;
  Nessi::Vector<NumT> output_sv(5);
  Nessi::Vector<NumT> output_sv_err2(5);
  Nessi::Vector<NumT> true_output_sv;
  Nessi::Vector<NumT> true_output_sv_err2;
  Nessi::Vector<NumT> output_vs(5);
  Nessi::Vector<NumT> output_vs_err2(5);
  Nessi::Vector<NumT> true_output_vs;
  Nessi::Vector<NumT> true_output_vs_err2;
  Nessi::Vector<NumT> output_vv(5);
  Nessi::Vector<NumT> output_vv_err2(5);
  Nessi::Vector<NumT> true_output_vv;
  Nessi::Vector<NumT> true_output_vv_err2;

  // fill in values as appropriate
  initialize_inputs(E_i,E_i_err2,E_f,E_f_err2);
  initialize_true_outputs(true_output_ss, true_output_ss_err2,
                          true_output_sv, true_output_sv_err2,
                          true_output_vs, true_output_vs_err2,
                          true_output_vv, true_output_vv_err2);

  // run the code being tested
  AxisManip::energy_transfer(E_i[0], E_i_err2[0],
                             E_f[0], E_f_err2[0],
                             output_ss, output_ss_err2);

  AxisManip::energy_transfer(E_i[0], E_i_err2[0],
                             E_f, E_f_err2,
                             output_sv, output_sv_err2);

  AxisManip::energy_transfer(E_i, E_i_err2,
                             E_f[0], E_f_err2[0],
                             output_vs, output_vs_err2);

  AxisManip::energy_transfer(E_i, E_i_err2,
                             E_f, E_f_err2,
                             output_vv, output_vv_err2);

  if(!debug.empty())
    {
      cout << endl;
      print(output_vv, true_output_vv, VV, debug);
      print(output_vv_err2, true_output_vv_err2, ERROR+VV, debug);
      print(output_vs, true_output_vs, VS, debug);
      print(output_vs_err2, true_output_vs_err2, ERROR+VS, debug);
      print(output_sv, true_output_sv, SV, debug);
      print(output_sv_err2, true_output_sv_err2, ERROR+SV, debug);
      print(output_ss, true_output_ss, SS, debug);
      print(output_ss_err2, true_output_ss_err2, ERROR+SS, debug);
    }

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
 * Main function that test energy_transfer for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "energy_transfer_test.cpp..........";

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
