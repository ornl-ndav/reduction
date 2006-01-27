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
void initialize_inputs(Nessi::Vector<NumT> & k_i,
                       Nessi::Vector<NumT> & k_i_err2,
                       Nessi::Vector<NumT> & k_f,
                       Nessi::Vector<NumT> & k_f_err2){
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
//template <typename NumT>  //REMOVE

/*void initialize_true_outputs(NumT                & true_output_ss,
                             NumT                & true_output_ss_err2,
                             Nessi::Vector<NumT> & true_output_sv,
                             Nessi::Vector<NumT> & true_output_sv_err2,
                             Nessi::Vector<NumT> & true_output_vs,
                             Nessi::Vector<NumT> & true_output_vs_err2,
                             Nessi::Vector<NumT> & true_output_vv,
                             Nessi::Vector<NumT> & true_output_vv_err2){
*/
void initialize_true_outputs(float                & true_output_ss,
                             float                & true_output_ss_err2,
                             Nessi::Vector<float> & true_output_sv,
                             Nessi::Vector<float> & true_output_sv_err2,
                             Nessi::Vector<float> & true_output_vs,
                             Nessi::Vector<float> & true_output_vs_err2,
                             Nessi::Vector<float> & true_output_vv,
                             Nessi::Vector<float> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<float>(0.35036611557006835938);
  true_output_ss_err2=static_cast<float>(0.41659948229789733887);

  // scalar vector
  true_output_sv.push_back(static_cast<float>(0.35036611557006835938));
  true_output_sv_err2.push_back(static_cast<float>(0.41659948229789733887));
  true_output_sv.push_back(static_cast<float>(1.29265675181475581113));
  true_output_sv_err2.push_back(static_cast<float>(1.65810190421910097491));
  true_output_sv.push_back(static_cast<float>(2.28454947471618652344));
  true_output_sv_err2.push_back(static_cast<float>(2.69188070297241210938));
  true_output_sv.push_back(static_cast<float>(3.28136730194091796875));
  true_output_sv_err2.push_back(static_cast<float>(3.70446825027465820312));
  true_output_sv.push_back(static_cast<float>(4.27967023849487304688));
  true_output_sv_err2.push_back(static_cast<float>(4.71099901199340820312));

  // vector scalar
  true_output_vs.push_back(static_cast<float>(0.350366115570068359375));
  true_output_vs_err2.push_back(static_cast<float>(0.4165994822978973388671875));
  true_output_vs.push_back(static_cast<float>(0.82644593715667724609375 ));
  true_output_vs_err2.push_back(static_cast<float>(1.5647885799407958984375));
  true_output_vs.push_back(static_cast<float>(1.8009078502655029296875));
  true_output_vs_err2.push_back(static_cast<float>(2.682316303253173828125));
  true_output_vs.push_back(static_cast<float>(2.7934792041778564453125));
  true_output_vs_err2.push_back(static_cast<float>(3.708995819091796875));
  true_output_vs.push_back(static_cast<float>(3.7899582386016845703125));
  true_output_vs_err2.push_back(static_cast<float>(4.720211029052734375));

  // vector vector
  true_output_vv.push_back(static_cast<float>(0.350366115570068359375));
  true_output_vv_err2.push_back(static_cast<float>(0.4165994822978973388671875));
  true_output_vv.push_back(static_cast<float>(0.52860486507415771484375));
  true_output_vv_err2.push_back(static_cast<float>(0.98320102691650390625));
  true_output_vv.push_back(static_cast<float>(0.72972548007965087890625));
  true_output_vv_err2.push_back(static_cast<float>( 1.5125067234039306640625));
  true_output_vv.push_back(static_cast<float>(0.939141809940338134765625));
  true_output_vv_err2.push_back(static_cast<float>(2.245140552520751953125));
  true_output_vv.push_back(static_cast<float>(1.152339458465576171875));
  true_output_vv_err2.push_back(static_cast<float>( 3.2094576358795166015625));
}

void initialize_true_outputs(double                & true_output_ss,
                             double                & true_output_ss_err2,
                             Nessi::Vector<double> & true_output_sv,
                             Nessi::Vector<double> & true_output_sv_err2,
                             Nessi::Vector<double> & true_output_vs,
                             Nessi::Vector<double> & true_output_vs_err2,
                             Nessi::Vector<double> & true_output_vv,
                             Nessi::Vector<double> & true_output_vv_err2){
  // scalar scalar
  true_output_ss=static_cast<double>(0.350366060961226966075088284924);
  true_output_ss_err2=static_cast<double>(0.416599643788511941888685896629);

  // scalar vector
  true_output_sv.push_back(static_cast<double>(0.350366060961226966075088284924));
  true_output_sv_err2.push_back(static_cast<double>(0.416599643788511941888685896629));
  true_output_sv.push_back(static_cast<double>(1.292656751814755811125223772251));
  true_output_sv_err2.push_back(static_cast<double>(1.658101904219100974913203572214));
  true_output_sv.push_back(static_cast<double>(2.284549535324428948257491356344));
  true_output_sv_err2.push_back(static_cast<double>(2.691880339911111086337314191042));
  true_output_sv.push_back(static_cast<double>(3.281367349244801445706798403990));
  true_output_sv_err2.push_back(static_cast<double>(3.704467899594361401938158451230));
  true_output_sv.push_back(static_cast<double>(4.279670172107733705502141674515));
  true_output_sv_err2.push_back(static_cast<double>(4.710998620505037592920416500419));

  // vector scalar
  true_output_vs.push_back(static_cast<double>(0.350366060961226966075088284924));
  true_output_vs_err2.push_back(static_cast<double>(0.416599643788511941888685896629));
  true_output_vs.push_back(static_cast<double>(0.826445856270676904031802223471));
  true_output_vs_err2.push_back(static_cast<double>(1.564788674638813770201295483275));
  true_output_vs.push_back(static_cast<double>(1.800907862723814645278253010474));
  true_output_vs_err2.push_back(static_cast<double>(2.682315931126148633723005332286));
  true_output_vs.push_back(static_cast<double>(2.793479104395439005514845121070));
  true_output_vs_err2.push_back(static_cast<double>(3.708996112578096138179262197809));
  true_output_vs.push_back(static_cast<double>(3.789958031874156585416812959011));
  true_output_vs_err2.push_back(static_cast<double>(4.720211648202864651580057397950));

  // vector vector
  true_output_vv.push_back(static_cast<double>(0.350366060961226966075088284924));
  true_output_vv_err2.push_back(static_cast<double>(0.416599643788511941888685896629));
  true_output_vv.push_back(static_cast<double>( 0.528604725692601418174376703973));
  true_output_vv_err2.push_back(static_cast<double>(0.983201585879540318479996585666));
  true_output_vv.push_back(static_cast<double>( 0.729725796483303490447269723518));
  true_output_vv_err2.push_back(static_cast<double>(1.512505204385275359157958519063
));
  true_output_vv.push_back(static_cast<double>(0.939141481758426266424066852778));
  true_output_vv_err2.push_back(static_cast<double>( 2.245142119443735317929622397060));
  true_output_vv.push_back(static_cast<double>(1.152338452948267644160296185873));
  true_output_vv_err2.push_back(static_cast<double>(3.209463035565176092234196403297));
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
