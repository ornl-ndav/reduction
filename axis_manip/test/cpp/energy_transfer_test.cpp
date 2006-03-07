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
 * \{
 *
 * This test compares the output data calculated by the library
 * function <i>init_scatt_wavevector_to_scalar_Q</i> and described in 3.30
 * of the <i>SNS 107030214-TD0001-R00, "Data Reduction Library Software
 * Requirements and Specifications"</i> with the true output data
 * \f$true\_output\_ss\f$, \f$true\_output\_sv\f$, \f$true\_output\_vs\f$, and
 * \f$true\_output\_vv\f$ manually calculated.
 * Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
 * will generate in the testsuite.log file an error message that gives details
 * about the location and type of the error.
 *
 * <b>Notation used:</b>
 * - ss : scalar-scalar
 * - vv : vector-vector
 * - vs : vector-scalar
 * - sv : scalar-vector
 * - SS : "s,s"
 * - VV = "v,v"
 * - SV = "s,v"
 * - VS = "v,s"
 * - ERROR = "Error"
 * - EMPTY = ""
 */

/**
 * This function initializes the value of arrays, \f$E\_i\f$, \f$E\_i\_err2\f$,
 * \f$E\_f\f$, and \f$E\_f\_err2\f$.
 *
 * \param E_i (OUTPUT) is the initial energy
 * \param E_i_err2 (OUTPUT) is the square of the uncertainty of the initial
 * energy
 * \param E_f (OUTPUT) is the final energy
 * \param E_f_err2 (OUTPUT) is thes square of the uncertainty of the final
 * energy
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
 * This function sets the true outputs based on values contained in
 * \f$E\_i\f$, \f$E\_i\_err2\f$, \f$E\_f\f$, and \f$E\_f\_err2\f$ for the
 * float case.
 *
 * For the scalar case, the scalar used is the first element of the arrays
 * (\f$E\_i[0]\f$, \f$E\_i\_err2[0]\f$, \f$E\_f[0]\f$, and
 * \f$E\_f\_err2[0]\f$).
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_sv (OUTPUT) is the true array for the sv case
 * \param true_output_sv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the sv case
 * \param true_output_vs (OUTPUT) is the true array for the vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vs case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
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
  true_output_ss=static_cast<float>(-0.60449737);
  true_output_ss_err2=static_cast<float>(0.11693345);

  // scalar vector
  true_output_sv.push_back(static_cast<float>(-0.60449737));   
  true_output_sv_err2.push_back(static_cast<float>(0.11693345));
  true_output_sv.push_back(static_cast<float>(-0.84629631));
  true_output_sv_err2.push_back(static_cast<float>(0.17540018));
  true_output_sv.push_back(static_cast<float>(-1.08809530));
  true_output_sv_err2.push_back(static_cast<float>(0.23386691));
  true_output_sv.push_back(static_cast<float>(-1.32989418));
  true_output_sv_err2.push_back(static_cast<float>(0.29233363));
  true_output_sv.push_back(static_cast<float>(-1.57169318));
  true_output_sv_err2.push_back(static_cast<float>(0.35080036));

  // vector scalar
  true_output_vs.push_back(static_cast<float>(-0.60449737));
  true_output_vs_err2.push_back(static_cast<float>(0.11693345));
  true_output_vs.push_back(static_cast<float>(-0.12089947));
  true_output_vs_err2.push_back(static_cast<float>(0.17540018));
  true_output_vs.push_back(static_cast<float>(0.36269840));
  true_output_vs_err2.push_back(static_cast<float>(0.23386691));
  true_output_vs.push_back(static_cast<float>(0.84629631));
  true_output_vs_err2.push_back(static_cast<float>(0.29233363));
  true_output_vs.push_back(static_cast<float>(1.32989418));
  true_output_vs_err2.push_back(static_cast<float>(0.35080036));

  // vector vector
  true_output_vv.push_back(static_cast<float>(-0.60449737));
  true_output_vv_err2.push_back(static_cast<float>(0.11693345));
  true_output_vv.push_back(static_cast<float>(-0.36269840));
  true_output_vv_err2.push_back(static_cast<float>(0.23386691));
  true_output_vv.push_back(static_cast<float>(-0.12089947));
  true_output_vv_err2.push_back(static_cast<float>(0.35080036));
  true_output_vv.push_back(static_cast<float>(0.12089947));
  true_output_vv_err2.push_back(static_cast<float>(0.46773383));
  true_output_vv.push_back(static_cast<float>(0.36269840));
  true_output_vv_err2.push_back(static_cast<float>(0.58466726));
}

/**
 * This function sets the true outputs based on values contained in
 * \f$E\_i\f$, \f$E\_i\_err2\f$, \f$E\_f\f$, and \f$E\_f\_err2\f$ for the
 * double case.
 *
 * For the scalar case, the scalar used is the first element of the arrays (
 * \f$E\_i[0]\f$, \f$E\_i\_err2[0]\f$, \f$E\_f[0]\f$, and \f$E\_f\_err2[0]\f$.
 *
 * \param true_output_ss (OUTPUT) is the true output for the ss case
 * \param true_output_ss_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the ss case
 * \param true_output_sv (OUTPUT) is the true array for the sv case
 * \param true_output_sv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the sv case
 * \param true_output_vs (OUTPUT) is the true array for the vs case
 * \param true_output_vs_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vs case
 * \param true_output_vv (OUTPUT) is the true array for the vv case
 * \param true_output_vv_err2 (OUTPUT) is the square of the uncertainty of the
 * true output for the vv case
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
  true_output_sv_err2.push_back(static_cast<double>(0.11693345459098251));
  true_output_sv.push_back(static_cast<double>(-0.84629628935129341));
  true_output_sv_err2.push_back(static_cast<double>(0.17540018188647385));
  true_output_sv.push_back(static_cast<double>(-1.08809522916594869));
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
  true_output_vs.push_back(static_cast<double>(0.36269840972198291));
  true_output_vs_err2.push_back(static_cast<double>(0.23386690918196512));
  true_output_vs.push_back(static_cast<double>(0.84629628935129341));
  true_output_vs_err2.push_back(static_cast<double>(0.29233363647745641));
  true_output_vs.push_back(static_cast<double>(1.32989416898060408));
  true_output_vs_err2.push_back(static_cast<double>(0.35080036377294770));

  // vector vector
  true_output_vv.push_back(static_cast<double>(-0.60449734953663813));
  true_output_vv_err2.push_back(static_cast<double>(0.11693345459098256));
  true_output_vv.push_back(static_cast<double>(-0.36269840972198291));
  true_output_vv_err2.push_back(static_cast<double>(0.23386690918196512));
  true_output_vv.push_back(static_cast<double>(-0.12089946990732763));
  true_output_vv_err2.push_back(static_cast<double>(0.35080036377294770));
  true_output_vv.push_back(static_cast<double>(0.12089946990732763));
  true_output_vv_err2.push_back(static_cast<double>(0.46773381836393024));
  true_output_vv.push_back(static_cast<double>(0.36269840972198291));
  true_output_vv_err2.push_back(static_cast<double>(0.58466727295491283));
}

/**
 * Function that tests the discrepancies between the true outputs and the
 * outputs generated by the <i>energy_transfer</i> function for the ss, sv,
 * vs and  vv cases.
 *
 * The function returns TRUE if the two arrays compared \f$output\f$ and
 * \f$true\_output\f$ match, and returns FALSE if they do not match.
 *
 * \param output_ss (INPUT) is the value created by <i>energy_transfer</i> for
 * the ss case
 * \param output_ss_err2 (INPUT) is the square of the uncertainty of the value
 * created by <i>energy_transfer</i> for the ss case
 * \param true_output_ss (INPUT)) is the true value for the ss case
 * \param true_output_ss_err2 (INPUT) is the square of the uncertainty of the
 * true value for the ss case
 * \param output_sv (INPUT) is the array created by <i>energy_transfer</i> for
 * the sv case
 * \param output_sv_err2 (INPUT) is the square of the uncertainty in the array
 * created by <i>energy_transfer</i> for the sv case
 * \param true_output_sv (INPUT) is the true array for the sv case
 * \param true_output_sv_err2 (INPUT) is the square of the uncertainty in the
 * true array for the sv case
 * \param output_vs (INPUT) is the array created by <i>energy_transfer</i> for
 * the vs case
 * \param output_vs_err2 (INPUT) is the square of the uncertainty in the array
 * created by <i>energy_transfer</i> for the vs case
 * \param true_output_vs (INPUT) is the true array for the vs case
 * \param true_output_vs_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vs case
 * \param output_vv (INPUT) is the array created by <i>energy_transfer</i> for
 * the vv case
 * \param output_vv_err2 (INPUT) is the square of the uncertainty in the array
 * created by <i>energy_transfer</i> for the vv case
 * \param true_output_vv (INPUT) is the true array for the vv case
 * \param true_output_vv_err2 (INPUT) is the square of the uncertainty in the
 * true array for the vv case
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
 * Function that generates the data using the <i>energy_transfer</i> function
 * (as described in the documentation of the <i>energy_transfer</i> function)
 * and launches the comparison of the data.
 *
 * \param key (INPUT) is a key that permits to launch the correct test
 * \param debug (INPUT) is any string that launches the debug mode (print all
 * the array created and calculated)
 *
 * \return Result of the function (TRUE/FALSE)
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
 * Main function that test energy_transfer for float and double.
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

/**
 * \}
 */  // end of energy_transfer_test group
