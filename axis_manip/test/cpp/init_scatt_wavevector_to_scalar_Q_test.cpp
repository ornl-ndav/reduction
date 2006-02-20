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
 * \file axis_manip/test/cpp/init_scatt_wavevector_to_scalar_Q_test.cpp
 */

#include "conversions.hpp"
#include "test_common.hpp"

using namespace std;

const size_t NUM_VAL=5;

/**
 * \defgroup init_scatt_wavevector_to_scalar_Q \
 * init_scatt_wavevector_to_scalar_Q
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
void initialize_inputs(Nessi::Vector<NumT> & k_i,
                       Nessi::Vector<NumT> & k_i_err2,
                       Nessi::Vector<NumT> & k_f,
                       Nessi::Vector<NumT> & k_f_err2)
{
  for( size_t i=0 ; i<NUM_VAL ; i++ )
    {
      k_i.push_back(static_cast<NumT>(i+1));
      k_i_err2.push_back(static_cast<NumT>(i+0.5));
      k_f.push_back(static_cast<NumT>(i+1.25));
      k_f_err2.push_back(static_cast<NumT>(i+0.25));
    }
}

/**
 * This function generate the values to compare the calculation to.
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
  true_output_ss=static_cast<float>(0.3503661155);
  true_output_ss_err2=static_cast<float>(0.4165994822);

  // scalar vector
  true_output_sv.push_back(static_cast<float>(0.3503661155));
  true_output_sv_err2.push_back(static_cast<float>(0.4165994822));
  true_output_sv.push_back(static_cast<float>(1.2926567518));
  true_output_sv_err2.push_back(static_cast<float>(1.6581019042));
  true_output_sv.push_back(static_cast<float>(2.2845494747));
  true_output_sv_err2.push_back(static_cast<float>(2.6918807029));
  true_output_sv.push_back(static_cast<float>(3.2813673019));
  true_output_sv_err2.push_back(static_cast<float>(3.7044682502));
  true_output_sv.push_back(static_cast<float>(4.2796702384));
  true_output_sv_err2.push_back(static_cast<float>(4.7109990119));

  // vector scalar
  true_output_vs.push_back(static_cast<float>(0.3503661155));
  true_output_vs_err2.push_back(static_cast<float>(0.4165994822));
  true_output_vs.push_back(static_cast<float>(0.8264459371));
  true_output_vs_err2.push_back(static_cast<float>(1.5647885799));
  true_output_vs.push_back(static_cast<float>(1.8009078502));
  true_output_vs_err2.push_back(static_cast<float>(2.6823163032));
  true_output_vs.push_back(static_cast<float>(2.7934792041));
  true_output_vs_err2.push_back(static_cast<float>(3.7089958190));
  true_output_vs.push_back(static_cast<float>(3.7899582386));
  true_output_vs_err2.push_back(static_cast<float>(4.7202110290));

  // vector vector
  true_output_vv.push_back(static_cast<float>(0.3503661155));
  true_output_vv_err2.push_back(static_cast<float>(0.4165994822));
  true_output_vv.push_back(static_cast<float>(0.5286048650));
  true_output_vv_err2.push_back(static_cast<float>(0.9832010269));
  true_output_vv.push_back(static_cast<float>(0.7297254800));
  true_output_vv_err2.push_back(static_cast<float>( 1.512506723));
  true_output_vv.push_back(static_cast<float>(0.9391418099));
  true_output_vv_err2.push_back(static_cast<float>(2.2451405525));
  true_output_vv.push_back(static_cast<float>(1.1523394584));
  true_output_vv_err2.push_back(static_cast<float>(3.2094576355));
}

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
  true_output_ss=static_cast<double>(0.35036606096122696);
  true_output_ss_err2=static_cast<double>(0.41659964378851194);

  // scalar vector
  true_output_sv.push_back(static_cast<double>(0.35036606096122696));
  true_output_sv_err2.push_back(static_cast<double>(0.41659964378851194));
  true_output_sv.push_back(static_cast<double>(1.29265675181475581));
  true_output_sv_err2.push_back(static_cast<double>(1.65810190421910097));
  true_output_sv.push_back(static_cast<double>(2.28454953532442894));
  true_output_sv_err2.push_back(static_cast<double>(2.69188033991111108));
  true_output_sv.push_back(static_cast<double>(3.28136734924480144));
  true_output_sv_err2.push_back(static_cast<double>(3.70446789959436140));
  true_output_sv.push_back(static_cast<double>(4.27967017210773370));
  true_output_sv_err2.push_back(static_cast<double>(4.71099862050503759));

  // vector scalar
  true_output_vs.push_back(static_cast<double>(0.35036606096122696));
  true_output_vs_err2.push_back(static_cast<double>(0.41659964378851194));
  true_output_vs.push_back(static_cast<double>(0.82644585627067690));
  true_output_vs_err2.push_back(static_cast<double>(1.56478867463881377));
  true_output_vs.push_back(static_cast<double>(1.80090786272381464));
  true_output_vs_err2.push_back(static_cast<double>(2.68231593112614863));
  true_output_vs.push_back(static_cast<double>(2.79347910439543900));
  true_output_vs_err2.push_back(static_cast<double>(3.70899611257809613));
  true_output_vs.push_back(static_cast<double>(3.78995803187415658));
  true_output_vs_err2.push_back(static_cast<double>(4.72021164820286465));

  // vector vector
  true_output_vv.push_back(static_cast<double>(0.35036606096122696));
  true_output_vv_err2.push_back(static_cast<double>(0.41659964378851194));
  true_output_vv.push_back(static_cast<double>(0.52860472569260141));
  true_output_vv_err2.push_back(static_cast<double>(0.98320158587954031));
  true_output_vv.push_back(static_cast<double>(0.72972579648330349));
  true_output_vv_err2.push_back(static_cast<double>(1.51250520438527535));
  true_output_vv.push_back(static_cast<double>(0.93914148175842626));
  true_output_vv_err2.push_back(static_cast<double>(2.24514211944373531));
  true_output_vv.push_back(static_cast<double>(1.15233845294826764));
  true_output_vv_err2.push_back(static_cast<double>(3.20946303556517609));
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
  NumT                polar=static_cast<NumT>(0.22);
  NumT                polar_err2=static_cast<NumT>(0.11);
  Nessi::Vector<NumT> k_i;
  Nessi::Vector<NumT> k_i_err2;
  Nessi::Vector<NumT> k_f;
  Nessi::Vector<NumT> k_f_err2;
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
  initialize_inputs(k_i,k_i_err2,k_f,k_f_err2);
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
 * Main functino that test energy_transfer for float and double
 *
 * \param argc The number of command-line arguments present
 * \param argv The list of command-line arguments
 */
int main(int argc, char *argv[])
{
  cout << "init_scatt_wavevector_to_scalar_Q_test.cpp..........";

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
